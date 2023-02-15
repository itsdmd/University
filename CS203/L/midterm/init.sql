USE [QLNhomNghienCuu]
GO
ALTER TABLE [dbo].[ThanhVien_NNC] DROP CONSTRAINT [FK_ThanhVien_NNC_NhomNC]
GO
ALTER TABLE [dbo].[ThanhVien_NNC] DROP CONSTRAINT [FK_ThanhVien_NNC_GiangVien]
GO
ALTER TABLE [dbo].[TacGiaSP] DROP CONSTRAINT [FK_TacGiaSP_ThanhVien_NNC]
GO
ALTER TABLE [dbo].[TacGiaSP] DROP CONSTRAINT [FK_TacGiaSP_SanPhamDT]
GO
ALTER TABLE [dbo].[SanPhamDT] DROP CONSTRAINT [FK_SanPhamDT_DeTaiNCC]
GO
ALTER TABLE [dbo].[NhomNC] DROP CONSTRAINT [FK_NhomNC_Khoa]
GO
ALTER TABLE [dbo].[NhomNC] DROP CONSTRAINT [FK_NhomNC_GiangVien]
GO
ALTER TABLE [dbo].[Khoa] DROP CONSTRAINT [FK_Khoa_GiangVien]
GO
ALTER TABLE [dbo].[HocVi_QuaTrinh] DROP CONSTRAINT [FK_HocVi_QuaTrinh_HocVi]
GO
ALTER TABLE [dbo].[HocVi_QuaTrinh] DROP CONSTRAINT [FK_ChucDanh_GiangVien]
GO
ALTER TABLE [dbo].[GiangVien] DROP CONSTRAINT [FK_GiangVien_Khoa]
GO
ALTER TABLE [dbo].[GiangVien] DROP CONSTRAINT [FK_GiangVien_HocVi]
GO
ALTER TABLE [dbo].[DeTaiNCC] DROP CONSTRAINT [FK_DeTaiNCC_NhomNC1]
GO
/****** Object:  Table [dbo].[ThanhVien_NNC]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[ThanhVien_NNC]') AND type in (N'U'))
DROP TABLE [dbo].[ThanhVien_NNC]
GO
/****** Object:  Table [dbo].[TacGiaSP]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[TacGiaSP]') AND type in (N'U'))
DROP TABLE [dbo].[TacGiaSP]
GO
/****** Object:  Table [dbo].[SanPhamDT]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[SanPhamDT]') AND type in (N'U'))
DROP TABLE [dbo].[SanPhamDT]
GO
/****** Object:  Table [dbo].[NhomNC]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[NhomNC]') AND type in (N'U'))
DROP TABLE [dbo].[NhomNC]
GO
/****** Object:  Table [dbo].[Khoa]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[Khoa]') AND type in (N'U'))
DROP TABLE [dbo].[Khoa]
GO
/****** Object:  Table [dbo].[HocVi_QuaTrinh]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[HocVi_QuaTrinh]') AND type in (N'U'))
DROP TABLE [dbo].[HocVi_QuaTrinh]
GO
/****** Object:  Table [dbo].[HocVi]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[HocVi]') AND type in (N'U'))
DROP TABLE [dbo].[HocVi]
GO
/****** Object:  Table [dbo].[GiangVien]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[GiangVien]') AND type in (N'U'))
DROP TABLE [dbo].[GiangVien]
GO
/****** Object:  Table [dbo].[DeTaiNCC]    Script Date: 8/2/2023 3:06:11 PM ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DeTaiNCC]') AND type in (N'U'))
DROP TABLE [dbo].[DeTaiNCC]
GO
USE [master]
GO
/****** Object:  Database [QLNhomNghienCuu]    Script Date: 8/2/2023 3:06:11 PM ******/
DROP DATABASE [QLNhomNghienCuu]
GO
/****** Object:  Database [QLNhomNghienCuu]    Script Date: 8/2/2023 3:06:11 PM ******/
CREATE DATABASE [QLNhomNghienCuu]
GO
USE [QLNhomNghienCuu]
GO
/****** Object:  Table [dbo].[DeTaiNCC]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DeTaiNCC](
	[MaDT] [varchar](20) NOT NULL,
	[MaNNC] [varchar](5) NOT NULL,
	[TenDT] [nvarchar](50) NULL,
	[NgayBD] [date] NULL,
	[NgayKT] [date] NULL,
	[NgayNT] [datetime] NULL,
	[Kinhphi] [money] NULL,
	[ChuNhiemDT] [varchar](5) NULL,
	[XepLoai] [nvarchar](50) NULL,
 CONSTRAINT [PK_DeTaiNCC] PRIMARY KEY CLUSTERED 
(
	[MaDT] ASC,
	[MaNNC] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[GiangVien]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GiangVien](
	[MaGV] [varchar](5) NOT NULL,
	[HoTen] [nvarchar](50) NULL,
	[CMND] [varchar](20) NULL,
	[NgaySinh] [datetime] NULL,
	[MaKhoa] [varchar](5) NULL,
	[HocVi] [varchar](3) NULL,
 CONSTRAINT [PK_GiangVien] PRIMARY KEY CLUSTERED 
(
	[MaGV] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[HocVi]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HocVi](
	[MaHV] [varchar](3) NOT NULL,
	[TenHV] [nvarchar](50) NULL,
 CONSTRAINT [PK_HocVi] PRIMARY KEY CLUSTERED 
(
	[MaHV] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[HocVi_QuaTrinh]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HocVi_QuaTrinh](
	[MaGV] [varchar](5) NOT NULL,
	[HocVi] [varchar](3) NOT NULL,
	[NgayCap] [datetime] NOT NULL,
	[NoiCap] [nvarchar](40) NULL,
 CONSTRAINT [PK_ChucDanh] PRIMARY KEY CLUSTERED 
(
	[MaGV] ASC,
	[HocVi] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Khoa]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Khoa](
	[MaKhoa] [varchar](5) NOT NULL,
	[TenKhoa] [nvarchar](50) NULL,
	[NamTL] [int] NULL,
	[TruongKhoa] [varchar](5) NULL,
 CONSTRAINT [PK_Khoa] PRIMARY KEY CLUSTERED 
(
	[MaKhoa] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[NhomNC]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NhomNC](
	[MaNhom] [varchar](5) NOT NULL,
	[TenNhom] [nvarchar](50) NULL,
	[NgayLapNhom] [datetime] NULL,
	[TruongNhom] [varchar](5) NULL,
	[MaKhoa] [varchar](5) NULL,
 CONSTRAINT [PK_NhomNC] PRIMARY KEY CLUSTERED 
(
	[MaNhom] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[SanPhamDT]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SanPhamDT](
	[MaDT] [varchar](20) NOT NULL,
	[MaNNC] [varchar](5) NOT NULL,
	[STT] [int] NOT NULL,
	[TenSP] [nvarchar](50) NULL,
	[Loai] [varchar](5) NULL,
	[ISBN] [varchar](20) NULL,
	[NgayXB] [datetime] NULL,
 CONSTRAINT [PK_SanPhamDT] PRIMARY KEY CLUSTERED 
(
	[MaDT] ASC,
	[MaNNC] ASC,
	[STT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TacGiaSP]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TacGiaSP](
	[MaDT] [varchar](20) NULL,
	[MaNNC] [varchar](5) NULL,
	[STT] [int] NOT NULL,
	[MaGV] [varchar](5) NULL,
	[VaiTro] [nvarchar](50) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ThanhVien_NNC]    Script Date: 8/2/2023 3:06:11 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ThanhVien_NNC](
	[MaNhom] [varchar](5) NOT NULL,
	[MaGV] [varchar](5) NOT NULL,
	[NgayVaoNhom] [datetime] NULL,
	[NgayRoiNhom] [datetime] NULL,
 CONSTRAINT [PK_ThanhVien_NNC] PRIMARY KEY CLUSTERED 
(
	[MaNhom] ASC,
	[MaGV] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[DeTaiNCC] ([MaDT], [MaNNC], [TenDT], [NgayBD], [NgayKT], [NgayNT], [Kinhphi], [ChuNhiemDT], [XepLoai]) VALUES (N'2022.CNTT.01', N'NH01', N'Cải thiện độ tương đồng của hệ thống tư vấn', CAST(N'2022-03-01' AS Date), CAST(N'2022-09-01' AS Date), CAST(N'2022-09-15T00:00:00.000' AS DateTime), 50000000.0000, N'GV01', N'Giỏi')
GO
INSERT [dbo].[DeTaiNCC] ([MaDT], [MaNNC], [TenDT], [NgayBD], [NgayKT], [NgayNT], [Kinhphi], [ChuNhiemDT], [XepLoai]) VALUES (N'2022.CNTT.02', N'NH02', N'Phương pháp tư vấn khoá học', CAST(N'2022-03-01' AS Date), CAST(N'2022-09-01' AS Date), NULL, 60000000.0000, N'GV03', NULL)
GO
INSERT [dbo].[DeTaiNCC] ([MaDT], [MaNNC], [TenDT], [NgayBD], [NgayKT], [NgayNT], [Kinhphi], [ChuNhiemDT], [XepLoai]) VALUES (N'2022.CNTT.03', N'NH03', N'Xây dựng hệ thống gợi ý du lịch', CAST(N'2022-03-01' AS Date), CAST(N'2022-09-01' AS Date), CAST(N'2023-01-25T00:00:00.000' AS DateTime), 50000000.0000, N'GV05', N'Đạt')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV01', N'Trần Xuân Hiền', N'0276886', CAST(N'1990-03-13T00:00:00.000' AS DateTime), N'CNTT', N'CN')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV02', N'Phan Văn Nghĩa', N'0276887', CAST(N'1987-05-05T00:00:00.000' AS DateTime), N'CNTT', N'TS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV03', N'Nguyễn Thị Mai', N'0034881150', CAST(N'1994-08-15T00:00:00.000' AS DateTime), N'CNTT', N'ThS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV04', N'Trương Gia Minh', N'0348811230', CAST(N'1994-04-30T00:00:00.000' AS DateTime), N'VL', N'ThS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV05', N'Nguyễn Ánh Loan', N'02886765', CAST(N'1983-01-17T00:00:00.000' AS DateTime), N'VL', N'TS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV06', N'Trần Gia Nam', N'02881147', CAST(N'1988-08-08T00:00:00.000' AS DateTime), N'CNTT', N'TS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV07', N'Nguyễn Trần Huy', N'01181178', CAST(N'1986-09-10T00:00:00.000' AS DateTime), N'CNTT', N'ThS')
GO
INSERT [dbo].[HocVi] ([MaHV], [TenHV]) VALUES (N'CN', N'Cử nhân')
GO
INSERT [dbo].[HocVi] ([MaHV], [TenHV]) VALUES (N'ThS', N'Thạc sỹ')
GO
INSERT [dbo].[HocVi] ([MaHV], [TenHV]) VALUES (N'TS', N'Tiến sĩ')
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV01', N'ThS', CAST(N'2018-05-11T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV02', N'ThS', CAST(N'2014-05-11T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV03', N'ThS', CAST(N'2019-10-05T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV04', N'CN ', CAST(N'2015-10-07T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV05', N'ThS', CAST(N'2013-06-10T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV05', N'TS ', CAST(N'2016-10-10T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV06', N'TS ', CAST(N'2018-06-15T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV07', N'ThS', CAST(N'2015-05-10T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'CNTT', N'Công nghệ thông tin', 1995, N'GV06')
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'HH', N'Hoá học', 1998, NULL)
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'VL', N'Vật lý', 1998, N'GV05')
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'VS', N'Vi sinh', 2000, NULL)
GO
INSERT [dbo].[NhomNC] ([MaNhom], [TenNhom], [NgayLapNhom], [TruongNhom], [MaKhoa]) VALUES (N'NH01', N'CNTT - Hệ tư vấn', CAST(N'2013-10-10T00:00:00.000' AS DateTime), N'GV02', N'CNTT')
GO
INSERT [dbo].[NhomNC] ([MaNhom], [TenNhom], [NgayLapNhom], [TruongNhom], [MaKhoa]) VALUES (N'NH02', N'CNTT - Trí tuệ nhân tạo', CAST(N'2019-02-04T00:00:00.000' AS DateTime), N'GV03', N'CNTT')
GO
INSERT [dbo].[NhomNC] ([MaNhom], [TenNhom], [NgayLapNhom], [TruongNhom], [MaKhoa]) VALUES (N'NH03', N'VL - Vật lý ứng dụng', CAST(N'2015-06-06T00:00:00.000' AS DateTime), N'GV05', N'VL')
GO
INSERT [dbo].[SanPhamDT] ([MaDT], [MaNNC], [STT], [TenSP], [Loai], [ISBN], [NgayXB]) VALUES (N'2022.CNTT.01', N'NH01', 1, N'Cải thiện độ tương đồng dựa trên phân rã ma trận', N'HN', NULL, CAST(N'2022-08-04T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[SanPhamDT] ([MaDT], [MaNNC], [STT], [TenSP], [Loai], [ISBN], [NgayXB]) VALUES (N'2022.CNTT.01', N'NH01', 2, N'Cải thiện độ tương đồng dựa trên ngữ nghĩa', N'HN', NULL, CAST(N'2022-09-02T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[SanPhamDT] ([MaDT], [MaNNC], [STT], [TenSP], [Loai], [ISBN], [NgayXB]) VALUES (N'2022.CNTT.03', N'NH03', 1, N'Gợi ý tour du lịch dựa trên ngữ cảnh', N'HN', NULL, CAST(N'2022-12-02T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH01', N'GV01', CAST(N'2013-10-20T00:00:00.000' AS DateTime), CAST(N'2014-11-11T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH01', N'GV02', CAST(N'2013-10-10T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH01', N'GV07', CAST(N'2014-11-15T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH02', N'GV03', CAST(N'2019-02-04T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH02', N'GV06', CAST(N'2019-02-04T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH03', N'GV04', CAST(N'2015-06-06T00:00:00.000' AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH03', N'GV05', CAST(N'2015-06-06T00:00:00.000' AS DateTime), NULL)
GO
ALTER TABLE [dbo].[DeTaiNCC]  WITH CHECK ADD  CONSTRAINT [FK_DeTaiNCC_NhomNC1] FOREIGN KEY([MaNNC])
REFERENCES [dbo].[NhomNC] ([MaNhom])
GO
ALTER TABLE [dbo].[DeTaiNCC] CHECK CONSTRAINT [FK_DeTaiNCC_NhomNC1]
GO
ALTER TABLE [dbo].[GiangVien]  WITH CHECK ADD  CONSTRAINT [FK_GiangVien_HocVi] FOREIGN KEY([HocVi])
REFERENCES [dbo].[HocVi] ([MaHV])
GO
ALTER TABLE [dbo].[GiangVien] CHECK CONSTRAINT [FK_GiangVien_HocVi]
GO
ALTER TABLE [dbo].[GiangVien]  WITH CHECK ADD  CONSTRAINT [FK_GiangVien_Khoa] FOREIGN KEY([MaKhoa])
REFERENCES [dbo].[Khoa] ([MaKhoa])
GO
ALTER TABLE [dbo].[GiangVien] CHECK CONSTRAINT [FK_GiangVien_Khoa]
GO
ALTER TABLE [dbo].[HocVi_QuaTrinh]  WITH CHECK ADD  CONSTRAINT [FK_ChucDanh_GiangVien] FOREIGN KEY([MaGV])
REFERENCES [dbo].[GiangVien] ([MaGV])
GO
ALTER TABLE [dbo].[HocVi_QuaTrinh] CHECK CONSTRAINT [FK_ChucDanh_GiangVien]
GO
ALTER TABLE [dbo].[HocVi_QuaTrinh]  WITH CHECK ADD  CONSTRAINT [FK_HocVi_QuaTrinh_HocVi] FOREIGN KEY([HocVi])
REFERENCES [dbo].[HocVi] ([MaHV])
GO
ALTER TABLE [dbo].[HocVi_QuaTrinh] CHECK CONSTRAINT [FK_HocVi_QuaTrinh_HocVi]
GO
ALTER TABLE [dbo].[Khoa]  WITH CHECK ADD  CONSTRAINT [FK_Khoa_GiangVien] FOREIGN KEY([TruongKhoa])
REFERENCES [dbo].[GiangVien] ([MaGV])
GO
ALTER TABLE [dbo].[Khoa] CHECK CONSTRAINT [FK_Khoa_GiangVien]
GO
ALTER TABLE [dbo].[NhomNC]  WITH CHECK ADD  CONSTRAINT [FK_NhomNC_GiangVien] FOREIGN KEY([TruongNhom])
REFERENCES [dbo].[GiangVien] ([MaGV])
GO
ALTER TABLE [dbo].[NhomNC] CHECK CONSTRAINT [FK_NhomNC_GiangVien]
GO
ALTER TABLE [dbo].[NhomNC]  WITH CHECK ADD  CONSTRAINT [FK_NhomNC_Khoa] FOREIGN KEY([MaKhoa])
REFERENCES [dbo].[Khoa] ([MaKhoa])
GO
ALTER TABLE [dbo].[NhomNC] CHECK CONSTRAINT [FK_NhomNC_Khoa]
GO
ALTER TABLE [dbo].[SanPhamDT]  WITH CHECK ADD  CONSTRAINT [FK_SanPhamDT_DeTaiNCC] FOREIGN KEY([MaDT], [MaNNC])
REFERENCES [dbo].[DeTaiNCC] ([MaDT], [MaNNC])
GO
ALTER TABLE [dbo].[SanPhamDT] CHECK CONSTRAINT [FK_SanPhamDT_DeTaiNCC]
GO
ALTER TABLE [dbo].[TacGiaSP]  WITH CHECK ADD  CONSTRAINT [FK_TacGiaSP_SanPhamDT] FOREIGN KEY([MaDT], [MaNNC], [STT])
REFERENCES [dbo].[SanPhamDT] ([MaDT], [MaNNC], [STT])
GO
ALTER TABLE [dbo].[TacGiaSP] CHECK CONSTRAINT [FK_TacGiaSP_SanPhamDT]
GO
ALTER TABLE [dbo].[TacGiaSP]  WITH CHECK ADD  CONSTRAINT [FK_TacGiaSP_ThanhVien_NNC] FOREIGN KEY([MaNNC], [MaGV])
REFERENCES [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV])
GO
ALTER TABLE [dbo].[TacGiaSP] CHECK CONSTRAINT [FK_TacGiaSP_ThanhVien_NNC]
GO
ALTER TABLE [dbo].[ThanhVien_NNC]  WITH CHECK ADD  CONSTRAINT [FK_ThanhVien_NNC_GiangVien] FOREIGN KEY([MaGV])
REFERENCES [dbo].[GiangVien] ([MaGV])
GO
ALTER TABLE [dbo].[ThanhVien_NNC] CHECK CONSTRAINT [FK_ThanhVien_NNC_GiangVien]
GO
ALTER TABLE [dbo].[ThanhVien_NNC]  WITH CHECK ADD  CONSTRAINT [FK_ThanhVien_NNC_NhomNC] FOREIGN KEY([MaNhom])
REFERENCES [dbo].[NhomNC] ([MaNhom])
GO
ALTER TABLE [dbo].[ThanhVien_NNC] CHECK CONSTRAINT [FK_ThanhVien_NNC_NhomNC]
GO
USE [master]
GO
ALTER DATABASE [QLNhomNghienCuu] SET  READ_WRITE 
GO