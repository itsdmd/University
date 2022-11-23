-- Họ tên: Đào Minh Đức
-- MSSV: 2159003
-- Mã đề: 2

use QLNhomNghienCuu
go

-- 1. Viết truy vấn cho biết (mã nhóm, tên nhóm, số thành viên) của nhóm nghiên cứu nào có số thành viên (đang hoạt động) nhiều nhất.
select NNC.MaNhom, NNC.TenNhom, count(TV.MaGV) as SoThanhVien
from NhomNC as NNC,
	ThanhVien_NNC as TV
where NNC.MaNhom = TV.MaNhom
	and TV.NgayRoiNhom is null
group by NNC.MaNhom, NNC.TenNhom
having count(TV.MaGV) >= ALL (select count(TV.MaGV)
								from NhomNC as NNC,
									ThanhVien_NNC as TV
								where NNC.MaNhom = TV.MaNhom
									and TV.NgayRoiNhom is null
								group by NNC.MaNhom, NNC.TenNhom)
go

-- 2. Viết truy vấn cho biết nhóm nghiên cứu nào có tất cả thành viên tham gia đều là tiến sĩ.
select *
from NhomNC as NNC
where not exists (select *
					from ThanhVien_NNC as TV
					where NNC.MaNhom = TV.MaNhom
						and TV.MaGV not in (select MaGV
											from GiangVien as GV,
												HocVi as HV
											where GV.HocVi = HV.MaHV
												and HV.TenHV = N'Tiến sĩ'))
go



-- 3. Viết stored procedure thực hiện cập nhật học vị cho 1 giảng viên
-- • Input: mã giảng viên, mã học vị
-- • Gọi thực thi stored procedure
-- drop procedure CapNhatHocVi
create procedure CapNhatHocVi
	@MaGV varchar(5),
	@MaHV varchar(3)
as
begin
	update GiangVien
	set HocVi = @MaHV
	where MaGV = @MaGV
end
go

execute CapNhatHocVi 'GV01', 'TS'
go
