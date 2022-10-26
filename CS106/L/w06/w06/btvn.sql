use QLGV
go

-- 1. Cho số công việc đã tham gia của mỗi giảng viên thuộc bộ môn HTTT.
-- Chỉ xuất 3 giảng viên tham gia hơn 3 công việc.
select top 3
    gv.MaGV, gv.TenGV, count(TenCV) as SoCongViec
from GiaoVien as GV
	join ThamGiaDT as TG on GV.MaGV = TG.MaGV
	join CongViec as CV on (TG.MaDT = CV.MaDT and TG.STT = CV.SoTT)
where GV.MaBM = N'HTTT'
group by gv.MaGV, gv.TenGV
having count(cv.TenCV) > 3
go

-- 2. Cho biết các giảng viên chủ nhiệm hơn 3 đề tài thuộc chủ đề "NGHIÊN CỨU PHÁT TRIỂN"
select gv.MaGV, gv.TenGV, count(dt.MaDT) as SoDeTai
from GiaoVien as GV
	join ThamGiaDT as TG on TG.MaGV = GV.MaGV
	join DeTai as DT on DT.MaDT = TG.MaDT
where DT.TenDT = N'NGHIÊN CỨU PHÁT TRIỂN'
-- where DT.TenDT = N'Nghiên cứu phát triển'
group by gv.MaGV, gv.TenGV
having count(dt.MaDT) > 3
go

-- 3. Cho biết các bộ môn có hơn 3 giảng viên chủ nhiệm đề tài.
select bm.MaBM, bm.TenBoMon, count(gv.MaGV) as SoGiangVienCNDT
from BoMon as BM
	join GiaoVien as GV on GV.MaBM = BM.MaBM
	join ThamGiaDT as TG on TG.MaGV = GV.MaGV
	join DeTai as DT on DT.MaDT = TG.MaDT
group by bm.MaBM, bm.TenBoMon
having count(gv.MaGV) > 3
go

-- 4. Cho biết các khoa có hơn 5 giảng viên
select K.MaKhoa, K.TenKhoa, count(gv.MaGV) as SoGiangVien
from Khoa as K
	join BoMon as BM on BM.MaKhoa = K.MaKhoa
	join GiaoVien as GV on GV.MaBM = BM.MaBM
group by K.MaKhoa, K.TenKhoa
having count(gv.MaGV) > 5
go

-- 5. Đếm số đề tài chủ nhiệm của mỗi trưởng khoa.
select GV.MaGV, GV.TenGV, count(DT.MaDT) as SoDeTai
from GiaoVien as GV
	right join Khoa as K on GV.MaGV = K.TruongKhoa
	join DeTai as DT on GV.MaGV = DT.GVCNDT
group by GV.MaGV, GV.TenGV
go