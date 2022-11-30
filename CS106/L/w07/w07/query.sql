use QLGV
go


-- T5.35. Cho biết mức lương cao nhất của các giảng viên.
select max(Luong)
from GiaoVien
go

-- T5.36. Cho biết những giáo viên có lương lớn nhất.
select TenGV
from GiaoVien
where Luong = (select max(Luong)
               from GiaoVien)
go

-- T5.37. Cho biết lương cao nhất trong bộ môn “HTTT”.
select max(Luong)
from GiaoVien
where MaBM = 'HTTT'
go

-- T5.38. Cho biết tên giáo viên lớn tuổi nhất của bộ môn Hệ thống thông tin.
select TenGV
from GiaoVien as gv,
	BoMon as bm
where gv.MaBM = bm.MaBM
	and bm.TenBoMon = N'Hệ thống thông tin'
    and (year(getdate()) - year(NgSinh)) = (select max(year(getdate()) - year(NgSinh))
                                             from GiaoVien as gv,
                                                BoMon as bm
                                            where gv.MaBM = bm.MaBM
                                                and bm.TenBoMon = N'Hệ thống thông tin')
go

-- T5.39. Cho biết tên giáo viên nhỏ tuổi nhất khoa Công nghệ thông tin.
select TenGV
from GiaoVien as gv,
	BoMon as bm
where gv.MaBM = bm.MaBM
	and bm.TenBoMon = N'Công nghệ thông tin'
    and (year(getdate()) - year(NgSinh)) = (select min(year(getdate()) - year(NgSinh))
                                             from GiaoVien as gv,
                                                BoMon as bm
                                            where gv.MaBM = bm.MaBM
                                                and bm.TenBoMon = N'Công nghệ thông tin')
go

-- T5.40. Cho biết tên giáo viên và tên khoa của giáo viên có lương cao nhất.
select gv.TenGV, k.TenKhoa
from GiaoVien as gv,
    BoMon as bm,
    Khoa as k
where gv.MaBM = bm.MaBM
    and bm.MaKhoa = k.MaKhoa
    and gv.Luong = (select max(Luong)
                    from GiaoVien)
go

-- T5.41. Cho biết những giáo viên có lương lớn nhất trong bộ môn của họ.
select gv.TenGV
from GiaoVien as gv,
    BoMon as bm
where gv.MaBM = bm.MaBM
    and gv.Luong = (select max(Luong)
                    from GiaoVien
                    where MaBM = gv.MaBM)
go

-- T5.42. Cho biết tên những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia.
select dt.TenDT
from DeTai as dt
where dt.MaDT not in (select tg.MaDT
                      from ThamGiaDT as tg,
                        GiaoVien as gv
                      where tg.MaGV = gv.MaGV
                        and gv.TenGV = N'Nguyễn Hoài An')
go

-- T5.43. Cho biết những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia. Xuất ra tên đề tài, tên người chủ nhiệm đề tài.
select distinct dt.TenDT, gv.TenGV as TenGVCNDT
from DeTai as dt,
    GiaoVien as gv
where dt.GVCNDT = gv.MaGV
    and dt.MaDT not in (select tg.MaDT
                        from ThamGiaDT as tg,
                            GiaoVien as gv
                        where tg.MaGV = gv.MaGV
                            and gv.TenGV = N'Nguyễn Hoài An')
go

-- T5.44. Cho biết tên những giáo viên khoa Công nghệ thông tin mà chưa tham gia đề tài nào.
select gv.TenGV
from GiaoVien as gv,
    BoMon as bm,
    Khoa as k
where gv.MaBM = bm.MaBM
    and bm.MaKhoa = k.MaKhoa
    and k.TenKhoa = N'Công nghệ thông tin'
    and gv.MaGV not in (select tg.MaGV
                        from ThamGiaDT as tg)
go

-- T5.45. Tìm những giáo viên không tham gia bất kỳ đề tài nào
select gv.TenGV
from GiaoVien as gv
where gv.MaGV not in (select tg.MaGV
                      from ThamGiaDT as tg)
go

-- T5.46. Cho biết giáo viên có lương lớn hơn lương của giáo viên “Nguyễn Hoài An”
select gv.TenGV
from GiaoVien as gv
where gv.Luong > (select Luong
                  from GiaoVien
                  where TenGV = N'Nguyễn Hoài An')
go

-- T5.47. Tìm những trưởng bộ môn tham gia tối thiểu 1 đề tài
select gv.TenGV
from GiaoVien as gv,
    BoMon as bm
where gv.MaBM = bm.MaBM
    and gv.MaGV in (select tg.MaGV
                    from ThamGiaDT as tg)
    and gv.MaGV = bm.TruongBoMon
go

-- T5.48. Tìm giáo viên trùng tên và cùng phái với giáo viên khác trong cùng bộ môn
select gv.TenGV
from GiaoVien as gv,
    BoMon as bm
where gv.MaBM = bm.MaBM
    and gv.MaGV in (select gv.MaGV
                    from GiaoVien as gv,
                        BoMon as bm
                    where gv.MaBM = bm.MaBM
                        and gv.TenGV in (select gv.TenGV
                                         from GiaoVien as gv,
                                            BoMon as bm
                                        where gv.MaBM = bm.MaBM
                                            and gv.MaGV <> gv.MaGV
                                            and gv.Phai = gv.Phai))
go

-- T5.49. Tìm những giáo viên có lương lớn hơn lương của ít nhất một giáo viên bộ môn “Công nghệ phần mềm”
select gv.TenGV
from GiaoVien as gv
where gv.Luong > (select min(Luong)
                  from GiaoVien as gv,
                    BoMon as bm
                  where gv.MaBM = bm.MaBM
                    and bm.TenBoMon = N'Công nghệ phần mềm')
go

-- T5.50. Tìm những giáo viên có lương lớn hơn lương của tất cả giáo viên thuộc bộ môn “Hệ thống thông tin”
select gv.TenGV
from GiaoVien as gv
where gv.Luong > (select max(Luong)
                  from GiaoVien as gv,
                    BoMon as bm
                  where gv.MaBM = bm.MaBM
                    and bm.TenBoMon = N'Hệ thống thông tin')
go

-- T5.51. Cho biết tên khoa có đông giáo viên nhất
select top 1 k.TenKhoa
from Khoa as k,
    BoMon as bm,
    GiaoVien as gv
where k.MaKhoa = bm.MaKhoa
    and bm.MaBM = gv.MaBM
group by k.TenKhoa
order by count(gv.MaGV) desc
go

-- T5.52. Cho biết họ tên giáo viên chủ nhiệm nhiều đề tài nhất
select top 1 gv.TenGV
from GiaoVien as gv,
    DeTai as dt
where gv.MaGV = dt.GVCNDT
group by gv.TenGV
order by count(dt.MaDT) desc
go

-- T5.53. Cho biết mã bộ môn có nhiều giáo viên nhất
select bm.MaBM
from BoMon as bm,
    GiaoVien as gv
where bm.MaBM = gv.MaBM
group by bm.MaBM
having count(gv.MaGV) = (select top 1 count(gv.MaGV)
                         from BoMon as bm,
                            GiaoVien as gv
                        where bm.MaBM = gv.MaBM
                        group by bm.MaBM)
go

-- T5.54. Cho biết tên giáo viên và tên bộ môn của giáo viên tham gia nhiều đề tài nhất.
select gv.TenGV, bm.TenBoMon
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
select gv.TenGV
from GiaoVien as gv,
    BoMon as bm,
    ThamGiaDT as tg
where gv.MaGV = tg.MaGV
    and gv.MaBM = bm.MaBM
    and bm.MaBM = 'HTTT'
group by gv.TenGV
having count(tg.MaGV) = (select top 1 count(tg.MaGV)
                         from ThamGiaDT as tg,
                            GiaoVien as gv,
                            BoMon as bm
                         where tg.MaGV = gv.MaGV
                            and gv.MaBM = bm.MaBM
                            and bm.MaBM = 'HTTT'
                         group by tg.MaGV
                         order by count(tg.MaGV) desc)
go

-- T5.56. Cho biết tên giáo viên và tên bộ môn của giáo viên có nhiều người thân nhất.
select gv.TenGV, bm.TenBoMon
from GiaoVien as gv,
    BoMon as bm,
    NguoiThan as nt
where gv.MaGV = nt.MaGV
    and gv.MaBM = bm.MaBM
group by gv.TenGV, bm.TenBoMon
having count(nt.MaGV) = (select top 1 count(nt.MaGV)
                         from NguoiThan as nt
                         group by nt.MaGV
                         order by count(nt.MaGV) desc)
go

-- T5.57. Cho biết tên trưởng bộ môn mà chủ nhiệm nhiều đề tài nhất.
select gv.TenGV
from GiaoVien as gv,
    BoMon as bm,
    DeTai as dt
where gv.MaGV = bm.TruongBoMon
    and dt.GVCNDT = gv.MaGV
group by gv.TenGV
having count(dt.MaDT) = (select top 1 count(dt.MaDT)
                         from DeTai as dt
                         group by dt.MaDT
                         order by count(dt.MaDT) desc)
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

-- T6.59. Cho biết tên đề tài nào mà được tất cả các giáo viên của bộ môn HTTT tham gia.
select dt.TenDT
from DeTai as dt,
    ThamGiaDT as tg,
    GiaoVien as gv,
    BoMon as bm
where dt.MaDT = tg.MaDT
    and tg.MaGV = gv.MaGV
    and gv.MaBM = bm.MaBM
    and bm.MaBM = 'HTTT'
group by dt.TenDT
having count(distinct gv.MaGV) = (select count(*)
                                  from GiaoVien as gv,
                                    BoMon as bm
                                  where gv.MaBM = bm.MaBM
                                    and bm.MaBM = 'HTTT')
go

-- T6.60. Cho biết tên đề tài có tất cả giảng viên bộ môn “Hệ thống thông tin” tham gia
select dt.TenDT
from DeTai as dt,
    ThamGiaDT as tg,
    GiaoVien as gv,
    BoMon as bm
where dt.MaDT = tg.MaDT
    and tg.MaGV = gv.MaGV
    and gv.MaBM = bm.MaBM
    and bm.MaBM = 'HTTT'
group by dt.TenDT
having count(distinct gv.MaGV) = (select count(*)
                                  from GiaoVien as gv,
                                    BoMon as bm
                                  where gv.MaBM = bm.MaBM
                                    and bm.TenBoMon = N'Hệ thống thông tin')
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

-- T6.62. Cho biết tên giáo viên nào tham gia tất cả các đề tài mà giáo viên Trần Trà Hương đã tham gia.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.MaDT in (select dt.MaDT
                    from DeTai as dt,
                        ThamGiaDT as tg,
                        GiaoVien as gv
                    where dt.MaDT = tg.MaDT
                        and tg.MaGV = gv.MaGV
                        and gv.TenGV = N'Trần Trà Hương')
group by gv.TenGV
having count(distinct tg.MaDT) = (select count(*)
                                  from DeTai as dt,
                                    ThamGiaDT as tg,
                                    GiaoVien as gv
                                  where dt.MaDT = tg.MaDT
                                    and tg.MaGV = gv.MaGV
                                    and gv.TenGV = N'Trần Trà Hương')
go

-- T6.63. Cho biết tên đề tài nào mà được tất cả các giáo viên của bộ môn Hóa Hữu Cơ tham gia.
select dt.TenDT
from DeTai as dt,
    ThamGiaDT as tg,
    GiaoVien as gv,
    BoMon as bm
where dt.MaDT = tg.MaDT
    and tg.MaGV = gv.MaGV
    and gv.MaBM = bm.MaBM
    and bm.TenBoMon = N'Hóa Hữu Cơ'
group by dt.TenDT
having count(distinct gv.MaGV) = (select count(*)
                                  from GiaoVien as gv,
                                    BoMon as bm
                                  where gv.MaBM = bm.MaBM
                                    and bm.TenBoMon = N'Hóa Hữu Cơ')
go

-- T6.64. Cho biết tên giáo viên nào mà tham gia tất cả các công việc của đề tài 006.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.MaDT = '006'
group by gv.TenGV
having count(tg.MaDT) = (select count(*)
                         from CongViec
                         where MaDT = '006')
go

-- T6.65. Cho biết giáo viên nào đã tham gia tất cả các đề tài của chủ đề Ứng dụng công nghệ.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
group by gv.TenGV
having count(distinct tg.MaDT) = (select count(*)
                                  from DeTai as dt,
                                    ChuDe as cd
                                  where dt.MaCD = cd.MaCD
                                    and cd.TenCD = N'Ứng dụng công nghệ')
go

-- T6.66. Cho biết tên giáo viên nào đã tham gia tất cả các đề tài của do Trần Trà Hương làm chủ nhiệm.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.GVCNDT = (select gv.MaGV
                   from GiaoVien as gv
                   where gv.TenGV = N'Trần Trà Hương')
group by gv.TenGV
having count(distinct tg.MaDT) = (select count(*)
                                  from DeTai as dt,
                                    GiaoVien as gv
                                  where dt.GVCNDT = gv.MaGV
                                    and gv.TenGV = N'Trần Trà Hương')
go

-- T6.67. Cho biết tên đề tài nào mà được tất cả các giáo viên của khoa CNTT tham gia.
select dt.TenDT
from DeTai as dt,
    ThamGiaDT as tg,
    GiaoVien as gv,
	BoMon as bm,
    Khoa as k
where dt.MaDT = tg.MaDT
    and tg.MaGV = gv.MaGV
    and gv.MaBM = bm.MaBM
    and bm.MaKhoa = k.MaKhoa
    and k.MaKhoa = 'CNTT'
group by dt.TenDT
having count(distinct gv.MaGV) = (select count(*)
                                  from GiaoVien as gv,
                                    BoMon as bm,
                                    Khoa as k
                                  where gv.MaBM = bm.MaBM
                                    and bm.MaKhoa = k.MaKhoa
                                    and k.MaKhoa = 'CNTT')
go

-- T6.68. Cho biết tên giáo viên nào mà tham gia tất cả các công việc của đề tài Nghiên cứu tế bào gốc.
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.TenDT = N'Nghiên cứu tế bào gốc'
group by gv.TenGV
having count(tg.MaDT) = (select count(*)
                         from CongViec
                         where MaDT = (select dt.MaDT
                                       from DeTai as dt
                                       where dt.TenDT = N'Nghiên cứu tế bào gốc'))
go

-- T6.69. Tìm tên các giáo viên được phân công làm tất cả các đề tài có kinh phí trên 100 triệu?
select gv.TenGV
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
group by gv.TenGV
having count(distinct tg.MaDT) = (select count(*)
                                  from DeTai as dt
                                  where dt.KinhPhi > 100)
go

-- T6.70. Cho biết tên đề tài nào mà được tất cả các giáo viên của khoa Sinh Học tham gia.
select dt.TenDT
from DeTai as dt,
    ThamGiaDT as tg,
    GiaoVien as gv,
    BoMon as bm,
    Khoa as k
where dt.MaDT = tg.MaDT
    and tg.MaGV = gv.MaGV
    and gv.MaBM = bm.MaBM
    and bm.MaKhoa = k.MaKhoa
    and k.TenKhoa = N'Sinh Học'
group by dt.TenDT
having count(distinct gv.MaGV) = (select count(*)
                                  from GiaoVien as gv,
                                    BoMon as bm,
                                    Khoa as k
                                  where gv.MaBM = bm.MaBM
                                    and bm.MaKhoa = k.MaKhoa
                                    and k.TenKhoa = N'Sinh Học')
go

-- T6.71. Cho biết mã số, họ tên, ngày sinh của giáo viên tham gia tất cả các công việc của đề tài “Ứng dụng hóa học xanh”.
select gv.MaGV, gv.TenGV, gv.NgSinh
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and dt.TenDT = N'Ứng dụng hóa học xanh'
group by gv.MaGV, gv.TenGV, gv.NgSinh
having count(tg.MaDT) = (select count(*)
                         from CongViec
                         where MaDT = (select dt.MaDT
                                       from DeTai as dt
                                       where dt.TenDT = N'Ứng dụng hóa học xanh'))
go

-- T6.72. Cho biết mã số, họ tên, tên bộ môn và tên người quản lý chuyên môn của giáo viên tham gia tất cả các đề tài thuộc chủ đề “Nghiên cứu phát triển”.	
select gv.MaGV, gv.TenGV, bm.TenBoMon, gv.GVQLCM
from GiaoVien as gv,
    ThamGiaDT as tg,
    DeTai as dt,
    ChuDe as cd,
    BoMon as bm
where gv.MaGV = tg.MaGV
    and tg.MaDT = dt.MaDT
    and gv.MaBM = bm.MaBM
    and dt.MaCD = cd.MaCD
    and cd.TenCD = N'Nghiên cứu phát triển'
group by gv.MaGV, gv.TenGV, bm.TenBoMon, gv.GVQLCM
having count(distinct tg.MaDT) = (select count(*)
                                  from DeTai as dt,
                                    ChuDe as cd
                                  where dt.MaCD = cd.MaCD
                                    and cd.TenCD = N'Nghiên cứu phát triển')
go