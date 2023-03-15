use QLThuVien
go

-- 1. Ngày mượn sách phải là ngày hiện tại
--		T	X	S
-- PM	+	-	-
create
-- alter
trigger tg_cau1
on PhieuMuon
for insert
as
begin
	if exists
	(
		select count(*)
		from inserted i
		where i.NgayMuon <> convert(date, getdate())
	)
	begin
		raiserror('Ngay muon phai la ngay hien tai', 15, 1)
		rollback
	end
end
go

-- 2. Ngày trả sách phải là ngày hiện tại.
--		T	X	S
-- PT	+	-	-
create
-- alter
trigger tg_cau2
on PhieuTra
for insert
as
begin
	if exists
	(
		select count(*)
		from inserted i
		where i.NgayTra <> convert(date, getdate())
	)
	begin
		raiserror('Ngay tra phai la ngay hien tai', 15, 1)
		rollback
	end
end
go

-- 3. Tình trạng sách chỉ bao gồm : "đang được mượn" hoặc "có thể cho mượn"
--		T	X	S
-- CS	+	-	+(tinhtrang)
create
-- alter
trigger tg_cau3
on CuonSach
for insert, update
as
begin
	if exists
	(
		select count(*)
		from inserted i
		where i.TinhTrang <> N'đang được mượn'
			and i.TinhTrang <> N'có thể cho mượn'
	)
	begin
		raiserror(N'Tinh trang sach chi bao gom: "đang được mượn" hoac "có thể cho mượn"', 15, 1)
		rollback
	end
end
go

-- 4. Đọc giả muốn mượn sách phải từ 18 tuổi trở lên.
--		T	X	S
-- PM	+	-	+(madg)
-- DG	-	-	-
create
-- alter
trigger tg_cau4
on PhieuMuon
for insert, update
as
begin
	if exists
	(
		select count(*)
		from inserted i,
			DocGia d
		where	i.madg = d.madg
			and datediff(year, d.NgSinh, getdate()) < 18
	)
	begin
		raiserror('Doc gia muon sach phai du 18 tuoi', 15, 1)
		rollback
	end
end
go

insert into DocGia(madg, hoten, ngsinh) values ('DG10', 'DG Test', '2010-11-19')
insert into PhieuMuon values ('PM20', 'DG10', '2023-08-03', 0)
go

-- 5. Số lượng đầu sách hiện có >=0.
--		T	X	S
-- DS	+	-	+(soluong)
create
-- alter
trigger tg_cau5
on DauSach
for insert, update
as
begin
	if exists
	(
		select count(*)
		from inserted i
		where i.SoLuong < 0
	)
	begin
		raiserror('So luong dau sach phai >= 0', 15, 1)
		rollback
	end
end
go

insert into DauSach(isbn) values ('12345678900')
go

-- 6. Thêm thuộc tính "SoLanTra" vào bảng PhieuMuon. SoLantra = số phiếu trả của phiếu mượn tương ứng.
--		T	X	S
-- PM	+	-	+(solantra)
-- PT	+	+	+(mapm)
if not exists
(
	select *
	from sys.columns
	where name = 'SoLanTra'
		and object_id = object_id('dbo.PhieuMuon')
)
begin
	print 'add column SoLanTra'
	alter table PhieuMuon
	add SoLanTra int
		default 0
end
go

create
-- alter
trigger tg_cau6_1
on PhieuMuon
for insert, update
as
begin
	if exists
	(
		select count(*)
		from inserted i
		where i.SoLanTra <> (select count(*) from PhieuTra where mapm = i.mapm)
	)
	begin
		raiserror('So lan tra phai bang so phieu tra cua phieu muon tuong ung', 15, 1)
		rollback
	end
end
go

create
-- alter
trigger tg_cau6_2
on PhieuTra
for update
as
begin
	if exists
	(
		select count(*)
		from inserted i,
			PhieuMuon p
		where i.mapm = p.mapm
			and p.SoLanTra <> (select count(*) from PhieuTra where mapm = p.mapm)
	)
	begin
		raiserror('So lan tra phai bang so phieu tra cua phieu muon tuong ung', 15, 1)
		rollback
	end
end
go

-- ANSWER
create
function uf_w07_SoPT(@mapm varchar(5))
returns int
as
	begin
		return (
			select count(*)
			from PhieuTra
			where mapm = @mapm
		)
	end
end
go

create
trigger ut_w06_cau6_0
on PhieuMuon
for insert
as
begin
	if not exists
	(
		select *
		from inserted i
			join PhieuMuon pm
				on i.mapm = pm.mapm
		where dbo.uf_w07_SoPT(i.mapm) = pm.SoLanTra
	)
	
	begin
		update PhieuMuon
		set solantra = dbo.uf_w07_SoPT(mapm)
		from inserted i
		where i.mapm = PhieuMuon.mapm
	end
end
go

create
trigger ut_w06_cau6_1
on PhieuMuon
for update
as
begin
	if not exists
	(
		select *
		from inserted i
			join PhieuMuon pm
				on i.mapm = pm.mapm
		where dbo.uf_w07_SoPT(i.mapm) = pm.SoLanTra
	)
	
	begin
		update PhieuMuon
		set solantra = dbo.uf_w07_SoPT(mapm)
		from inserted i
		where i.mapm = PhieuMuon.mapm
	end
end
go

create
trigger ut_w06_cau6_2
on PhieuMuon
for delete
as
begin
	if not exists
	(
		select *
		from deleted i
			join PhieuMuon pm
				on i.mapm = pm.mapm
		where dbo.uf_w07_SoPT(i.mapm) = pm.SoLanTra
	)
	
	begin
		update PhieuMuon
		set solantra = dbo.uf_w07_SoPT(mapm)
		from deleted i
		where i.mapm = PhieuMuon.mapm
	end
end
go

-- 7. Thêm thuộc tính "NgayTraDuKien" vào bảng CT_PhieuTra. Ngày trả dự kiến = ngày mượn + số ngày quy định được mượn.
-- 		T	X	S
-- PM	-	-	+(ngaymuon)
-- CTPM	-	-	+(songayquydinh)
-- PT	-	-	+(mapm)
-- CTPT	+	-	+(ngaytradukien)

if not exists
(
	select *
	from sys.columns
	where name = 'NgayTraDuKien'
		and object_id = object_id(N'dbo.CT_PhieuTra')
)
begin
	print 'add column NgayTraDuKien'
	alter table CT_PhieuTra
	add NgayTraDuKien date
		default null
end
go

create
-- alter
trigger tg_cau7_1
on CT_PhieuTra
for insert, update
as
begin
	if exists
	(
		select count(*)
		from inserted i,
			PhieuMuon pm,
			CT_PhieuMuon ctpm,
			PhieuTra pt
		where i.mapt = pt.mapt
			and pt.mapm = pm.mapm
			and pm.mapm = ctpm.mapm
			and i.NgayTraDuKien <> dateadd(day, ctpm.SoNgayQuyDinh, pm.NgayMuon)
	)
	begin
		raiserror('Ngay tra du kien phai la ngay muon cong voi so ngay quy dinh', 15, 1)
		rollback
	end
end
go

create
-- alter
trigger tg_cau7_2
on PhieuTra
for update
as
begin
	if exists
	(
		select count(*)
		from inserted i,
			PhieuMuon pm,
			CT_PhieuMuon ctpm,
			CT_PhieuTra ctpt
		where i.mapm = pm.mapm
			and pm.mapm = ctpm.mapm
			and ctpt.NgayTraDuKien <> dateadd(day, ctpm.SoNgayQuyDinh, pm.NgayMuon)
	)
	begin
		raiserror('Ngay tra du kien phai la ngay muon cong voi so ngay quy dinh', 15, 1)
		rollback
	end
end
go

create
-- alter
trigger tg_cau7_3
on PhieuMuon
for update
as
begin
	if exists
	(
		select count(*)
		from inserted i,
			CT_PhieuMuon ctpm,
			PhieuTra pt,
			CT_PhieuTra ctpt
		where i.mapm = ctpm.mapm
			and i.mapm = pt.mapm
			and pt.mapt = ctpt.mapt
			and ctpt.NgayTraDuKien <> dateadd(day, ctpm.SoNgayQuyDinh, i.NgayMuon)
	)
	begin
		raiserror('Ngay tra du kien phai la ngay muon cong voi so ngay quy dinh', 15, 1)
		rollback
	end
end
go

create
-- alter
trigger tg_cau7_4
on CT_PhieuMuon
for update
as
begin
	if exists (
		select count(*)
		from inserted i,
			PhieuMuon pm,
			PhieuTra pt,
			CT_PhieuTra ctpt
		where i.mapm = pm.mapm
			and pt.mapt = ctpt.mapt
			and pt.mapm = pm.mapm
			and ctpt.NgayTraDuKien <> dateadd(day, i.SoNgayQuyDinh, pm.NgayMuon)
	)
	begin
		raiserror('Ngay tra du kien phai la ngay muon cong voi so ngay quy dinh', 15, 1)
		rollback
	end
end
go

-- ANSWER
-- De sai, xet bang CT_PhieuMuon
-- 		T	X	S
-- PM	-	-	+(ngaymuon)
-- CTPM	+	-	+(songayquydinh)

create function uf_w07_SoNgayQuyDinh (
	@mapm varchar(20)
)
returns table
as
	return (
		select SoNgayQuyDinh, ngaytradukien
		from CT_PhieuMuon
		where mapm = @mapm
	)
end
go

create ut_w07_cau7_1
on PhieuMuon
for update
as
	if update(ngaymuon)
	begin
		if exists (
			select *
			from inserted i,
				uf_w07_SoNgayQuyDinh() a
			where a.ngaytradukien = dateadd(day, a.songayquydinh, i.ngaymuon)
				and a.mapm = i.mapm
		)
		
		begin
			update CT_PhieuMuon
			set ngaytradukien = dateadd(day, songayquydinh, ngaymuon)
			from inserted i
			where i.mapm = CT_PhieuMuon.mapm
		end
	end
end
go

-- Same goes for other triggers

-- 8. Tinh trang cuon sach duoc tu dong cap nhat "dang duoc muon" khi thu thu thuc hien cho doc gia muon sach
create
-- alter
trigger ut_w07_cau8_1
on CT_PhieuMuon
for insert
as
	update CuonSach
	set tinhtrang = N'đang được mượn'
	from inserted i
	where i.isbn = CuonSach.isbn
		and i.masach = CuonSach.masach
end
go
