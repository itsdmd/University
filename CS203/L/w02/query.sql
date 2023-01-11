use QLThuVien

-- 1. Nhận vào hai số a, b và trả về tổng a, b.
if object_id('sp_cau1') is not null
	drop procedure sp_cau1
go

create procedure sp_cau1
	@a int,
	@b int,
	@tong int output
as
begin
	set @tong = @a + @b
end
go

declare
	@a1 int = 1,
	@b1 int = 2,
	@kq1 int

execute sp_cau1 @a1, @b1, @kq1 output
print '' + convert(varchar(10), @a1) + ' + ' + convert(varchar(10), @b1) + ' = ' + convert(varchar(10), @kq1)
go


-- 2. Nhận vào hai số a, b và trả về hiệu a, b.
if object_id('sp_cau2') is not null
	drop procedure sp_cau2
go

create procedure sp_cau2
	@a int,
	@b int,
	@hieu int output
as
begin
	set @hieu = @a - @b
end
go

declare
	@a2 int = 1,
	@b2 int = 2,
	@kq2 int

execute sp_cau2 @a2, @b2, @kq2 output
print '' + convert(varchar(10), @a2) + ' - ' + convert(varchar(10), @b2) + ' = ' + convert(varchar(10), @kq2)
go


-- 3. Nhận vào hai số a, b và trả về tích a, b.
if object_id('sp_cau3') is not null
	drop procedure sp_cau3
go

create procedure sp_cau3
	@a int,
	@b int,
	@tich int output
as
begin
	set @tich = @a * @b
end
go

declare
	@a3 int = 1,
	@b3 int = 2,
	@kq3 int

execute sp_cau3 @a3, @b3, @kq3 output
print '' + convert(varchar(10), @a3) + ' * ' + convert(varchar(10), @b3) + ' = ' + convert(varchar(10), @kq3)
go


-- 4. Nhận vào hai số a, b và trả về thương a, b.
if object_id('sp_cau4') is not null
	drop procedure sp_cau4
go

create procedure sp_cau4
	@a int,
	@b int,
	@thuong int output
as
begin
	set @thuong = @a / @b
end

declare
	@a4 int = 7,
	@b4 int = 2,
	@kq4 int

execute sp_cau4 @a4, @b4, @kq4 output
print '' + convert(varchar(10), @a4) + ' / ' + convert(varchar(10), @b4) + ' = ' + convert(varchar(10), @kq4)
go


-- 5. Nhận vào hai số a, b và trả về số dư của phép chia a cho b.
if object_id('sp_cau5') is not null
	drop procedure sp_cau5
go

create procedure sp_cau5
	@a int,
	@b int,
	@soDu int output
as
begin
	set @soDu = @a % @b
end

declare
	@a5 int = 9,
	@b5 int = 5,
	@kq5 int

execute sp_cau5 @a5, @b5, @kq5 output
print 'So du cua phep chia ' + convert(varchar(10), @a5) + ' / ' + convert(varchar(10), @b5) + ' la: ' + convert(varchar(10), @kq5)
go


-- 6. Nhận vào hai số a, b và i.
---- Nếu i là 1 trả về tổng a, b
---- Nếu i là 2 trả về hiệu a, b
---- Nếu i là 3 trả về tích a, b
---- Nếu i là 4 trả về thương a, b
---- Nếu i là 5 trả về số dư phép chia a cho b
---- Yêu cầu: sử dụng lại stored procedure ở câu 1 đến câu 5 và dùng case để xét giá trị i.
if object_id('sp_cau6') is not null
	drop procedure sp_cau6
go

create procedure sp_cau6
	@a int,
	@b int,
	@i int = 0,
	@kq int output
as
begin
	declare
		@kq_c1 int = 0,
		@kq_c2 int = 0,
		@kq_c3 int = 0,
		@kq_c4 int = 0,
		@kq_c5 int = 0

	execute sp_cau1 @a, @b, @kq_c1 output
	execute sp_cau2 @a, @b, @kq_c2 output
	execute sp_cau3 @a, @b, @kq_c3 output
	execute sp_cau4 @a, @b, @kq_c4 output
	execute sp_cau5 @a, @b, @kq_c5 output

	select case @i
		when 1 then @kq_c1
		when 2 then @kq_c2
		when 3 then @kq_c3
		when 4 then @kq_c4
		when 5 then @kq_c5
		else 'i khong hop le'
	end
end

declare
	@a6 int = 7,
	@b6 int = 4,
	@i6 int = 1,
	@return6 int,
	@kq6 int

execute @return6 = sp_cau6 @a6, @b6, @i6, @kq6 output
print 'Ket qua: ' + convert(varchar(10), @kq6)
go


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
	if @n > @m
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


-- 11. Nhận vào ngày a (kiểu date hoặc datetime) cho biết tháng của ngày a có bao nhiêu ngày. Ví dụ: nếu ngày a là ngày 15/02/2000 thì trả về 28 là số ngày của tháng 2 trong năm 2000.
if object_id('sp_cau11') is not null
	drop procedure sp_cau11
go

create procedure sp_cau11
	@a date,
	@so_ngay int output
as
begin
	set @so_ngay = 0
	if datepart(mm, @a) in (1, 3, 5, 7, 8, 10, 12)
		set @so_ngay = 31
	else if datepart(mm, @a) in (4, 6, 9, 11)
		set @so_ngay = 30
	else if datepart(mm, @a) = 2
		begin
			if datepart(yy, @a) % 4 = 0 and datepart(yy, @a) % 100 <> 0 or datepart(yy, @a) % 400 = 0
				set @so_ngay = 29
			else
				set @so_ngay = 28
		end
end
go

declare
	@a11 date = '2020-02-15',
	@kq11 int

execute sp_cau11 @a11, @kq11 output
print 'Thang ' + convert(varchar(10), datepart(mm, @a11)) + ' cua nam ' + convert(varchar(10), datepart(yy, @a11)) + ' co ' + convert(varchar(10), @kq11) + ' ngay'
go


-- 12. Nhận vào n, kiểm tra xem n có phải số nguyên tố không. Nếu là số nguyên tố trả về 1 còn không trả về 0.
if object_id('sp_cau12') is not null
	drop procedure sp_cau12
go

create procedure sp_cau12
	@n int,
	@kq int output
as
begin
	set @kq = 1
	if @n < 2
		set @kq = 0
	else
		begin
			declare @i int = 2
			while @i <= @n / 2 and @kq = 1
			begin
				if @n % @i = 0
					set @kq = 0
			end
		end
end

declare
	@n12 int = 13,
	@kq12 int

execute sp_cau12 @n12, @kq12 output
if @kq12 = 1
	print '' + convert(varchar(10), @n12) + ' la so nguyen to'
else
	print '' + convert(varchar(10), @n12) + ' khong phai la so nguyen to'


-- 13. Nhận vào n, m và trả về tích các số nguyên tố nằm trong đoạn n, m (dùng tham số output). Lưu ý: số nguyên tố là số có hai ước chung là 1 và chính nó, ví dụ: 13, 17, ...
if object_id('sp_cau13') is not null
	drop procedure sp_cau13
go

create procedure sp_cau13
	@n int,
	@m int,
	@kq int output
as
begin
	set @kq = 1
	declare @i int = @n
	while @i <= @m
	begin
		declare @j int = 2
		while @j <= @i / 2
		begin
			if @i % @j = 0
				break
			set @j = @j + 1
		end
		if @j > @i / 2
			set @kq = @kq * @i
		set @i = @i + 1
	end
end

declare
	@n13 int = 2,
	@m13 int = 10,
	@kq13 int

execute sp_cau13 @n13, @m13, @kq13 output
print 'Tich cac so nguyen to trong doan ' + convert(varchar(10), @n13) + ' den ' + convert(varchar(10), @m13) + ' la: ' + convert(varchar(10), @kq13)
go


-- 14. Nhận vào n, kiểm tra xem n có phải số chính phương không. Nếu là số chính phương trả về 1 còn không trả về 0. Lưu ý: số chính phương là bình phương của một số khác, ví dụ: 4, 9, ...
if object_id('sp_cau14') is not null
	drop procedure sp_cau14
go

create procedure sp_cau14
	@n int,
	@kq int output
as
begin
	set @kq = 0
	declare @i int = 1
	while @i <= @n / 2
	begin
		if @i * @i = @n
			set @kq = 1
		set @i = @i + 1
	end
end

declare
	@n14 int = 9,
	@kq14 int

execute sp_cau14 @n14, @kq14 output
if @kq14 = 1
	print '' + convert(varchar(10), @n14) + ' la so chinh phuong'
else
	print '' + convert(varchar(10), @n14) + ' khong phai la so chinh phuong'
go


-- 15. Nhận vào n, m và trả về tổng các số chính phương nằm trong đoạn n, m (dùng tham số output).
if object_id('sp_cau15') is not null
	drop procedure sp_cau15
go

create procedure sp_cau15
	@n int,
	@m int,
	@kq int output
as
begin
	set @kq = 0
	declare @i int = @n
	while @i <= @m
	begin
		declare @j int = 1
		while @j <= @i / 2
		begin
			if @j * @j = @i
				set @kq = @kq + @i
			set @j = @j + 1
		end
		set @i = @i + 1
	end
end

declare
	@n15 int = 2,
	@m15 int = 10,
	@kq15 int

execute sp_cau15 @n15, @m15, @kq15 output
print 'Tong cac so chinh phuong trong doan ' + convert(varchar(10), @n15) + ' den ' + convert(varchar(10), @m15) + ' la: ' + convert(varchar(10), @kq15)
go
