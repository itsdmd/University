use QLThuVien
go

-- /* ------------ Examples ------------ */
-- Viết thủ tục truyền vào madg và
-- Xuất ra thông tin đọc giả (MADG, HOTEN), 
-- Số lượng phiếu mượn
-- Danh sách phiếu mượn của đọc giả => CUR

create
-- alter
proc sp_001
	@madg varchar(10)
as

-- Xuất thông tin đọc giả
declare
	@hoten nvarchar(30),
	@sl int

select @hoten = hoten
from docgia
where madg = @madg

print N'Mã đg:' + @madg
print N'Họ tên đg:' + @hoten

-- Tính sl độc giả
select @sl = count(*)
from phieumuon
where madg = @madg
print N'số lượng phiếu mượn:' +  cast(@sl as varchar(4))

-- Xuất ds phiếu mươn của đọc giả truyền vào

-- -- Khai báo cursor
declare cur cursor for (
	select mapm, ngaymuon, solantra
from phieumuon
where madg = @madg
)

-- -- Mở cursor
open cur

-- -- Nạp dữ liệu lần 1 vào cur
declare @mapm varchar(5), @ngaymuon date, @ttrang nvarchar(20), @solantra int

fetch next from cur into @mapm, @ngaymuon,@ttrang, @solantra
print N' danh sách phiếu mượn'
print N'mã pm' + space(4) + N'ngay mượn' +space(4) + N'tinhtrang' +
	space(4) + 'so lan tra'

-- -- Duyệt cur
while (@@fetch_status = 0)
	begin

	-- -- Xử lí theo đề
	print
		@mapm + space (4) + cast(ISNULL(@ngaymuon,'-') as varchar(20)) 
		+ space(4) + ISNULL(@ttrang, '-')
		+ space(20 - len(@ttrang)) + cast(ISNULL(@sosachmuon,0) as varchar(5))

	fetch next from cur into @mapm, @ngaymuon, @ttrang, @solantra
end

-- -- Đóng cur
close cur
-- -- Hủy vùng nhớ
deallocate cur
go

exec sp_001 'dg04'
go

-- /* ------------ Classwork ----------- */

-- 1.
-- Input: MaPM
-- Mã PM:
-- Ngày mượn:
-- Tên đọc giả:

-- DANH SÁCH SÁCH MƯỢN
-- -----------------------
-- ISBN   MaSach   TenSach

create
-- alter
proc sp_DanhSachSachMuon
	@mapm varchar(5)
as

declare
	@ngaymuon date,
	@madg varchar(10),
	@hoten nvarchar(30)

select @ngaymuon = ngaymuon, @hoten = hoten
from phieumuon p join docgia d on p.madg = d.madg
where mapm = @mapm

print N'Mã PM: ' + @mapm
print N'Ngày mượn: ' + cast(@ngaymuon as varchar(20))
print N'Tên đọc giả: ' + @hoten

declare cur cursor for (
	select s.isbn, s.masach, d.tensach

from DauSach d
	join CuonSach s on d.isbn = s.isbn

where s.isbn in (
	select isbn
from CT_PhieuMuon
where mapm = @mapm
	and masach = s.masach
)
)

open cur

declare
	@isbn varchar(10),
	@masach varchar(10),
	@tensach nvarchar(30)

fetch next from cur into @isbn, @masach, @tensach

print N'DANH SÁCH SÁCH MƯỢN'
print N'ISBN' + space(10) + N'MaSach' + space(3) + N'TenSach'

while (@@fetch_status = 0)
begin
	print @isbn + space(4) + @masach + space(4) + @tensach
	fetch next from cur into @isbn, @masach, @tensach
end

close cur
deallocate cur
go

exec sp_DanhSachSachMuon 'PM001'
go




-- 2.
--  Input: MaPT
-- DANH SÁCH SÁCH TRẢ
-- --------------------------------------
-- ISBN   MaSach   TenSach   Số ngày mượn

create
-- alter
proc sp_DanhSachSachTra
	@mapt varchar(5)
as

declare cur cursor for (
	select s.isbn, s.masach, d.tensach,
	datediff(day, p.ngaymuon, pt.ngaytra) as songaymuon

from DauSach d
	join CuonSach s on d.isbn = s.isbn
	join CT_PhieuMuon c on s.isbn = c.isbn and s.masach = c.masach
	join PhieuMuon p on c.mapm = p.mapm
	join PhieuTra pt on p.mapm = pt.mapm

where pt.mapt = @mapt
)

open cur

declare
	@isbn varchar(10),
	@masach varchar(10),
	@tensach nvarchar(30),
	@songaymuon int

fetch next from cur into @isbn, @masach, @tensach, @songaymuon

print N'DANH SÁCH SÁCH TRẢ'
print N'ISBN' + space(10)
	+ N'MaSach' + space(3)
	+ N'TenSach' + space(13)
	+ N'Số ngày mượn'

while (@@fetch_status = 0)
begin
	print @isbn + space(4)
		+ @masach + space(4)
		+ @tensach + space(20 - len(@tensach))
		+ cast(@songaymuon as varchar(5))

	fetch next from cur into @isbn, @masach, @tensach, @songaymuon
end

close cur
deallocate cur
go

exec sp_DanhSachSachTra 'PT002'
go


-- 3.
-- Input: MaPM
-- DANH SÁCH SÁCH ĐANG MƯỢN
-- ---------------------------------------------
-- ISBN   MaSach   TenSach   Tình trạng (trễ, -)

create
-- alter
proc sp_DanhSachSachDangMuon
	@mapm varchar(5)
as

declare @songayquydinh int

select @songayquydinh = songayquydinh
from CT_PhieuMuon c
	join CuonSach s on c.isbn = s.isbn and c.masach = s.masach
	join DauSach d on s.isbn = d.isbn
where mapm = @mapm

print N'Số ngày quy định: ' + cast(@songayquydinh as varchar(5))

declare cur cursor for (
	select s.isbn, s.masach, d.tensach,
	case when datediff(day, pm.ngaymuon, pt.ngaytra) > @songayquydinh
		then N'Trễ'
		else N'-'
	end as tinhtrang

from DauSach d
	join CuonSach s on d.isbn = s.isbn
	join CT_PhieuMuon c on s.isbn = c.isbn and s.masach = c.masach
	join PhieuMuon pm on c.mapm = pm.mapm
	join PhieuTra pt on pm.mapm = pt.mapm

where pm.mapm = @mapm
)

open cur

declare
	@isbn varchar(10),
	@masach varchar(10),
	@tensach nvarchar(30),
	@tinhtrang nvarchar(10)

fetch next from cur into @isbn, @masach, @tensach, @tinhtrang

print N'DANH SÁCH SÁCH ĐANG MƯỢN'
print N'ISBN' + space(10)
	+ N'MaSach' + space(3)
	+ N'TenSach' + space(13)
	+ N'Tình trạng'

while (@@fetch_status = 0)
begin
	print @isbn + space(4)
		+ @masach + space(4)
		+ @tensach + space(20 - len(@tensach))
		+ @tinhtrang

	fetch next from cur into @isbn, @masach, @tensach, @tinhtrang
end

close cur
deallocate cur
go

exec sp_DanhSachSachDangMuon 'PM003'
go

