use QLGV
go

-- 27. Cho biết số lượng giáo viên viên và tổng lương của họ.
select count(MaGV) as SoGV, sum(Luong) as TongLuong
from GiaoVien
go

-- 28. Cho biết số lượng giáo viên và lương trung bình của từng bộ môn.
select BM.MaBM, BM.TenBoMon, count(MaGV) as SoGV, avg(Luong) as LuongTB
from GiaoVien as GV
	join BoMon as BM on GV.MaBM = BM.MaBM
group by BM.MaBM, BM.TenBoMon
go

-- 29. Cho biết tên chủ đề và số lượng đề tài thuộc về chủ đề đó.
select CD.TenCD as TenChuDe, count(MaDT) as SoDeTai
from ChuDe as CD, DeTai as DT
where CD.MaCD = DT.MaCD
group by CD.TenCD
go

-- 30. Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó tham gia.
select GV.TenGV, count(MaDT) as SoDeTaiThamGia
from GiaoVien as GV, ThamGiaDT as TG
where GV.MaGV = TG.MaGV
group by GV.MaGV, GV.TenGV
go

-- 31. Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó làm chủ nhiệm.
select GV.TenGV, count(MaDT) as SoDeTaiChuNhiem
from GiaoVien as GV, DeTai as DT
where GV.MaGV = DT.GVCNDT
group by GV.MaGV, GV.TenGV
go

-- 32. Với mỗi giáo viên cho tên giáo viên và số người thân của giáo viên đó.	
select GV.TenGV, count(NT.MaGV) as SoNguoiThan
from GiaoVien as GV, NguoiThan as NT
where GV.MaGV = NT.MaGV
group by GV.MaGV, GV.TenGV
go

-- 33. Cho biết tên những giáo viên đã tham gia từ 3 đề tài trở lên.
select GV.TenGV, count(MaDT) as SoDeTaiThamGia
from GiaoVien as GV
    join ThamGiaDT as TG on GV.MaGV = TG.MaGV
group by TG.MaGV, GV.TenGV
having count(MaDT) >= 3
go

-- 34. Cho biết số lượng giáo viên đã tham gia vào đề tài N"Ứng dụng hóa học xanh".
select count(MaGV) SoGVThamGia
from ThamGiaDT
    left join DeTai on ThamGiaDT.MaDT = DeTai.MaDT
where TenDT = N'Ứng dụng hóa học xanh'
go