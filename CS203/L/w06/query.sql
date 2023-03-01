use QLThuVien
go

-- 1. Viết hàm đếm số độc giả

-- 2. Viết hàm truyền vào isbn lấy mức giá phạt của đầu sách

-- 3. Viết hàm truyền vào MaPM, ISBN, MaSach lấy số ngày qui định

-- 4. Viết hàm truyền vào MaPM lấy ngày mượn

-- 5. Viết hàm truyền vào MaPT lấy ngày trả

-- 6. Viết hàm truyền vào mà độc giả tính số phiếu mượn của độc giả
create
-- alter
function UF_SoPhieuMuonTheoMaDG(@MaDG char(4))
returns int
as
begin
	declare @SoPhieuMuon int
	
	select @SoPhieuMuon = count(*)
	from PhieuMuon
	where madg = @MaDG
	
	return @SoPhieuMuon
end
go

select dbo.UF_SoPhieuMuonTheoMaDG('DG01')
go

-- 7. Viết hàm truyền vào MaDG và ngày mượn tính số sách độc giả mượn trong ngày đó
create
-- alter
function UF_SoSachDocGiaMuonTheoNgay(
	@MaDG char(4),
	@NgayMuon date)
returns int
as
begin
	declare @SoSach int
	
	select @SoSach = count(*)
	from PhieuMuon
	where madg = @MaDG
		and ngaymuon = @NgayMuon
	
	return @SoSach
end
go

select dbo.UF_SoSachDocGiaMuonTheoNgay('DG01', '2020-05-20')
go

-- 8. Viết hàm truyền vào ngày sinh tính tuổi của độc giả
create
-- alter
function UF_TinhTuoiDocGia(@NgaySinh date)
returns int
as
begin
	declare @Tuoi int
	
	select @Tuoi = datediff(year, @NgaySinh, getdate())
	
	return @Tuoi
end
go

select dbo.UF_TinhTuoiDocGia('1999-05-20')
go

-- 9. Viết hàm truyền vào ngày mượn tính số sách được mượn trong ngày đó

-- 10. Viết hàm truyền vào MaPM và MaPT tính số sách còn nợ của độc giả

-- 11. Viết hàm truyền vào MaPT, ISBN, MaSach tính tiền phạt

-- 12. Viết hàm truyền vào ISBN và chỉ thị:
-- -- Nếu chỉ thị là 1 thì trả ra danh sách sách có tình trạng =Đang được mượn
-- -- Nếu chỉ thị là 2 thì trả ra danh sách sách có tình trạng = Có thể mượn

-- 13. Viết hàm truyền vào tình trạng cho biết danh sách cuốn sách trong tình trạng đó

-- 14. Viết hàm truyền vào thể loại xuất danh sách sách (ISBN, TenSach, TacGia, SoLuong, MucGiaPhat) thuộc thể loại đó

-- 15. Viết hàm truyền vào tuổi, giới tính xuất danh sách sách mà độc giả có tuổi và giới tính này mượn
create
-- alter
function UF_DanhSachMuonTheoTuoiVaGioiTinh(
	@Tuoi int,
	@GioiTinh nvarchar(3))
returns table
as
return
(
	select ctpm.ISBN,
		ctpm.MaSach,
		ds.TenSach
	from PhieuMuon pm,
		CT_PhieuMuon ctpm,
		DauSach ds
	where pm.MaPM = ctpm.MaPM
		and ctpm.ISBN = ds.ISBN
		and pm.MaDG in
		(
			select dg.MaDG
			from DocGia dg
			where datediff(year, dg.ngsinh, getdate()) = @Tuoi
				and dg.GioiTinh = @GioiTinh
		)
)
go

select * from dbo.UF_DanhSachMuonTheoTuoiVaGioiTinh(34, N'Nam')
go

-- 16. Viết hàm truyền vào MAPM xuất danh sách mượn (MaPM, NGAYMUON, ISBN, MASACH, SONGAYQUYDINH)
create
-- alter
function UF_DanhSachMuonTheoMaPM(@MaPM varchar(5))
returns table
as
return
(
	select pm.MaPM,
		pm.NgayMuon,
		ctpm.ISBN,
		ctpm.MaSach,
		ctpm.SoNgayQuyDinh
	from PhieuMuon pm,
		CT_PhieuMuon ctpm
	where pm.MaPM = ctpm.MaPM
		and pm.MaPM = @MaPM
)
go

select * from dbo.UF_DanhSachMuonTheoMaPM('PM001')
go

-- 17. Viết hàm truyền vào MAPM xuất danh sách trả (MAPM, MAPT, NGAYTRA, ISBN, MASACH, MUCGIAPHAT, TIENPHAT)
create
-- alter
function UF_DanhSachTraTheoMaPM(@MaPM varchar(5))
returns table
as
return
(
	select pm.MaPM,
		pt.MaPT,
		pt.NgayTra,
		ctpm.ISBN,
		ctpm.MaSach,
		ds.MucGiaPhat,
		TienPhat = datediff(day, ctpm.SoNgayQuyDinh, pt.NgayTra) * ds.MucGiaPhat
	from PhieuMuon pm,
		PhieuTra pt,
		CT_PhieuMuon ctpm,
		DauSach ds
	where pm.MaPM = pt.MaPM
		and pm.MaPM = ctpm.MaPM
		and ctpm.ISBN = ds.ISBN
		and pm.MaPM = @MaPM
)
go

select * from dbo.UF_DanhSachTraTheoMaPM('PM001')
go

-- 18. Viết hàm truyền vào ISBN và MaSach cho biết danh sách sách (ISBN, MASACH, Số sách có, số sách đang được mượn)

-- 19. Viết hàm truyền vào MaDG xuất danh sách phiếu mượn của độc gia (MaPM, NgayMuon, số sách mượn)

-- 20. Viết hàm truyền vào Ngày mượn xuất danh sách sách mượn (MaPM, ISBN, MaSach, SoNgayQuyDinh) trong ngày đó