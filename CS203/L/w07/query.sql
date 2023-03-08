use QLThuVien
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

-- 6. SoLantra = số phiếu trả của phiếu mượn tương ứng.
--		T	X	S
-- PM	-	-	-
-- PT	+	+	+(mapm)
create
-- alter
trigger tg_cau6_i
on PhieuTra
for insert
as
begin
	update PhieuMuon
	set SoLanTra = SoLanTra +
	(
		select count(*)
		from PhieuTra
		where mapm = PhieuMuon.mapm
	)
	from inserted i
	where PhieuMuon.mapm = i.mapm
end
go

create
-- alter
trigger tg_cau6_u
on PhieuTra
for update
as
begin
	update PhieuMuon
	set SoLanTra =
	(
		select count(*)
		from PhieuTra
		where mapm = PhieuMuon.mapm
	)
end
go

create
-- alter
trigger tg_cau6_d
on PhieuTra
for delete
as
begin
	update PhieuMuon
	set SoLanTra = SolanTra -
	(
		select count(*)
		from PhieuTra
		where mapm = PhieuMuon.mapm
	)
	from deleted d
	where PhieuMuon.mapm = d.mapm
end
go
