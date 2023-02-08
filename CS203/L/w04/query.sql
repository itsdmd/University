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

-- /* ------------ Homework ------------ */
-- Viết thủ tục thực hiện các yêu cầu sau:

-- 4. Thêm thuộc tính số cuốn mượn vào bảng PhieuMuon. Cập nhật giá trị “số cuốn mượn” theo 2 cách: dùng truy vấn và dùng cursor

-- -- Cách 1: dùng truy vấn

create
-- alter
proc sp_CapNhatSoCuonMuon_01
	@mapm varchar(5)
as

alter table PhieuMuon
add socuonmuon int

update PhieuMuon
set socuonmuon = (
	select count(*)
from CT_PhieuMuon c
where c.mapm = @mapm
)
where mapm = @mapm

go

exec sp_CapNhatSoCuonMuon_01 'PM001'
go

-- -- Cách 2: dùng cursor

create
-- alter
proc sp_CapNhatSoCuonMuon_02
	@mapm varchar(5)
as

alter table PhieuMuon
add socuonmuon int

declare cur cursor for (
	select *
from CT_PhieuMuon
where mapm = @mapm
)

open cur

declare
	@isbn varchar(10),
	@masach varchar(10),
	@socuonmuon int = 0

fetch next from cur into @isbn, @masach

while (@@fetch_status = 0)
begin
	set @socuonmuon = @socuonmuon + 1

	fetch next from cur into @isbn, @masach
end

update PhieuMuon
set socuonmuon = @socuonmuon
where mapm = @mapm

close cur
deallocate cur
go

exec sp_CapNhatSoCuonMuon_02 'PM001'
go


-- 5. In ra danh sách các đầu sách với định dạng như sau:
-- -- Mã đầu sách
-- -- Tên đầu sách
-- -- Tổng số cuốn hiện còn
-- -- Tổng số cuốn đang mượn

create
-- alter
proc sp_DanhSachDauSach
as

declare cur cursor for (
	select d.isbn, d.tensach,
	(select count(*)
	from CuonSach s
	where s.isbn = d.isbn
		and s.tinhtrang = N'Hiện có') as tongsocon,
	(select count(*)
	from CuonSach s
		join CT_PhieuMuon c on s.isbn = c.isbn and s.masach = c.masach
	where s.isbn = d.isbn
		and s.tinhtrang = N'Đang mượn') as tongsomuon
from DauSach d
)

open cur

declare
	@isbn varchar(10),
	@tensach nvarchar(30),
	@tongsocon int,
	@tongsomuon int

print N'DANH SÁCH ĐẦU SÁCH'

fetch next from cur into @isbn, @tensach, @tongsocon, @tongsomuon

while (@@fetch_status = 0)
begin
	print N'ISBN: ' + @isbn
	print N'Tên sách: ' + @tensach
	print N'Tổng số cuốn hiện còn: ' + cast(@tongsocon as nvarchar(10))
	print N'Tổng số cuốn đang mượn: ' + cast(@tongsomuon as nvarchar(10))
	print ''

	fetch next from cur into @isbn, @tensach, @tongsocon, @tongsomuon
end

close cur
deallocate cur
go

exec sp_DanhSachDauSach
go


-- 6. Xuất ra màn hình thống kê theo mẫu như sau:
-- -- Tháng: 09/2020
-- -- Số lượng đọc giả mượn sách
-- -- Đầu sách được mượn nhiều nhất
-- -- Tổng số tiền phạt do trả trễ

create
-- alter
proc sp_ThongKe
	@thang int,
	@nam int
as

declare
	@soluongdocgia int,
	@isbn varchar(10),
	@tongtienphat float

declare cur cursor for (
	select month(p.ngaymuon) as thang, year(p.ngaymuon) as nam,
	count(distinct p.madg) as soluongdocgia,
	(select top 1
		d.isbn
	from DauSach d
		join CuonSach s on d.isbn = s.isbn
		join CT_PhieuMuon c on s.isbn = c.isbn and s.masach = c.masach
	where month(p.ngaymuon) = @thang and year(p.ngaymuon) = @nam
	group by d.isbn
	order by count(*) desc) as isbn,
	sum(ct.tienphat) as tongtienphat
from PhieuMuon p
	join CT_PhieuMuon c on p.mapm = c.mapm
	join PhieuTra t on p.mapm = t.mapm
	join CT_PhieuTra ct on t.mapt = ct.mapt
where month(p.ngaymuon) = @thang and year(p.ngaymuon) = @nam
group by month(p.ngaymuon), year(p.ngaymuon)
)

open cur

fetch next from cur into @thang, @nam, @soluongdocgia, @isbn, @tongtienphat

while (@@fetch_status = 0)
begin
	print N'Tháng: ' + cast(@thang as nvarchar(10)) + N'/' + cast(@nam as nvarchar(10))
	print N'Số lượng đọc giả mượn sách: ' + cast(@soluongdocgia as nvarchar(10))
	print N'Đầu sách được mượn nhiều nhất: ' + @isbn
	print N'Tổng số tiền phạt do trả trễ: ' + cast(@tongtienphat as nvarchar(10))
	print ''

	fetch next from cur into @thang, @nam, @soluongdocgia, @isbn, @tongtienphat
end

close cur
deallocate cur
go

exec sp_ThongKe 9, 2020
go

-- 7. Xuất ra màn hình tình hình mượn trả sách của tháng này:
-- -- Mã phiếu mượn
-- -- Tình trạng: (chưa trả xong, đã trả xong)
-- -- Danh sách sách chưa trả

create
-- alter
proc sp_TinhHinhMuonTra
as

declare
	@mapm varchar(10),
	@tinhtrang nvarchar(30),
	@ngaymuon datetime,
	@ngaytra datetime

declare cur cursor for (
	select pm.mapm, pm.ngaymuon, pt.ngaytra,
	case
		when pt.ngaytra is null then N'Chưa trả xong'
		when pt.ngaytra > pm.ngaymuon then N'Đã trả xong'
		else N'Chưa trả xong'
	end as tinhtrang
from PhieuMuon pm
	join PhieuTra pt on pm.mapm = pt.mapm
)

open cur

fetch next from cur into @mapm, @ngaymuon, @ngaytra, @tinhtrang

while (@@fetch_status = 0)
begin
	print N'Mã phiếu mượn: ' + @mapm
	print N'Tình trạng: ' + @tinhtrang
	print N'Danh sách sách chưa trả:'

	declare cur2 cursor for (
		select s.isbn, s.masach, d.tensach, d.tacgia, d.namxb, d.theloai, d.nhaxb, d.tongluotmuon
	from CuonSach s
		join DauSach d on s.isbn = d.isbn
		join CT_PhieuMuon c on s.isbn = c.isbn and s.masach = c.masach
	where c.mapm = @mapm
	)

	open cur2

	declare
		@isbn varchar(10),
		@masach varchar(10),
		@tensach nvarchar(30),
		@tacgia nvarchar(30),
		@namxb int,
		@theloai nvarchar(30),
		@nhaxb nvarchar(30),
		@trangthai nvarchar(30)

	fetch next from cur2 into @isbn, @masach, @tensach, @tacgia, @namxb, @theloai, @nhaxb, @trangthai

	while (@@fetch_status = 0)
	begin
		print '---'
		print N'ISBN: ' + @isbn
		print N'Mã sách: ' + @masach
		print N'Tên sách: ' + @tensach
		print N'Tác giả: ' + @tacgia
		print N'Năm xuất bản: ' + cast(@namxb as nvarchar(10))
		print N'Thể loại: ' + @theloai
		print N'Nhà xuất bản: ' + @nhaxb
		print '---'
		print ''

		fetch next from cur2 into @isbn, @masach, @tensach, @tacgia, @namxb, @theloai, @nhaxb, @trangthai
	end

	close cur2
	deallocate cur2
	print ''

	fetch next from cur into @mapm, @ngaymuon, @ngaytra, @tinhtrang
end

close cur
deallocate cur
go

exec sp_TinhHinhMuonTra
go

