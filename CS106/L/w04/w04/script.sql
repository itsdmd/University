USE OnThiGiuaKi
GO



-- Create THANHVIEN table
SET DATEFORMAT DMY
CREATE TABLE THANHVIEN
(
    IDThanhVien char(1) NOT NULL,
    HoTen nvarchar(50),
    SoCMND char(9),
    DiaChi nvarchar(50),
    NgaySinh date,

    PRIMARY KEY (IDThanhVien)
)

-- Create DOI table
CREATE TABLE DOI
(
    IDDoi char(1) NOT NULL,
    TenDoi nvarchar(50),
    DoiTruong char(1),
    SoLuong int,

    PRIMARY KEY (IDDoi),
    CONSTRAINT FK_DOI_DoiTruong FOREIGN KEY (DoiTruong) REFERENCES THANHVIEN(IDThanhVien)
)

-- Create BOTRI table
CREATE TABLE BOTRI
(
    IDDoi char(1) NOT NULL,
    IDThanhVien char(1) NOT NULL,
    DiaChi nvarchar(50),
    NhiemVu nvarchar(50),
    QuanLi char(1),

    PRIMARY KEY (IDDoi, IDThanhVien),
    CONSTRAINT FK_BOTRI_IDDoi FOREIGN KEY (IDDoi) REFERENCES DOI(IDDoi),
    CONSTRAINT FK_BOTRI_IDThanhVien FOREIGN KEY (IDThanhVien) REFERENCES THANHVIEN(IDThanhVien),
    CONSTRAINT FK_BOTRI_QuanLi FOREIGN KEY (QuanLi) REFERENCES THANHVIEN(IDThanhVien)
)



-- Input data for DOI
INSERT INTO DOI VALUES ('2', N'Đội Tân Phú', '1', NULL)
INSERT INTO DOI VALUES ('7', N'Đội Bình Phú', '2', NULL)

-- Input data for BOTRI
INSERT INTO BOTRI VALUES ('2', '2', N'123 Vườn Lài Tân Phú', N'Trực khu vực vòng xoay 1', '1')
INSERT INTO BOTRI VALUES ('2', '1', N'45 Phú Thọ Hòa Tân Phú', N'Theo dõi hoạt động', '1')
INSERT INTO BOTRI VALUES ('7', '3', N'11 Chợ lớn Bình Phú', NULL, '2')
INSERT INTO BOTRI VALUES ('7', '4', N'2 Bis Nguyễn Văn Cừ Q5', NULL, '5')

-- Input data for THANHVIEN
INSERT INTO THANHVIEN VALUES ('1', N'Nguyễn Quan Tùng', '240674018', N'TPHCM', '30/01/2000')
INSERT INTO THANHVIEN VALUES ('2', N'Lưu Phi Nam', '240674027', N'Quảng Nam', '12/3/2001')
INSERT INTO THANHVIEN VALUES ('3', N'Lê Quang Bảo', '240674063', N'Quảng Ngãi', '14/5/1999')
INSERT INTO THANHVIEN VALUES ('4', N'Hà Ngọc Thúy', '240674504', N'TPHCM', '26/7/1998')
INSERT INTO THANHVIEN VALUES ('5', N'Trương Thị Minh', '240674405', N'Hà Nội', NULL)
INSERT INTO THANHVIEN VALUES ('6', N'Ngô Thị Thủy', '240674306', NULL, '18/9/2000')



-- Query
-- Tên đội & tên đội trưởng của các thành viên thực hiện nhiệm vụ tại địa chỉ Tân Phú
SELECT DISTINCT TenDoi, DT.HoTen AS HoTenDoiTruong
FROM BOTRI AS BT
    JOIN DOI AS D ON BT.IDDoi = D.IDDoi
    JOIN THANHVIEN AS DT ON D.DoiTruong = DT.IDThanhVien
    JOIN THANHVIEN AS TV ON BT.IDThanhVien = TV.IDThanhVien
WHERE BT.DiaChi LIKE N'%Tân Phú%'