use QLGV
go

-- Xem danh sách các giảng viên (MaGV, số đề tài tham gia, số đề tài chủ nhiệm) của mỗi giảng viên
-- drop procedure SP_1
go
create procedure SP_1
as
begin
	select GV.MaGV,
		count(DT.MaDT) as SoDeTaiThamGia,
		count(case when (DT.GVCNDT = GV.MaGV) then 1 end) as SoDeTaiChuNhiem
	from GiaoVien as GV,
		ThamGiaDT as TG,
		DeTai as DT
	where GV.MaGV = TG.MaGV
		and TG.MaDT = DT.MaDT
	group by GV.MaGV
end
go

execute SP_1
go

-- Cho danh sách các giảng viên tham gia nhiều đề tài có kinh phí >100tr nhất.
-- drop procedure SP_2
go
create procedure SP_2
as
begin
	select GiaoVien.MaGV
	from GiaoVien, DeTai, ThamGiaDT
	where GiaoVien.MaGV = ThamGiaDT.MaGV
		and DeTai.MaDT = ThamGiaDT.MaDT
		and DeTai.KinhPhi > 100
	group by GiaoVien.MaGV
end
go

execute SP_2
go

-- Xem danh sách các đề tài đã tham gia của 1 mã gv cho trước
-- drop procedure SP_3
go
create procedure SP_3 @MaGV char(3)
as
begin
	select distinct DeTai.MaDT
	from DeTai, ThamGiaDT
	where DeTai.MaDT = ThamGiaDT.MaDT
		and ThamGiaDT.MaGV = @MaGV
end
go

execute SP_3 '001'
go

-- Cập nhật lương của 1 mã gv cho trước
-- drop procedure SP_4
go
create procedure SP_4 @MaGV char(3), @Luong int
as
begin
	update GiaoVien
	set Luong = @Luong
	where MaGV = @MaGV
end
go

execute SP_4 '001', 2000
go

-- Xoá người thân của 1 mã gv bất kỳ
-- drop procedure SP_5
go
create procedure SP_5 @MaGV char(3)
as
begin
	delete from NguoiThan
	where MaGV = @MaGV
end
go

execute SP_5 '001'
go

-- Cập nhật phụ cấp của 1 mã gv trong 1 công việc cụ thể đã tham gia.
-- drop procedure SP_6
go
create procedure SP_6 @MaGV char(3), @MaDT char(3), @SoTT int, @PhuCap int
as
begin
	update ThamGiaDT
	set PhuCap = @PhuCap
	where MaGV = @MaGV
		and MaDT = @MaDT
		and STT = @SoTT
end
go

execute SP_6 '001', '002', 1, 0
go