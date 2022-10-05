USE QLGV
GO

-- 1. Luong GV nu
SELECT Luong
FROM GiaoVien
WHERE Phai = N'Nữ'

-- 2. TenGV + Luong +10%
SELECT TenGV, Luong*1.1 as Luong10
FROM GiaoVien

-- 3. MaGV cua (TenGV bat dau bang 'Nguyen' & Luong > 2000) | GVTBM nhan chuc sau 1995
SELECT MaGV
FROM GiaoVien
WHERE (TenGV LIKE N'Nguyễn%') AND (Luong > 2000)
UNION
SELECT TruongBoMon
FROM BoMon
WHERE (YEAR(NgayNhanChuc) > 1995)

-- 4. TenGV co (TenKhoa = N'Công nghệ thông tin')
SELECT TenGV
FROM GiaoVien
    LEFT JOIN BoMon ON BoMon.MaBM = GiaoVien.MaBM
    LEFT JOIN Khoa ON Khoa.MaKhoa = BoMon.MaKhoa
WHERE Khoa.TenKhoa = N'Công nghệ thông tin'

-- 5. BoMon + GVTBM
SELECT *
FROM BoMon
JOIN GiaoVien
ON BoMon.TruongBoMon = GiaoVien.MaGV

-- 6. GiaoVien + BoMon
SELECT *
FROM GiaoVien
    LEFT JOIN BoMon
ON GiaoVien.MaBM = BoMon.MaBM

-- 7. DeTai + GVCNDT
SELECT *
FROM DeTai
    LEFT JOIN GiaoVien
ON DeTai.GVCNDT = GiaoVien.MaGV

-- 8. Khoa + TruongKhoa
SELECT *
FROM Khoa
    LEFT JOIN GiaoVien
ON Khoa.TruongKhoa = GiaoVien.MaGV

-- 9. GiaoVien (TenBoMon = 'Vi sinh') & (MaDT = '006')
SELECT *
FROM GiaoVien
    LEFT JOIN BoMon ON BoMon.MaBM = GiaoVien.MaBM
    LEFT JOIN DeTai ON DeTai.GVCNDT = GiaoVien.MaGV
WHERE (BoMon.TenBoMon = N'Vi sinh') AND (DeTai.MaDT = '006')

-- 10. DeTai (CapQL = 'Thành phố'): TenDT, ChuDe, GVCNDT(TenGV + NgSinh + DiaChi)
SELECT TenDT, ChuDe.MaCD, ChuDe.TenCD, TenGV, NgSinh, DiaChi
FROM DeTai
    LEFT JOIN ChuDe ON DeTai.MaCD = ChuDe.MaCD
    LEFT JOIN GiaoVien ON DeTai.GVCNDT = GiaoVien.MaGV
WHERE CapQL = N'Thành phố'

-- 11. TenGV + GVQLCM(TenGV)
SELECT GV.TenGV, GVQL.TenGV AS TenGVQLCM
FROM GiaoVien AS GV
    LEFT JOIN GiaoVien AS GVQL ON GV.GVQLCM = GVQL.MaGV

-- 12. TenGV co TenGVQLCM = 'Nguyễn Thanh Tùng'
SELECT GV.TenGV
FROM GiaoVien AS GV
LEFT JOIN GiaoVien AS GVQLCM ON GV.GVQLCM = GVQLCM.MaGV
WHERE GVQLCM.TenGV = N'Nguyễn Thanh Tùng'