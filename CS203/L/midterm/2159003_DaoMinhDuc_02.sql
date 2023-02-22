-- MSSV: 2159003
-- Họ tên: Đào Minh Đức

-- Use database generated from init.sql

use QLNhomNghienCuu
go

set dateformat 'dmy'
go

-- 1. Viết stored procedure thực hiện thêm mới 1 nhóm nghiên cứu, biết rằng:
-- - Trưởng nhóm nghiên cứu phải cùng khoa với nhóm nghiên cứu và phải đạt học vị Thạc sỹ trở lên.
-- - Trưởng nhóm được phân công không được đang kiêm nhiệm trưởng cho nhóm nào khác (chỉ làm trưởng 1 nhóm, không tính nhóm trong quá khứ)
-- - Gọi thực thi stored procedure

drop procedure if exists sp_ThemNhomNC
go

create procedure sp_ThemNhomNC
	@MaNhom nvarchar(10),
	@TenNhom nvarchar(50),
	@MaKhoa_NNC nvarchar(10),
	@MaGV nvarchar(10)
as
begin
	-- Truong nhom khong ton tai
	if (select magv
		from GiangVien
		where magv = @MaGV) is NULL
	begin
		RAISERROR('Truong nhom khong ton tai', 15, 1)
		return
	end
	
	-- Truong nhom khong cung khoa
	declare @MaKhoa_GV nvarchar(10)
	select @MaKhoa_GV = makhoa
	from GiangVien
	where magv = @MaGV
	
	if @MaKhoa_NNC <> @MaKhoa_GV
	begin
		RAISERROR('Truong nhom khong cung khoa', 15, 1)
		return
	end
	
	-- Truong nhom khong dat hoc vi thac si
	if (select HocVi
		from GiangVien
		where magv = @MaGV) = 'CN'
	begin
		RAISERROR('Truong nhom khong dat hoc vi thac si', 15, 1)
		return
	end
	
	-- Truong nhom da duoc phan cong
	if (select TruongNhom
		from NhomNC
		where TruongNhom = @MaGV) is not NULL
	begin
		RAISERROR('Truong nhom da duoc phan cong', 15, 1)
		return
	end
	
	-- Them nhom nghien cuu
	insert into NhomNC values (@MaNhom, @TenNhom, GETDATE(), @MaGV, @MaKhoa_NNC)
	
	-- Them thanh vien
	insert into ThanhVien_NNC values (@MaNhom, @MaGV, GETDATE(), NULL)
end
go

-- insert into GiangVien values (GV08, 'Nguyen Van A', '01111111', '1998-12-12', 'VS', 'ThS')
-- go

exec sp_ThemNhomNC 'NH10', N'Nhom nghien cuu Vi Sinh', 'VS', 'GV08'
go



-- 2. Viết thủ tục xuất thông tin nghiên cứu của các nhóm của 1 khoa cụ thể như mẫu sau:
-- Mã nhóm NC:
-- Ngày lập nhóm:
-- Số thành viên hiện tại:
-- Danh sách các đề tài nghiên cứu phụ trách:
-- Mã đề tài		Ngày bắt đầu		Tình trạng			Tên GV chủ nhiệm
-- DT01				1/1/2022			Đang thực hiện		Tuấn
-- DT02				13/2/2021			Đã nghiệm thu		Huy
-- ----------------------------------
-- Mã nhóm NC:
-- Ngày lập nhóm:
-- Số thành viên hiện tại:
-- etc.
-- Biết rằng: tình trạng đề tài có giá trị (đã nghiệm thu, đang thực hiện)

create
-- alter
procedure sp_XuatThongTinNghienCuu
	@MaKhoa nvarchar(10)
as
begin
	-- Khoa khong ton tai
	if (select makhoa
		from Khoa
		where makhoa = @MaKhoa) is NULL
	begin
		RAISERROR('Khoa khong ton tai', 15, 1)
		return
	end
	
	-- Xuat thong tin
	declare @MaNhom nvarchar(10)
	declare @TenNhom nvarchar(50)
	declare @NgayLap date
	declare @TruongNhom nvarchar(10)
	declare @SoThanhVien int
	declare @MaDT nvarchar(10)
	declare @NgayBD date
	declare @NgayNT date
	declare @TinhTrang nvarchar(20)
	declare @ChuNhiemDT nvarchar(10)
	declare @TenGV nvarchar(50)
	
	declare cur1 cursor for
	select MaNhom, TenNhom, NgayLapNhom, TruongNhom, MaKhoa
	from NhomNC
	where MaKhoa = @MaKhoa
	
	-- SoThanhVien: Dem trong ThanhVien_NNC, neu NgayRoiNhom = NULL thi +1
	set @SoThanhVien = (select count(*)
						from ThanhVien_NNC
						where MaNhom = @MaNhom
							and NgayRoiNhom is NULL)
	
	open cur1
	fetch next from cur1 into @MaNhom, @TenNhom, @NgayLap, @TruongNhom, @MaKhoa
	
	while @@FETCH_STATUS = 0
	begin
		print 'Ma nhom NC: ' + @MaNhom
		print 'Ngay lap nhom: ' + convert(varchar(10), @NgayLap)
		print 'So thanh vien hien tai: ' + convert(varchar(5), @SoThanhVien)
		
		print 'Danh sach cac de tai nghien cuu phu trach:'
		print 'Ma de tai		Ngay bat dau		Tinh trang			Ten GV chu nhiem'
		
		declare cur2 cursor for
		select MaDT, NgayBD, NgayNT, ChuNhiemDT
		from DeTaiNCC
		where MaNNC = @MaNhom
		
		open cur2
		fetch next from cur2 into @MaDT, @NgayBD, @NgayNT, @ChuNhiemDT
		
		while @@FETCH_STATUS = 0
		begin
			-- Ngay nghiem thu = null => dang thuc hien
			if (select NgayNT
				from DeTaiNCC
				where MaNNC = @MaNhom) is NULL
				set @TinhTrang = N'Đang thực hiện'
			else
				set @TinhTrang = N'Đã nghiệm thu'
				
			set @TenGV = (select HoTen
					  from GiangVien
					  where MaGV = @ChuNhiemDT)
			
			print @MaDT + '		' + convert(varchar(10), @NgayBD) + '		    ' + @TinhTrang + '		' + @TenGV
			fetch next from cur2 into @MaDT, @NgayBD, @TinhTrang, @TenGV
		end
		
		close cur2
		deallocate cur2
		
		print '----------------------------------'
		
		fetch next from cur1 into @MaNhom, @TenNhom, @NgayLap, @TruongNhom, @MaKhoa
	end
	
	close cur1
	deallocate cur1
end
go

-- insert into DeTaiNCC values ('2023.VS.01', 'NH10', 'Test', '2023-02-01', NULL, NULL, '40000000.0000', 'GV08', NULL)
-- go

exec sp_XuatThongTinNghienCuu 'VS'
go