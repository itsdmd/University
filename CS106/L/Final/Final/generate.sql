USE [master]
GO
/****** Object:  Database [QLNhomNghienCuu]    Script Date: 2/8/2021 9:41:15 PM ******/
CREATE DATABASE [QLNhomNghienCuu]
go
USE [QLNhomNghienCuu]
GO
/****** Object:  Table [dbo].[GiangVien]    Script Date: 2/8/2021 9:41:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
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
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[HocVi]    Script Date: 2/8/2021 9:41:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
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
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[HocVi_QuaTrinh]    Script Date: 2/8/2021 9:41:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[HocVi_QuaTrinh](
	[MaGV] [varchar](5) NOT NULL,
	[HocVi] [varchar](50) NOT NULL,
	[NgayCap] [datetime] NOT NULL,
	[NoiCap] [nvarchar](40) NULL,
 CONSTRAINT [PK_ChucDanh] PRIMARY KEY CLUSTERED 
(
	[MaGV] ASC,
	[HocVi] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Khoa]    Script Date: 2/8/2021 9:41:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
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
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[NhomNC]    Script Date: 2/8/2021 9:41:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
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
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[ThanhVien_NNC]    Script Date: 2/8/2021 9:41:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
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
SET ANSI_PADDING OFF
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV01', N'Tr?n Xuân Hi?n', N'0276886', CAST(0x000080AF00000000 AS DateTime), N'CNTT', N'CN')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV02', N'Phan V?n Ngh?a', N'0276887', CAST(0x00007C9C00000000 AS DateTime), N'CNTT', N'TS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV03', N'Nguy?n Th? Mai', N'0034881150', CAST(0x000086FF00000000 AS DateTime), N'CNTT', N'ThS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV04', N'Tr??ng Gia Minh', N'0348811230', CAST(0x0000869400000000 AS DateTime), N'VL', N'ThS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV05', N'Nguy?n Ánh Loan', N'02886765', CAST(0x0000767B00000000 AS DateTime), N'VL', N'TS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV06', N'Tr?n Gia Nam', N'02881147', CAST(0x00007E6900000000 AS DateTime), N'CNTT', N'TS')
GO
INSERT [dbo].[GiangVien] ([MaGV], [HoTen], [CMND], [NgaySinh], [MaKhoa], [HocVi]) VALUES (N'GV07', N'Nguy?n Tr?n Huy', N'01181178', CAST(0x00007BAF00000000 AS DateTime), N'CNTT', N'ThS')
GO
INSERT [dbo].[HocVi] ([MaHV], [TenHV]) VALUES (N'CN', N'C? nhân')
GO
INSERT [dbo].[HocVi] ([MaHV], [TenHV]) VALUES (N'ThS', N'Th?c s?')
GO
INSERT [dbo].[HocVi] ([MaHV], [TenHV]) VALUES (N'TS', N'Ti?n s?')
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV01', N'ThS', CAST(0x0000A8DD00000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV02', N'ThS', CAST(0x0000A32800000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV03', N'ThS', CAST(0x0000AADD00000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV04', N'CN ', CAST(0x0000A52A00000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV05', N'ThS', CAST(0x0000A1D900000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV05', N'TS ', CAST(0x0000A69B00000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV06', N'TS ', CAST(0x0000A90000000000 AS DateTime), NULL)
GO
INSERT [dbo].[HocVi_QuaTrinh] ([MaGV], [HocVi], [NgayCap], [NoiCap]) VALUES (N'GV07', N'ThS', CAST(0x0000A49400000000 AS DateTime), NULL)
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'CNTT', N'Công ngh? thông tin', 1995, N'GV06')
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'HH', N'Hoá h?c', 1998, NULL)
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'VL', N'V?t lý', 1998, N'GV05')
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamTL], [TruongKhoa]) VALUES (N'VS', N'Vi sinh', 2000, NULL)
GO
INSERT [dbo].[NhomNC] ([MaNhom], [TenNhom], [NgayLapNhom], [TruongNhom], [MaKhoa]) VALUES (N'NH01', N'CNTT - H? t? v?n', CAST(0x0000A25300000000 AS DateTime), N'GV02', N'CNTT')
GO
INSERT [dbo].[NhomNC] ([MaNhom], [TenNhom], [NgayLapNhom], [TruongNhom], [MaKhoa]) VALUES (N'NH02', N'CNTT - Trí tu? nhân t?o', CAST(0x0000A9EA00000000 AS DateTime), N'GV03', N'CNTT')
GO
INSERT [dbo].[NhomNC] ([MaNhom], [TenNhom], [NgayLapNhom], [TruongNhom], [MaKhoa]) VALUES (N'NH03', N'VL - V?t lý ?ng d?ng', CAST(0x0000A4AF00000000 AS DateTime), N'GV05', N'VL')
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH01', N'GV01', CAST(0x0000A25D00000000 AS DateTime), CAST(0x0000A3E000000000 AS DateTime))
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH01', N'GV02', CAST(0x0000A25300000000 AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH01', N'GV07', CAST(0x0000A3E400000000 AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH02', N'GV03', CAST(0x0000A9EA00000000 AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH02', N'GV06', CAST(0x0000A9EA00000000 AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH03', N'GV04', CAST(0x0000A4AF00000000 AS DateTime), NULL)
GO
INSERT [dbo].[ThanhVien_NNC] ([MaNhom], [MaGV], [NgayVaoNhom], [NgayRoiNhom]) VALUES (N'NH03', N'GV05', CAST(0x0000A4AF00000000 AS DateTime), NULL)
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
go
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