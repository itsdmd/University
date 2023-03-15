use QLThuVien
go

-- 1. (3đ) Viết hàm với thông tin sau: 3đ
-- -- Tên function: UF_D1_C1
-- -- Input: MaPM
-- -- Output: số sách đang mượn
-- -- Nội dung: đếm số sách đang mượn của phiếu mượn truyền vào
create
-- alter
function UF_D1_C1(@MaPM varchar(5))
returns int
as
begin
	declare @SoSachDangMuon int
	
	select @SoSachDangMuon = count(*)
	from CT_PhieuMuon
	where MaPM like @MaPM
	
	return @SoSachDangMuon
end
go

-- Test
select dbo.UF_D1_C1('PM001')
go

-- 2. Thêm cột SoSachMuon và TinhTrang vào bảng PhieuMuon. Kiểm tra các RBTV sau:

-- --  RB1: (3đ) ‘SoSachMuon = số sách đang nợ’
-- -- -- Tên trigger: UTR_D1_C2
-- -- -- Yêu cầu: Vẽ bảng tầm ảnh hưởng và in thông báo + hủy thao tác khi có vi phạm

-- 		T	X	S
-- PM	+	-	+(SoSachMuon)
-- CTPM	+	-	+(MaPM, MaSach)

create
-- delete
-- alter
function
dbo.UF_D1_C2(@MaPM varchar(5))
returns int
as
begin
	declare @SoSachDangMuon int
	
	select @SoSachDangMuon = count(*)
	from CT_PhieuMuon
	where MaPM like @MaPM
	
	return @SoSachDangMuon
end
go

create
-- delete
-- alter
trigger UTR_D1_C2
on PhieuMuon
for insert
as
begin
	declare @MaPM varchar(5)
	declare @SoSachMuon int
	
	select @MaPM = MaPM
	from inserted i
	
	select @SoSachMuon = dbo.UF_D1_C2(@MaPM)
	
	if not exists (
		select *
		from PhieuMuon
		where MaPM like @MaPM
		and SoSachMuon = @SoSachMuon
	)
	begin
		rollback
		print 'SoSachMuon phai bang so sach dang no'
	end
end
go

-- --  RB2: (4đ) Viết trigger tự động cập nhật tình trạng của PhieuMuon
-- -- -- Tên trigger: UTR_D1_C3
-- -- -- Yêu cầu: Khi thêm CT_PhieuTra (trả sách)
create
-- delete
-- alter
trigger UTR_D1_C3
on CT_PhieuTra
for insert
as
begin
	declare @MaPM varchar(5)
	declare @SoSachMuon int
	
	select @MaPM = (
		select MaPM
		from PhieuTra
		where MaPT = (
			select MaPT
			from inserted i
		)
	)
	from inserted i
	
	select @SoSachMuon = dbo.UF_D1_C2(@MaPM)
	
	if (@SoSachMuon = 0)
	begin
		update PhieuMuon
		set TinhTrang = N'Đã trả hết'
		where MaPM like @MaPM
	end
	
	else
	begin
		update PhieuMuon
		set TinhTrang = N'Chưa trả hết'
		where MaPM like @MaPM
	end
end
go
