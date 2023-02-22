-- MSSV: 2159003
-- Họ tên: Đào Minh Đức

-- Use database generated from init.sql

use QLNhomNghienCuu
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
end
go

-- insert into GiangVien values (GV08, 'Nguyen Van A', '01111111', '1998-12-12', 'VS', 'ThS')
-- go

exec sp_ThemNhomNC 'NH10', N'Nhom nghien cuu Vi Sinh', 'VS', 'GV08'
go