use QLThuVien

-- 7. Nhận vào n, m và trả về tổng các giá trị nằm trong đoạn n, m (dùng tham số output).
if object_id('sp_cau7') is not null
	drop procedure sp_cau7
go

create procedure sp_cau7
	@n int,
	@m int,
	@tong int output
as
begin
	set @tong = 0
	if @n >= @m
		begin
			return 1
		end
	else
	begin
		while @n <= @m
		begin
			set @tong = @tong + @n
			set @n = @n + 1
		end
		return 0
	end
end
go

declare
	@n7 int = 1,
	@m7 int = 10,
	@kq7 int,
	@return7 int

execute @return7 = sp_cau7 @n7, @m7, @kq7 output
if @return7 = 1
	print 'Loi: n phai nho hon m'
else
	print 'Tong cac gia tri trong doan tu ' + convert(varchar(10), @n7) + ' den ' + convert(varchar(10), @m7) + ' la: ' + convert(varchar(10), @kq7)
go


-- 8. Nhận vào năm n, kiểm tra xem n có phải năm nhuận không. Nếu n là năm nhuận trả về 1 còn không phải trả về 0 (dùng tham số output).
if object_id('sp_cau8') is not null
	drop procedure sp_cau8
go

create procedure sp_cau8
	@n int,
	@kq int output
as
begin
	if (@n % 4 = 0 and @n % 100 <> 0) or (@n % 400 = 0)
		set @kq = 1
	else
		set @kq = 0
end
go

declare
	@n8 int = 2023,
	@kq8 int

execute sp_cau8 @n8, @kq8 output
if @kq8 = 1
	print 'Nam ' + convert(varchar(10), @n8) + ' la nam nhuan'
else
	print 'Nam ' + convert(varchar(10), @n8) + ' khong phai nam nhuan'


-- 9. Nhận vào năm n, m, đếm xem có bao nhiêu năm nhuận trong đoạn n đến m  (dùng tham số output).
if object_id('sp_cau9') is not null
	drop procedure sp_cau9
go

create procedure sp_cau9
	@n int,
	@m int,
	@so_nam_nhuan int output
as
begin
	set @so_nam_nhuan = 0
	
	if @n >= @m
		begin
			return 1
		end
	else
	
	begin
		while @n <= @m
		begin
			if (@n % 4 = 0 and @n % 100 <> 0) or (@n % 400 = 0)
				set @so_nam_nhuan = @so_nam_nhuan + 1
			set @n = @n + 1
		end
		return 0
	end
end
go

declare
	@n9 int = 2000,
	@m9 int = 2020,
	@kq9 int,
	@return9 int

execute @return9 = sp_cau9 @n9, @m9, @kq9 output
if @return9 = 1
	print 'Loi: n phai nho hon m'
else
	print 'So nam nhuan trong doan tu ' + convert(varchar(10), @n9) + ' den ' + convert(varchar(10), @m9) + ' la: ' + convert(varchar(10), @kq9)
go

-- 10. Nhận vào n và trả ra giá trị n!, biết rằng n! = 1*2*3*...*n
if object_id('sp_cau10') is not null
	drop procedure sp_cau10
go

create procedure sp_cau10
	@n int,
	@kq int output
as
begin
	set @kq = 1
	while @n > 0
	begin
		set @kq = @kq * @n
		set @n = @n - 1
	end
end
go

declare
	@n10 int = 5,
	@kq10 int

execute sp_cau10 @n10, @kq10 output
print 'Gia tri cua ' + convert(varchar(10), @n10) + '! la: ' + convert(varchar(10), @kq10)
go
