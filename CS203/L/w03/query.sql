-- Database generating file:../w01/init.sql

use QLThuVien
go

-- /* ------------ Examples ------------ */

-- Viết stored procedure nhận vào một ngày, xuất ra danh sách các phiếu trả trong ngày đó (mã phiếu trả, số cmnd độc giả của phiếu trả đó).
drop procedure if exists sp_ThongKePhieuTraTheoNgay
go

create procedure sp_ThongKePhieuTraTheoNgay 
	@ngay datetime
as
begin
	if (@ngay is NULL) or (@ngay = '')
	begin
		RAISERROR('Ngay khong hop le', 15, 1)
		return
	end
	
	select *
	from PhieuTra
	where NgayTra = @ngay
end
go

execute sp_ThongKePhieuTraTheoNgay '2014-01-18'
go

-- Viết stored procedure nhận vào một số cmnd, xuất ra danh sách các phiếu mượn của người này (mã phiếu mượn, ngày mượn và tổng số sách mượn của phiếu mượn đó

drop procedure if exists sp_ThongKePhieuMuonTheoSoCMND
go

create procedure sp_ThongKePhieuMuonTheoSoCMND
	@soCMND varchar(10)
as
begin
	if (select socmnd from DocGia where socmnd = @soCMND) is NULL
	begin
		RAISERROR('So CMND khong ton tai', 15, 1)
		return
	end
	
	select pm.mapm, pm.ngaymuon, count(*) as 'Tong so sach muon'
	from PhieuMuon as pm,
		DocGia as dg,
		PhieuTra as pt
	where dg.madg = pm.madg
		and pt.mapm = pm.mapm
		and dg.socmnd = @soCMND
	group by pm.mapm, pm.ngaymuon
end
go

execute sp_ThongKePhieuMuonTheoSoCMND '2157836254'
go

-- /* ------------ Homework ------------ */

-- 1. Nhận vào mã phiếu mượn, trả ra số cmnd, họ tên, địa chỉ, ngày sinh của độc giả mượn phiếu đó.
drop procedure if exists sp_cau1
go

create procedure sp_cau1
	@maPhieuMuon varchar(10)
as
begin
	if (select mapm
		from PhieuMuon
		where mapm = @maPhieuMuon) is NULL
	begin
		RAISERROR('Ma phieu muon khong ton tai', 15, 1)
		return
	end
	
	select dg.socmnd, dg.hoten, dg.diachi, dg.ngsinh
	from PhieuMuon as pm,
		DocGia as dg
	where pm.madg = dg.madg
		and pm.mapm = @maPhieuMuon
end
go

execute sp_cau1 'PM001'
go
	

-- 2. Nhận vào một năm, xuất ra thông tin các độc giả sinh năm đó.
drop procedure if exists sp_cau2
go

create procedure sp_cau2
	@nam int
as
begin
	if (@nam is NULL) or (@nam < 1900)
	begin
		RAISERROR('Nam khong hop le', 15, 1)
		return
	end
	
	select *
	from DocGia
	where YEAR(ngsinh) = @nam
end
go

execute sp_cau2 1990
go


-- 3. Xuất ra thông tin độc giả trẻ tuổi nhất.
drop procedure if exists sp_cau3
go

create procedure sp_cau3
as
begin
	select top 1 *
	from DocGia
	order by DATEDIFF(year, ngsinh, GETDATE()) ASC
end
go

execute sp_cau3
go


-- 4. Nhận vào một mã phiếu mượn, trả ra số cmnd, họ tên độc giả mượn và tổng số cuốn sách được mượn trong lần đó.
drop procedure if exists sp_cau4
go

create procedure sp_cau4
	@maPhieuMuon varchar(10)
as
begin
	if (select mapm
		from PhieuMuon
		where mapm = @maPhieuMuon) is NULL
	begin
		RAISERROR('Ma phieu muon khong ton tai', 15, 1)
		return
	end
	
	select dg.socmnd, dg.hoten, count(*) as 'Tong so cuon sach duoc muon'
	from PhieuMuon as pm,
		DocGia as dg,
		CT_PhieuMuon as ctpm
	where pm.madg = dg.madg
		and pm.mapm = ctpm.mapm
		and pm.mapm = @maPhieuMuon
	group by dg.socmnd, dg.hoten
end
go

execute sp_cau4 'PM003'
go


-- 5. Nhận vào số isbn một đầu sách, xuất ra danh sách độc giả (số cmnd, họ tên, ngsinh, địa chỉ) của các độc giả từng mượn đầu sách đó.
drop procedure if exists sp_cau5
go

create procedure sp_cau5
	@soISBN varchar(10)
as
begin
	if (select isbn
		from DauSach
		where isbn = @soISBN) is NULL
	begin
		RAISERROR('So ISBN khong ton tai', 15, 1)
		return
	end
	
	select dg.socmnd, dg.hoten, dg.ngsinh, dg.diachi
	from PhieuMuon as pm,
		DocGia as dg,
		CT_PhieuMuon as ctpm
	where pm.madg = dg.madg
		and pm.mapm = ctpm.mapm
		and ctpm.isbn = @soISBN
end
go

execute sp_cau5 '116525441'
go


-- 6. Nhận vào số cmnd một độc giả, xuất ra thông tin các cuốn sách (mã isbn, mã sách) mà độc giả đã từng mượn.
drop procedure if exists sp_cau6
go

create procedure sp_cau6
	@soCMND varchar(10)
as
begin
	if (select socmnd
		from DocGia
		where socmnd = @soCMND) is NULL
	begin
		RAISERROR('So CMND khong ton tai', 15, 1)
		return
	end
	
	select ctpm.isbn, ctpm.masach
	from PhieuMuon as pm,
		DocGia as dg,
		CT_PhieuMuon as ctpm
	where pm.madg = dg.madg
		and pm.mapm = ctpm.mapm
		and dg.socmnd = @soCMND
end
go

execute sp_cau6 '2157836254'
go


-- 7. Nhận vào một mã phiếu mượn trả ra số lượng phiếu trả cho phiếu mượn đó.
drop procedure if exists sp_cau7
go

create procedure sp_cau7
	@maPhieuMuon varchar(10)
as
begin
	if (select mapm
		from PhieuMuon
		where mapm = @maPhieuMuon) is NULL
	begin
		RAISERROR('Ma phieu muon khong ton tai', 15, 1)
		return
	end
	
	select count(*) as 'So luong phieu tra'
	from PhieuTra as pt,
		PhieuMuon as pm
	where pt.mapm = pm.mapm
		and pm.mapm = @maPhieuMuon
end
go

execute sp_cau7 'PM001'
go


-- 8. Nhận vào một mã isbn, xóa đầu sách mang mã isbn đó theo các bước sau: 
-- -- Kiểm tra đầu sách có tồn tại không. Nếu không trả về mã lỗi là 1 
-- -- Kiểm tra đầu sách đó đã có cuốn sách nào chưa:
-- -- -- Nếu chưa có cuốn sách nào thuộc đầu sách, tiến hành xóa đầu sách và trả về 0 báo hiệu xóa thành công.
-- -- -- Nếu có, kiểm tra các cuốn sách thuộc đầu sách đã từng có độc giả mượn hay trả chưa:
-- -- -- -- Nếu chưa, xóa các cuốn sách thuộc đầu sách sau đó xóa đầu sách và trả về 0 báo hiệu xóa thành công.
-- -- -- -- Nếu có, không được xóa và trả về mã lỗi là 2.
drop procedure if exists sp_cau8
go

create procedure sp_cau8
	@soISBN varchar(10)
as
begin
	-- Dau sach khong ton tai
	if (select isbn
		from DauSach
		where isbn = @soISBN) is NULL
	begin
		RAISERROR('So ISBN khong ton tai', 15, 1)
		return
	end
	
	-- Dau sach ton tai va khong co cuon sach nao
	if (select count(*)
		from CuonSach
		where isbn = @soISBN) = 0
	begin
		delete from DauSach
		where isbn = @soISBN
		
		RAISERROR('Xoa thanh cong', 0, 0)
		return
	end
	
	-- Cac cuon sach thuoc dau sach chua co nguoi muon
	if (select count(*)
		from CuonSach as cs,
			CT_PhieuMuon as ctpm
		where cs.masach = ctpm.masach
			and cs.isbn = @soISBN) = 0
	begin
		delete from CuonSach
		where isbn = @soISBN
		
		delete from DauSach
		where isbn = @soISBN
		
		RAISERROR('Xoa thanh cong', 0, 0)
		return
	end
	
	-- Khong the xoa
	else
	begin
		RAISERROR('Khong the xoa', 15, 2)
		return
	end
end
go

execute sp_cau8 '116525441'
go


-- 9. Nhận vào mã phiếu trả, cập nhật ngày trả theo các bước sau: 
-- -- Kiểm tra mã phiếu trả có tồn tại không > nếu không trả về mã lỗi là 1 
-- -- Cập nhật ngày trả của phiếu trả
-- -- Cập nhật tiền phạt của các chi tiết phiếu trả tương ứng theo công thức: tiền phạt = mucgiaphat * (ngày trả mới – ngày mượn – số ngày quy định)
drop procedure if exists sp_cau9
go

create procedure sp_cau9
	@maPhieuTra varchar(10),
	@ngayTra datetime
as
begin
	-- Ma phieu tra khong ton tai
	if (select mapt
		from PhieuTra
		where mapt = @maPhieuTra) is NULL
	begin
		RAISERROR('Ma phieu tra khong ton tai', 15, 1)
		return
	end
	
	-- Cap nhat ngay tra
	update PhieuTra
	set ngaytra = @ngayTra
	where mapt = @maPhieuTra
	
	-- Cap nhat tien phat
	update CT_PhieuTra
	set tienphat = ctpt.mucgiaphat * (DATEDIFF(day, pm.ngaymuon, @ngayTra) - ctpm.songayquydinh)
	from PhieuTra as pt,
		CT_PhieuTra as ctpt,
		PhieuMuon as pm,
		CT_PhieuMuon as ctpm
	where pt.mapt = ctpt.mapt
		and pt.mapm = pm.mapm
		and pm.mapm = ctpm.mapm
		and ctpt.mapt = @maPhieuTra
end
go

execute sp_cau9 'PT001', '2019-12-12'
go

-- 10. Nhận vào thông tin một phiếu mượn  (mã phiếu mượn, mã độc giả), thêm phiếu mượn vào CSDL theo các bước sau:  
-- -- Kiểm tra mã phiếu mượn đã tồn tại chưa > nếu đã tồn tại trả về mã lỗi là 1 
-- -- Kiểm tra mã độc giả phải khác null và phải tồn tại trong bảng độc giả > nếu không trả về mã lỗi 2 
-- -- Thêm phiếu mượn vào CSDL, biết rằng ngày mượn luôn là ngày hiện tại của hệ thống.
-- -- Trả về 0 báo hiệu thêm thành công.
drop procedure if exists sp_cau10
go

create procedure sp_cau10
	@maPhieuMuon varchar(10),
	@maDocGia varchar(10)
as
begin
	-- Ma phieu muon da ton tai
	if (select mapm
		from PhieuMuon
		where mapm = @maPhieuMuon) is not NULL
	begin
		RAISERROR('Ma phieu muon da ton tai', 15, 1)
		return
	end
	
	-- Ma doc gia khong ton tai
	if @maDocGia is NULL
		or (select madg
			from DocGia
			where madg = @maDocGia) is NULL
	begin
		RAISERROR('Ma doc gia khong ton tai', 15, 2)
		return
	end
	
	-- Them phieu muon
	insert into PhieuMuon
	values (@maPhieuMuon, @maDocGia,GETDATE(), 0, 0)
	
	RAISERROR('Them thanh cong', 0, 0)
end
go

execute sp_cau10 'PM001', 'DG001'
go
