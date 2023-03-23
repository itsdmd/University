-- Hệ thống quản lí sinh viên gồm:
-- SinhVien (MaSV, HoTen, NamSinh, GioiTinh, DiemTB, MaLop)
-- GiaoVien (MaGV, HoTen, NgaySinh, LoaiGV)
-- MonHoc (MaMH, TenMH, SoChi)
-- KetQua (MaSV, MaMH, LanThi, Diem)
-- Lop (MaLop, NamBD, NamKT, SiSo)
-- GV_Lop (MaLop, MaMH, MaGV)

-- 1. Tạo login cho GV01, GV02, GV03, SV01, SV02, SV03.
sp_addlogin 'gv01','123'
sp_addlogin 'gv02','123'
sp_addlogin 'gv03','123'
sp_addlogin 'sv01','123'
sp_addlogin 'sv02','123'
sp_addlogin 'sv03','123'


-- 2. Sinh viên chỉ được được cấp quyền xem, cập nhật thông tin
-- cá nhân của mình (tạo view).
create view v_XemThongTinCaNhanSV
as
select *
from SINHVIEN
where MaSV = CURRENT_USER
go

grant select,update on v_XemThongTinCaNhanSV
	to sv01, sv02, sv03
go

-- 3. Tạo 2 nhóm vai trò GiaoVien, QuanLi.
sp_addrole 'giaovien', 'quanli'
go


-- 4. GV01 thuộc nhóm quản lí, GV02, GV03 thuộc nhóm giáo
-- viên.
sp_addrolemember 'quanli', 'gv01'
sp_addrolemember 'giaovien', 'gv02', 'gv03'
go


-- 5. Giáo viên được xem thông tin tất cả môn học.
create view v_XemThongTinMonHocGV
as
select *
from MONHOC
go

grant select on v_XemThongTinMonHoc
	to giaovien
go

-- 6. Giáo viên được thêm một kết quả và cập nhật điểm của
-- môn học do mình phụ trách.
create view v_ThemKetQuaGV
as
select *
from ketqua kq,
	lop l,
	gv_lop gvl
where kq.MaMH = gvl.MaMH
	and l.MaLop = gvl.MaLop
	and gvl.MaGV = CURRENT_USER
go

grant insert, update on v_ThemKetQua
	to giaovien

-- 7. Quản lí được xem, cập nhật, thêm thông tin môn học, sinh
-- viên và được phép cấp các quyền cho user khác.
grant select, update, insert
	on monhoc, sinhvien
	to quanli
with grant option
go


-- 8. Tất cả các sinh viên đều được phép xem thông tin các môn
-- học hiện có ở trường.
create view v_XemThongTinMonHocSV
as
select *
from MONHOC
go


-- 9. Giáo viên GV03 không còn giản dạy ở trường. Hãy hủy
-- các quyền đã cấp cho GV03.
revoke all
	from gv03
go


-- 10. Cấm quyền truy cập thông tin của SV03.
revoke select
	from sv03
go


-- 11. Thêm GV01 vào nhóm sysadmin.
sp_addrolemember 'sysadmin', 'gv01'
go


-- 12. Có thể cập nhật lại mật khẩu của login GV03 thành
-- '111111' được không? Ai được phép thực hiện?

-- Trả lời:
-- Có thể cập nhật lại mật khẩu của login GV03 thành '111111'.
-- GV03 và sysadmin được phép thực hiện.

-- 13. Cấp toàn quyền thao tác trên CSDL cho GV01.
grant all
	on *
	to gv01
go


-- 14. Cấp quyền thực thi các thủ tục usp_TinhDiem cho GV02.
grant execute
	on usp_TinhDiem
	to gv02
go
