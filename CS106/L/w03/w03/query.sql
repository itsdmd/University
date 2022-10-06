USE QLGV
GO

-- 1. Cho biết họ tên và mức lương của các giáo viên nữ.
SELECT Luong
FROM GiaoVien
WHERE Phai = N'Nữ'

-- 2. Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%.
SELECT TenGV, Luong*1.1 as Luong10
FROM GiaoVien

-- 3. Cho biết mã của các giáo viên có họ tên bắt đầu là “Nguyễn” và lương trên $2000, hoặc giáo viên là trưởng bộ môn nhận chức sau năm 1995.
SELECT MaGV
FROM GiaoVien
WHERE (TenGV LIKE N'Nguyễn%')
    AND (Luong > 2000)
UNION
SELECT TruongBoMon
FROM BoMon
WHERE (YEAR(NgayNhanChuc) > 1995)

-- 4. Cho biết tên những giáo viên khoa Công nghệ thông tin.
SELECT TenGV
FROM GiaoVien
    LEFT JOIN BoMon ON BoMon.MaBM = GiaoVien.MaBM
    LEFT JOIN Khoa ON Khoa.MaKhoa = BoMon.MaKhoa
WHERE Khoa.TenKhoa = N'Công nghệ thông tin'

-- 5. Cho biết thông tin của bộ môn cùng thông tin giảng viên làm trưởng bộ môn đó.
SELECT *
FROM BoMon
JOIN GiaoVien
ON BoMon.TruongBoMon = GiaoVien.MaGV

-- 6. Với mỗi giáo viên, hãy cho biết thông tin của bộ môn mà họ đang làm việc.
SELECT *
FROM GiaoVien
    LEFT JOIN BoMon
ON GiaoVien.MaBM = BoMon.MaBM

-- 7.Cho biết tên đề tài và giáo viên chủ nhiệm đề tài.
SELECT *
FROM DeTai
    LEFT JOIN GiaoVien
ON DeTai.GVCNDT = GiaoVien.MaGV

-- 8. Với mỗi khoa cho biết thông tin trưởng khoa.
SELECT *
FROM Khoa
    LEFT JOIN GiaoVien
ON Khoa.TruongKhoa = GiaoVien.MaGV

-- 9.Cho biết các giáo viên của bộ môn “Vi sinh” có tham gia đề tài 006.
SELECT *
FROM GiaoVien
    LEFT JOIN BoMon ON BoMon.MaBM = GiaoVien.MaBM
    LEFT JOIN DeTai ON DeTai.GVCNDT = GiaoVien.MaGV
WHERE (BoMon.TenBoMon = N'Vi sinh')
    AND (DeTai.MaDT = '006')

-- 10. Với những đề tài thuộc cấp quản lý “Thành phố”, cho biết mã đề tài, đề tài thuộc về chủ đề nào, họ tên người chủ nghiệm đề tài cùng với ngày sinh và địa chỉ của người ấy.
SELECT TenDT, ChuDe.MaCD, ChuDe.TenCD, TenGV, NgSinh, DiaChi
FROM DeTai
    LEFT JOIN ChuDe ON DeTai.MaCD = ChuDe.MaCD
    LEFT JOIN GiaoVien ON DeTai.GVCNDT = GiaoVien.MaGV
WHERE CapQL = N'Thành phố'

-- 11. Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp của giáo viên đó.
SELECT GV.TenGV, GVQL.TenGV AS TenGVQLCM
FROM GiaoVien AS GV
    LEFT JOIN GiaoVien AS GVQL ON GV.GVQLCM = GVQL.MaGV

-- 12. Tìm họ tên của những giáo viên được “Nguyễn Thanh Tùng” phụ trách trực tiếp.
SELECT GV.TenGV
FROM GiaoVien AS GV
LEFT JOIN GiaoVien AS GVQLCM ON GV.GVQLCM = GVQLCM.MaGV
WHERE GVQLCM.TenGV = N'Nguyễn Thanh Tùng'

-- 13. Cho biết tên giáo viên là trưởng bộ môn “Hệ thống thông tin”.
SELECT TenGV
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaGV = BoMon.TruongBoMon
WHERE BoMon.TenBoMon = N'Hệ thống thông tin'

-- 14. Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề Quản lý giáo dục.
SELECT DISTINCT TenGV
FROM GiaoVien
    LEFT JOIN DeTai ON GiaoVien.MaGV = DeTai.GVCNDT
    LEFT JOIN ChuDe ON DeTai.MaCD = ChuDe.MaCD
WHERE ChuDe.TenCD = N'Quản lý giáo dục'

-- 15. Cho biết tên các công việc của đề tài HTTT quản lý các trường ĐH có thời gian bắt đầu trong tháng 3/2008.
SELECT TenCV
FROM CongViec
    LEFT JOIN DeTai ON CongViec.MaDT = DeTai.MaDT
WHERE (DeTai.TenDT = N'HTTT quản lý các trường ĐH')
    AND (MONTH(CongViec.NgayBD) = 3)
    AND (YEAR(CongViec.NgayBD) = 2008)

-- 16. Cho biết tên giáo viên và tên người quản lý chuyên môn của giáo viên đó.
SELECT GV.TenGV, GVQL.TenGV AS TenGVQLCM
FROM GiaoVien AS GV
    LEFT JOIN GiaoVien AS GVQL ON GV.GVQLCM = GVQL.MaGV

-- 17. Cho các công việc bắt đầu trong khoảng từ 01/01/2007 đến 01/08/2007.
SELECT *
FROM CongViec
WHERE (DAY(CongViec.NgayBD) >= 1) AND (MONTH(CongViec.NgayBD) >= 1) AND (YEAR(CongViec.NgayBD) >= 2007)
    AND (DAY(CongViec.NgayKT) <= 1) AND (MONTH(CongViec.NgayKT) <= 8) AND (YEAR(CongViec.NgayKT) <= 2007)

-- 18. Cho biết họ tên các giáo viên cùng bộ môn với giáo viên “Trần Trà Hương”.
SELECT GiaoVien.TenGV
FROM GiaoVien
    LEFT JOIN GiaoVien AS TTH ON TTH.TenGV = N'Trần Trà Hương'
WHERE GiaoVien.MaBM = TTH.MaBM

-- 19. Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài.
SELECT DISTINCT GiaoVien.*
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaBM = BoMon.MaBM
    LEFT JOIN DeTai ON GiaoVien.MaGV = DeTai.GVCNDT
WHERE (GiaoVien.MaGV = BoMon.TruongBoMon)
    AND (GiaoVien.MaGV = DeTai.GVCNDT)

-- 20. Cho biết tên những giáo viên vừa là trưởng khoa và vừa là trưởng bộ môn.
SELECT DISTINCT TenGV
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaBM = BoMon.MaBM
    LEFT JOIN Khoa ON BoMon.MaKhoa = Khoa.MaKhoa
WHERE (GiaoVien.MaGV = Khoa.TruongKhoa)
    AND (GiaoVien.MaGV = BoMon.TruongBoMon)

-- 21. Cho biết tên những trưởng bộ môn mà vừa chủ nhiệm đề tài.
SELECT DISTINCT TenGV
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaBM = BoMon.MaBM
    LEFT JOIN DeTai ON GiaoVien.MaGV = DeTai.GVCNDT
WHERE (GiaoVien.MaGV = BoMon.TruongBoMon)
    AND (GiaoVien.MaGV = DeTai.GVCNDT)

-- 22. Cho biết mã số các trưởng khoa có chủ nhiệm đề tài.
SELECT DISTINCT MaGV
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaBM = BoMon.MaBM
    LEFT JOIN Khoa ON BoMon.MaKhoa = Khoa.MaKhoa
    LEFT JOIN DeTai ON GiaoVien.MaGV = DeTai.GVCNDT
WHERE (GiaoVien.MaGV = Khoa.TruongKhoa)
    AND (GiaoVien.MaGV = DeTai.GVCNDT)

-- 23. Cho biết mã số các giáo viên thuộc bộ môn “HTTT” hoặc có tham gia đề tài mã “001”.
SELECT DISTINCT MaGV
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaBM = BoMon.MaBM
    LEFT JOIN DeTai ON GiaoVien.MaGV = DeTai.GVCNDT
WHERE (GiaoVien.MaBM = 'HTTT')
    OR (DeTai.MaDT = '001')

-- 24. Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002.
SELECT DISTINCT GiaoVien.*
FROM GiaoVien
    LEFT JOIN GiaoVien AS ZZT ON ZZT.MaGV = '002'
WHERE GiaoVien.MaBM = ZZT.MaBM

-- 25. Tìm những giáo viên là trưởng bộ môn.
SELECT DISTINCT GiaoVien.*
FROM GiaoVien
    LEFT JOIN BoMon ON GiaoVien.MaBM = BoMon.MaBM
WHERE GiaoVien.MaGV = BoMon.TruongBoMon

-- 26. Cho biết họ tên và mức lương của các giáo viên.
SELECT TenGV, Luong
FROM GiaoVien