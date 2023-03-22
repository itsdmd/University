-- Họ tên: Đào Minh Đức
-- MSSV: 2159003
-- Mã đề: 

use QLNhomNghienCuu
go

-- 1. Viết hàm truyền vào MaGV cho biết học vị của giảng viên này
-- Tên function: UF_D1_C1
-- Input: MaGV
-- Output: hoc vi cua giao vien

create
-- alter
-- drop
function UF_D1_C1(@MaGV char(5))
returns nvarchar(10)
as
begin
	declare @result nvarchar(10)
	
	select @result = hv.TenHV
	from NhomNC nnc,
		ThanhVien_NNC tv,
		GiangVien gv,
		DeTaiNCC dt,
		HocVi hv
	where tv.MaGV = gv.MaGV
		and tv.MaNhom = nnc.MaNhom
		and gv.MaGV = @MaGV
		and dt.MaNNC = nnc.MaNhom
		and dt.XepLoai is null
		and hv.MaHV = gv.HocVi
	return @result
end
go

-- test
select dbo.UF_D1_C1('GV03')
go

-- 2. Vẽ bảng tầm ảnh hưởng và chọn 1 trigger để cài cho RBTV sau:
-- “Giảng viên chủ nhiệm đề tài phải có học vị Tiến Sĩ”
-- Tên trigger: UTR_D1_2

-- 				T	X	S
-- DeTaiNCC		+	-	+(ChuNhiemDT)
-- GiangVien	-	-	+(HocVi)

-- Chon: DeTaiNCC - Sua - ChuNhiemDT
create
-- alter
-- drop
trigger UTR_D1_C2
on DeTaiNCC
for update
as
begin
	declare @MaGV nchar(5)
	declare @HocVi nvarchar(10)
	
	select @MaGV = ChuNhiemDT
	from inserted

	if @MaGV is not null
	begin
		select @HocVi = hv.TenHV
		from GiangVien gv,
			HocVi hv
		where gv.MaGV = @MaGV
			and gv.HocVi = hv.MaHV
		
		if @HocVi NOT LIKE N'Tiến sĩ'
		begin
			print 'Khong duoc cap nhat do hoc vi la ' + @HocVi
			rollback
		end
	end
end
go

-- test
update DeTaiNCC
set ChuNhiemDT = 'GV02'
where MaDT = '2022.CNTT.01'
go

-- 3. Cập nhật giảng viên chủ nhiệm là một thành viên là tiến sĩ trong nhóm nghiên cứu nếu vi
-- phạm điều kiện ở câu 2 (Lưu ý: nếu không có giáo viên nào thỏa thì xóa đề tài NC và sản
-- phẩm của đề tài đó)
-- Tên trigger: UTR_D1_C3

create
-- alter
-- drop
trigger UTR_D1_C3
on DeTaiNCC
for update
as
begin
	declare @MaGV nchar(5)
	declare @HocVi nvarchar(10)
			declare @MaNhom nchar(10)
	
	select @MaGV = ChuNhiemDT
	from inserted
	
	select @MaNhom = MaNNC
	from inserted

	if @MaGV is not null
	begin
		select @HocVi = hv.TenHV
		from GiangVien gv,
			HocVi hv
		where gv.MaGV = @MaGV
			and gv.HocVi = hv.MaHV
		
		if @HocVi NOT LIKE N'Tiến sĩ'
		begin
			print 'Khong duoc cap nhat do hoc vi la ' + @HocVi
			
			-- tim thanh vien trong nhom nghien cuu co hoc vi la tien si
			declare @MaGV2 nchar(5)
			select top 1 @MaGV2 = gv.MaGV
			from NhomNC nnc,
				ThanhVien_NNC tv,
				GiangVien gv,
				DeTaiNCC dt,
				HocVi hv
			where tv.MaGV = gv.MaGV
				and tv.MaNhom = @MaNhom
				and dt.MaNNC = @MaNhom
				and hv.MaHV = gv.HocVi
				and hv.TenHV LIKE N'Tiến sĩ'
			
			if @MaGV2 is not null
			begin
				print 'Cap nhat thanh vien ' + @MaGV2 + ' thanh chu nhiem'
				update DeTaiNCC
				set ChuNhiemDT = @MaGV2
				where MaDT = (select MaDT from inserted)
			end

			else
			begin
				declare @MaDT nchar(10) = (select MaDT from inserted)
				
				print 'Xoa de tai nghien cuu ' + @MaDT
				delete from DeTaiNCC
				where MaDT = (select MaDT from inserted)
				
				print 'Xoa san pham cua de tai nghien cuu ' + @MaDT
				delete from SanPhamDT
				where MaDT = @MaDT
			end
		end
	end
end
go

-- test
update DeTaiNCC
set ChuNhiemDT = 'GV01'
where MaDT = '2022.CNTT.01'
go

update DeTaiNCC
set ChuNhiemDT = 'GV01'
where MaDT = '2023.VS.01'
go
