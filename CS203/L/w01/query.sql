use QLThuVien
go

-- 1. Số lượng độc giả có địa chỉ tại Thủ Đức.

select count(*) as SoDocGia
from DocGia
where diachi like N'%Thủ Đức%'

go

-- 2. Đếm số phiếu mượn trong ngày 25 tháng 12.

select count(*) as SoPhieuMuon
from PhieuMuon
where DAY(ngaymuon) = 25
	and MONTH(ngaymuon) = 12

go

-- 3. Đếm số lượng đầu sách xuất bản sau năm 2000 hiện có trong thư viện.

select count(*) as SoDauSachSau2000HienCo
from DauSach ds
where namxb > 2000
	and isbn not in (
		select isbn
		from CT_PhieuMuon ct
	)

go

-- 4. Số isbn, mã sách và số lượng độc giả đã từng mượn cuốn sách này.

select isbn, masach, count(*) as SoDocGiaDaMuon
from CT_PhieuMuon ct
group by isbn, masach

go

-- 5. Số cmnd, họ tên và số lượng đầu sách mà độc giả này đã từng mượn.

select dg.socmnd, dg.hoten, count(*) as SoDauSachDaMuon
from DocGia dg
join PhieuMuon pm
	on dg.madg = pm.madg
join CT_PhieuMuon ct
	on pm.mapm = ct.mapm
group by dg.socmnd, dg.hoten

go

-- 6. Mã phiếu trả, ngày trả và tổng tiền phạt của phiếu trả đó.
-- tienphat = mucgiaphat * (ngaytra – ngaymuon – songayquydinh)

select pt.mapt, pt.ngaytra, SUM(GREATEST(ctpt.mucgiaphat * (DATEDIFF(day, pm.ngaymuon, pt.ngaytra) - ctpm.songayquydinh), 0)) as TongTienPhat
from PhieuTra pt
join CT_PhieuMuon ctpm
	on pt.mapm = ctpm.mapm
join CT_PhieuTra ctpt
	on pt.mapt = ctpt.mapt
join PhieuMuon pm
	on pt.mapm = pm.mapm
group by pt.mapt, pt.ngaytra

go

-- 7. Số isbn, mã sách của cuốn sách có nhiều độc giả mượn nhất.

select isbn, masach
from CT_PhieuMuon ct
group by isbn, masach
having count(*) >= ALL (
		select count(*)
		from CT_PhieuMuon ct
		group by isbn, masach
	)

go

-- 8. Số cmnd, họ tên độc giả mượn ít đầu sách nhất.

select dg.socmnd, dg.hoten
from DocGia dg
join PhieuMuon pm
	on dg.madg = pm.madg
join CT_PhieuMuon ct
	on pm.mapm = ct.mapm
group by dg.socmnd, dg.hoten
having count(*) <= ALL (
		select count(*)
		from DocGia dg
		join PhieuMuon pm
			on dg.madg = pm.madg
		join CT_PhieuMuon ct
			on pm.mapm = ct.mapm
		group by dg.socmnd, dg.hoten
	)

go

-- 9. Ngày có ít phiếu trả nhất.

select ngaytra
from PhieuTra
group by ngaytra
having count(*) <= ALL (
		select count(*)
		from PhieuTra
		group by ngaytra
	)

go

-- 10. Phiếu trả có tổng tiền phạt lớn nhất.

select pt.mapt, SUM(GREATEST(ctpt.mucgiaphat * (DATEDIFF(day, pm.ngaymuon, pt.ngaytra) - ctpm.songayquydinh), 0)) as TongTienPhat as TongTienPhat
from PhieuTra pt
join CT_PhieuMuon ctpm
	on pt.mapm = ctpm.mapm
join CT_PhieuTra ctpt
	on pt.mapt = ctpt.mapt
join PhieuMuon pm
	on pt.mapm = pm.mapm
group by pt.mapt
having SUM(GREATEST(ctpt.mucgiaphat * (DATEDIFF(day, pm.ngaymuon, pt.ngaytra) - ctpm.songayquydinh), 0)) >= ALL (
		select SUM(GREATEST(ctpt.mucgiaphat * (DATEDIFF(day, pm.ngaymuon, pt.ngaytra) - ctpm.songayquydinh), 0))
		from PhieuTra pt
		join CT_PhieuMuon ctpm
			on pt.mapm = ctpm.mapm
		join CT_PhieuTra ctpt
			on pt.mapt = ctpt.mapt
		join PhieuMuon pm
			on pt.mapm = pm.mapm
		group by pt.mapt
	)

go

-- 11. Ngày có nhiều phiếu mượn nhất.

select ngaymuon
from PhieuMuon
group by ngaymuon
having count(*) >= ALL (
		select count(*)
		from PhieuMuon
		group by ngaymuon
	)

go

-- 12. Số cmnd, họ tên độc giả của phiếu mượn có nhiều sách được mượn nhất.

select dg.socmnd, dg.hoten
from DocGia dg
join PhieuMuon pm
	on dg.madg = pm.madg
join CT_PhieuMuon ct
	on pm.mapm = ct.mapm
group by dg.socmnd, dg.hoten
having count(*) >= ALL (
		select count(*)
		from CT_PhieuMuon
		group by mapm
		having count(*) >= ALL (
			select count(*)
			from CT_PhieuMuon
			group by mapm
		)
	)

go

-- 13. Số cmnd, họ tên độc giả của phiếu mượn có nhiều phiếu trả nhất.

select dg.socmnd, dg.hoten
from DocGia dg
join PhieuMuon pm
	on dg.madg = pm.madg
join PhieuTra pt
	on pm.mapm = pt.mapm
group by dg.socmnd, dg.hoten
having count(*) >= ALL (
		select count(*)
		from PhieuTra
		group by mapm
		having count(*) >= ALL (
			select count(*)
			from PhieuTra
			group by mapm
		)
	)

go
