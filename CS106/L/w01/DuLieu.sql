USE [QLBanHang]
GO
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH_01', N'Anh', N'Nu', N'0583819989', N'15 Nguyen Cong Tru')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH_02', N'Binh', N'Nam', N'3868754476', N'32 Nguyen Thai Binh')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH_03', N'Khang', N'Nam', N'5113756452', N'19/3 Thanh Thai')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH_04', N'Nhi', N'Nu', N'6278456671', N'65 Ngo Thoi Nhiem')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH_05', N'Trong', N'Nam', N'0837752798', N'102 Nguyen Van Thu')
GO
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD_01', CAST(N'2021-12-24T00:00:00.000' AS DateTime), N'KH_03')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD_02', CAST(N'2022-01-05T00:00:00.000' AS DateTime), N'KH_02')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD_03', CAST(N'2022-03-15T00:00:00.000' AS DateTime), N'KH_05')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD_04', CAST(N'2022-06-17T00:00:00.000' AS DateTime), N'KH_01')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD_05', CAST(N'2022-09-10T00:00:00.000' AS DateTime), N'KH_04')
GO
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP_01', N'Nike Vapor', CAST(N'2021-07-25T00:00:00.000' AS DateTime), 2090000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP_02', N'Adidas Fusion', CAST(N'2022-01-12T00:00:00.000' AS DateTime), 3140000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP_03', N'New Balance Legend', CAST(N'2022-02-22T00:00:00.000' AS DateTime), 1990000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP_04', N'Mizuno Forza', CAST(N'2022-04-07T00:00:00.000' AS DateTime), 4120000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP_05', N'Wilson Urban', CAST(N'2022-08-17T00:00:00.000' AS DateTime), 8200000.0000)
GO
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD_01', N'SP_01', 2, 4180000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD_01', N'SP_04', 1, 4120000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD_02', N'SP_02', 1, 3140000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD_03', N'SP_05', 1, 8200000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD_04', N'SP_03', 2, 3980000.0000)
GO
