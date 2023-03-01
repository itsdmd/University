use QLThuVien
go

-- 1. Viết hàm đếm số độc giả
create
-- alter
function UF_SoDocGia()
returns int
as
begin
	declare @SoDocGia int
	
	select @SoDocGia = count(*)
	from DocGia
	
	return @SoDocGia
end
go

select dbo.UF_SoDocGia()
go

-- 2. Viết hàm truyền vào isbn lấy mức giá phạt của đầu sách
create
-- alter
function UF_MucGiaPhatCuaDauSach(@ISBN varchar(10))
returns int
as
begin
	declare @MucGiaPhat int
	
	select @MucGiaPhat = MucGiaPhat
	from DauSach
	where ISBN = @ISBN
	
	return @MucGiaPhat
end
go

select dbo.UF_MucGiaPhatCuaDauSach('116525441')
go

-- 3. Viết hàm truyền vào MaPM, ISBN, MaSach lấy số ngày qui định
create
-- alter
function UF_SoNgayQuyDinh(
	@MaPM varchar(5),
	@ISBN varchar(10),
	@MaSach varchar(5))
returns int
as
begin
	declare @SoNgayQuyDinh int
	
	select @SoNgayQuyDinh = SoNgayQuyDinh
	from CT_PhieuMuon
	where MaPM = @MaPM
		and ISBN = @ISBN
		and MaSach = @MaSach
	
	return @SoNgayQuyDinh
end
go

select dbo.UF_SoNgayQuyDinh('PM001', '116525441', 'S001')
go

-- 4. Viết hàm truyền vào MaPM lấy ngày mượn
create
-- alter
function UF_NgayMuonTheoMaPM(@MaPM varchar(5))
returns date
as
begin
	declare @NgayMuon date
	
	select @NgayMuon = ngaymuon
	from PhieuMuon
	where MaPM = @MaPM
	
	return @NgayMuon
end
go

select dbo.UF_NgayMuonTheoMaPM('PM001')
go

-- 5. Viết hàm truyền vào MaPT lấy ngày trả
create
-- alter
function UF_NgayTraTheoMaPT(@MaPT varchar(5))
returns date
as
begin
	declare @NgayTra date
	
	select @NgayTra = ngaytra
	from PhieuTra
	where MaPT = @MaPT
	
	return @NgayTra
end
go

select dbo.UF_NgayTraTheoMaPT('PT001')
go

-- 6. Viết hàm truyền vào mà độc giả tính số phiếu mượn của độc giả
create
-- alter
function UF_SoPhieuMuonTheoMaDG(@MaDG varchar(4))
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
create
-- alter
function UF_SoSachMuonTrongNgay(@NgayCanTim date)
returns int
as
begin
	declare @SoSach int
	
	select @SoSach = count(*)
	from PhieuMuon
	where ngaymuon = @NgayCanTim
	
	return @SoSach
end
go

select dbo.UF_SoSachMuonTrongNgay('2020-05-20')
go

-- 10. Viết hàm truyền vào MaPM và MaPT tính số sách còn nợ của độc giả
create
-- alter
function UF_SoSachConNo(
	@MaPM varchar(5),
	@MaPT varchar(5))
returns int
as
begin
	declare @SoSach int
	
	select @SoSach = count(*)
	from CT_PhieuMuon
	where MaPM = @MaPM
		and MaSach not in (
			select MaSach
			from CT_PhieuTra
			where MaPT = @MaPT)
	
	return @SoSach
end
go

select dbo.UF_SoSachConNo('PM001', 'PT001')
go

-- 11. Viết hàm truyền vào MaPT, ISBN, MaSach tính tiền phạt
create
-- alter
function UF_TinhTienPhat(
	@MaPT varchar(5),
	@ISBN varchar(10),
	@MaSach varchar(5))
returns int
as
begin
	declare @TienPhat int
	
	select @TienPhat = datediff(day, dbo.UF_NgayMuonTheoMaPM(@MaPT), dbo.UF_NgayTraTheoMaPT(@MaPT)) * dbo.UF_MucGiaPhatCuaDauSach(@ISBN)
	from CT_PhieuTra
	where MaPT = @MaPT
		and ISBN = @ISBN
		and MaSach = @MaSach
	
	return @TienPhat
end
go

select dbo.UF_TinhTienPhat('PT001', '116525441', 'S001')
go

-- 12. Viết hàm truyền vào ISBN và chỉ thị:
-- -- Nếu chỉ thị là 1 thì trả ra danh sách sách có tình trạng =Đang được mượn
-- -- Nếu chỉ thị là 2 thì trả ra danh sách sách có tình trạng = Có thể mượn
create
-- alter
function UF_DanhSachSachTheoIsbnVaTinhTrang(
	@ISBN varchar(10),
	@ChiThi int)
returns table
as
return
(
	select MaSach
	from CuonSach
	where ISBN = @ISBN
		and TinhTrang = @ChiThi
)
go

select * from dbo.UF_DanhSachSachTheoIsbnVaTinhTrang('116525441', 1)
go

-- 13. Viết hàm truyền vào tình trạng cho biết danh sách cuốn sách trong tình trạng đó
create
-- alter
function UF_DanhSachSachTheoTinhTrang(@TinhTrang nchar(50))
returns table
as
return
(
	select distinct MaSach
	from CuonSach
	where TinhTrang like @TinhTrang
)
go

select * from dbo.UF_DanhSachSachTheoTinhTrang(N'có thể mượn')
go

-- 14. Viết hàm truyền vào thể loại xuất danh sách sách (ISBN, TenSach, TacGia, SoLuong, MucGiaPhat) thuộc thể loại đó
create
-- alter
function UF_DanhSachSachTheoTheLoai(@TheLoai nvarchar(15))
returns table
as
return
(
	select ds.ISBN,
		ds.TenSach,
		ds.TacGia,
		ds.SoLuong,
		ds.MucGiaPhat
	from DauSach ds
	where ds.TheLoai = @TheLoai
)
go

select * from dbo.UF_DanhSachSachTheoTheLoai(N'khoa học cơ bản')
go

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
create
-- alter
function UF_DanhSachSachTheoIsbnVaMaSach(
	@ISBN nvarchar(10),
	@MaSach nvarchar(5))
returns table
as
return
(
	select ds.ISBN,
		cs.MaSach,
		ds.SoLuong,
		(
			select count(*)
			from CT_PhieuMuon ctpm
			where ctpm.ISBN like ds.ISBN
				and ctpm.MaSach like cs.MaSach
				and ctpm.MaPM in
				(
					select MaPM
					from PhieuMuon
					where TinhTrang like N'có thể mượn'
				)
		) as SoSachDangDuocMuon
	from DauSach ds,
		CuonSach cs
	where ds.ISBN = cs.ISBN
		and ds.ISBN = @ISBN
		and cs.MaSach = @MaSach
)
go

select * from dbo.UF_DanhSachSachTheoIsbnVaMaSach('116525441', 'S001')
go

-- 19. Viết hàm truyền vào MaDG xuất danh sách phiếu mượn của độc gia (MaPM, NgayMuon, số sách mượn)
create
-- alter
function UF_DanhSachPhieuMuonTheoMaDG(@MaDG varchar(5))
returns table
as
return
(
	select pm.MaPM,
		pm.NgayMuon,
		SoSachMuon = count(*)
	from PhieuMuon pm,
		CT_PhieuMuon ctpm
	where pm.MaPM = ctpm.MaPM
		and pm.MaDG = @MaDG
	group by pm.MaPM, pm.NgayMuon
)
go

select * from dbo.UF_DanhSachPhieuMuonTheoMaDG('DG01')
go

-- 20. Viết hàm truyền vào Ngày mượn xuất danh sách sách mượn (MaPM, ISBN, MaSach, SoNgayQuyDinh) trong ngày đó
create
-- alter
function UF_DanhSachSachMuonTheoNgayMuon(@NgayMuon date)
returns table
as
return
(
	select pm.MaPM,
		ctpm.ISBN,
		ctpm.MaSach,
		ctpm.SoNgayQuyDinh
	from PhieuMuon pm,
		CT_PhieuMuon ctpm
	where pm.MaPM = ctpm.MaPM
		and pm.NgayMuon = @NgayMuon
)
go

select * from dbo.UF_DanhSachSachMuonTheoNgayMuon('2020-05-20')
go