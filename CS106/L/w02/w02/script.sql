﻿CREATE DATABASE QLGV
GO
USE QLGV
GO


-- Create Tables

CREATE TABLE GiaoVien
(
	MaGV CHAR(3),
	TenGV NVARCHAR(30),
	Luong INT,
	NgaySinh DATE,
	Phai NVARCHAR(3),
	NgSinh DATE,
	DiaChi NVARCHAR(50),
	GVQLCM CHAR(3),
	MaBM VARCHAR(3),

	CONSTRAINT PK_GiaoVien PRIMARY KEY(MaGV)
)

CREATE TABLE Khoa
(
	MaKhoa CHAR(3),
	TenKhoa NVARCHAR(10),
	NamTL INT,
	Phong CHAR(3),
	DienThoai VARCHAR(11),
	TruongKhoa CHAR(3),
	NgayNhanChuc DATE,

	CONSTRAINT PK_Khoa PRIMARY KEY(MaKhoa)
)

CREATE TABLE BoMon
(
	MaBM VARCHAR(3),
	TenBoMon NVARCHAR(20),
	Phong CHAR(3),
	DienThoai VARCHAR(11),
	TruongBoMon CHAR(3),
	MaKhoa VARCHAR(3),
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