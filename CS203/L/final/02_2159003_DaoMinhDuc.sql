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
	
	select @result = gv.HocVi
	from NhomNC nnc,
		ThanhVien_NNC tv,
		GiangVien gv,
		DeTaiNCC dt
	where tv.MaGV = gv.MaGV
		and tv.MaNhom = nnc.MaNhom
		and gv.MaGV = @MaGV
		and dt.MaNNC = nnc.MaNhom
		and dt.XepLoai is null
	return @result
end
go

-- test
select dbo.UF_D1_C1('GV03')
go

-- 2. Vẽ bảng tầm ảnh hưởng và chọn 1 trigger để cài cho RBTV sau:
-- “Giảng viên chủ nhiệm đề tài phải có học vị Tiến Sĩ”
-- Tên trigger: UTR_D1_2

-- 			T	X	S
-- DeTaiNCC




-- 3. Cập nhật giảng viên chủ nhiệm là một thành viên là tiến sĩ trong nhóm nghiên cứu nếu vi
-- phạm điều kiện ở câu 2 (Lưu ý: nếu không có giáo viên nào thỏa thì xóa đề tài NC và sản
-- phẩm của đề tài đó)
-- Tên trigger: UTR_D1_C3
