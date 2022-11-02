use QLGV
go

-- T5.54. Cho biết tên giáo viên và tên bộ môn của giáo viên tham gia nhiều đề tài nhất.
select top 1 gv.TenGV, bm.TenBoMon
from GiaoVien as gv,
    BoMon as bm,
    DeTai as dt,
    ThamGiaDT as tg
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and gv.MaBM = bm.MaBM
group by gv.TenGV, bm.TenBoMon
having count(tg.MaGV) = (select top 1 count(tg.MaGV)
                         from ThamGiaDT as tg
                         group by tg.MaGV
                         order by count(tg.MaGV) desc)
go

-- T5.55. Cho biết tên giáo viên tham gia nhiều đề tài nhất của bộ môn HTTT.
select top 1 gv.TenGV
from GiaoVien as gv,
    BoMon as bm,
    ThamGiaDT as tg
where gv.MaGV = tg.MaGV
    and gv.MaBM = bm.MaBM
    and bm.MaBM = 'HTTT'
group by gv.TenGV
order by count(tg.MaGV) desc
go

-- T6.58. Cho biết tên giáo viên nào mà tham gia đề tài đủ tất cả các chủ đề.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt,
    ChuDe as cd
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.MaCD = cd.MaCD
group by gv.TenGV
having count(distinct cd.MaCD) = (select count(*)
                                  from ChuDe)
go

-- T6.61. Cho biết giáo viên nào đã tham gia tất cả các đề tài có mã chủ đề là QLGD.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.MaCD = 'QLGD'
group by gv.TenGV
having count(distinct tg.MaDT) = (select count(*)
                                  from DeTai
                                  where MaCD = 'QLGD')
go