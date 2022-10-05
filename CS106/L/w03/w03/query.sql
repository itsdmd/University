USE QLGV
GO

-- 1. Luong GV nu
SELECT Luong
FROM GiaoVien
WHERE Phai = N'Nữ'

-- 3. MaGV cua (TenGV bat dau bang 'Nguyen' & Luong > 2000) | GVTBM nhan chuc sau 1995
SELECT MaGV
FROM GiaoVien
WHERE (TenGV LIKE N'Nguyễn%') AND (Luong > 2000)
UNION
SELECT TruongBoMon
FROM BoMon
WHERE (YEAR(NgayNhanChuc) > 1995)

-- 5. BoMon + GVTBM
SELECT *
FROM BoMon
LEFT JOIN GiaoVien
ON BoMon.TruongBoMon = GiaoVien.MaGV

-- 7. DeTai + GVCNDT
SELECT *
FROM DeTai
LEFT JOIN GiaoVien
ON DeTai.GVCNDT = GiaoVien.MaGV

-- 9. GiaoVien (TenBoMon = 'Vi sinh') & (MaDT = '006')
SELECT *
FROM GiaoVien
WHERE MaBM = (SELECT MaBM
              FROM BoMon
              WHERE TenBoMon = N'Vi sinh')
    AND MaGV IN (SELECT GVCNDT
                 FROM DeTai
                 WHERE MaDT = '006')