CREATE DATABASE QLGV
GO
USE QLGV
GO


-- Create Tables

CREATE TABLE GiaoVien
(
	MaGV CHAR(3),
	TenGV NVARCHAR(30),
	Luong INT,
	Phai NVARCHAR(3),
	NgSinh DATE,
	DiaChi NVARCHAR(50),
	GVQLCM CHAR(3),
	MaBM VARCHAR(5),

	CONSTRAINT PK_GiaoVien PRIMARY KEY(MaGV)
)

CREATE TABLE Khoa
(
	MaKhoa VARCHAR(5),
	TenKhoa NVARCHAR(30),
	NamTL INT,
	Phong CHAR(3),
	DienThoai VARCHAR(11),
	TruongKhoa CHAR(3),
	NgayNhanChuc DATE,

	CONSTRAINT PK_Khoa PRIMARY KEY(MaKhoa)
)

CREATE TABLE BoMon
(
	MaBM VARCHAR(5),
	TenBoMon NVARCHAR(30),
	Phong CHAR(3),
	DienThoai VARCHAR(11),
	TruongBoMon CHAR(3),
	MaKhoa VARCHAR(5),
	NgayNhanChuc DATE,

	CONSTRAINT PK_BoMon PRIMARY KEY(MaBM)
)


-- Create Foreign Keys

ALTER TABLE GiaoVien
	ADD CONSTRAINT FK_MaGV_GVQLCM
	FOREIGN KEY(GVQLCM)
	REFERENCES GiaoVien(MaGV)
	
ALTER TABLE GiaoVien
	ADD CONSTRAINT FK_MaBM_BoMon
	FOREIGN KEY(MaBM)
	REFERENCES BoMon(MaBM)


ALTER TABLE Khoa
	ADD CONSTRAINT FK_TruongKhoa_GiaoVien
	FOREIGN KEY(TruongKhoa)
	REFERENCES GiaoVien(MaGV)


ALTER TABLE BoMon
	ADD CONSTRAINT FK_TruongBoMon_GiaoVien
	FOREIGN KEY(TruongBoMon)
	REFERENCES GiaoVien(MaGV)

ALTER TABLE BoMon
	ADD CONSTRAINT FK_MaKhoa_Khoa
	FOREIGN KEY(MaKhoa)
	REFERENCES Khoa(MaKhoa)


-- Data Input
INSERT INTO BoMon VALUES('CNTT', N'Công nghệ tri thức', 'B15', '0838126126', NULL, 'CNTT', NULL)
INSERT INTO BoMon VALUES('HHC', N'Hóa hữu cơ', 'B44', '838222222', NULL, 'HH', NULL)
INSERT INTO BoMon VALUES('HL', N'Hóa lý', 'B42', '0838878787', NULL, 'HH', NULL)
INSERT INTO BoMon VALUES('HPT', N'Hóa phân tích', 'B43', '0838777777', '007', 'HH', '2007-10-15')
INSERT INTO BoMon VALUES('HTTT', N'Hệ thống thông tin', 'B13', '0838125125', '002', 'CNTT', '2004-09-20')
INSERT INTO BoMon VALUES('MMT', N'Mạng máy tính', 'B16', '0838676767', '001', 'CNTT', '2005-05-15')
INSERT INTO BoMon VALUES('SH', N'Sinh hóa', 'B33', '0838898989', NULL, 'SH', NULL)
INSERT INTO BoMon VALUES('VLĐT', N'Vật lý điện tử', 'B23', '0838234234', NULL, 'VL', NULL)
INSERT INTO BoMon VALUES('VLƯD', N'Vật lý ứng dụng', 'B24', '0838454545', '005', 'VL', '2006-02-18')
INSERT INTO BoMon VALUES('VS', N'Vi sinh', 'B32', '0838909090', '004', 'SH', '2007-01-01')

INSERT INTO GiaoVien VALUES('001', N'Nguyễn Hoài An', 2000, N'Nam', '1990-02-15', N'25/3 Lạc Long Quân, Q.10, TP HCM', NULL, 'MMT')
INSERT INTO GiaoVien VALUES('002', N'Trần Trà Hương', 2500, N'Nữ', '1960-06-20', N'125 Trần Hưng Đạo, Q.1, TP HCM', NULL, 'HTTT')
INSERT INTO GiaoVien VALUES('003', N'Nguyễn Ngọc Ánh', 2200, N'Nữ', '1975-05-11', N'12/21 Võ Văn Ngân, Thủ Đức, TP HCM', '002', 'HTTT')
INSERT INTO GiaoVien VALUES('004', N'Trương Nam Sơn', 2300, N'Nam', '1959-06-20', N'215 Lý Thường Kiệt, TP Biên Hòa', NULL, 'VS')
INSERT INTO GiaoVien VALUES('005', N'Lý Hoàng Hà', 2500, N'Nam', '1954-10-23', N'22/5 Nguyễn Xí, Q. Bình Thạnh, TP HCM', NULL, 'VLĐT')
INSERT INTO GiaoVien VALUES('006', N'Trần Bạch Tuyết', 1500, N'Nữ', '1980-05-20', N'127 Hùng Vương, TP Mỹ Tho', '004', 'VS')
INSERT INTO GiaoVien VALUES('007', N'Nguyễn An Trung', 1800, N'Nam', '1976-06-05', N'234 3/2, TP Biên Hòa', NULL, 'HPT')
INSERT INTO GiaoVien VALUES('008', N'Trần Trung Hiếu', 1800, N'Nam', '1977-08-06', N'22/11 Lý Thường Kiệt, TP Mỹ Tho', '007', 'HPT')
INSERT INTO GiaoVien VALUES('009', N'Trần Hoàng Nam', 2000, N'Nam', '1975-11-22', N'234 Trấn Não, An Phú, TP HCM', '001', 'MMT')
INSERT INTO GiaoVien VALUES('010', N'Phạm Nam Thand', 1500, N'Nam', '1980-12-22', N'221 Hùng Vương, Q.5, TP HCM', '007', 'HPT')