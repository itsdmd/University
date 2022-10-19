-- Họ tên: Đào Minh Đức
-- MSSV: 2159003
-- Mã đề: 33

USE QLTHI
GO

-- 1.
create table PHONGTHI
(
    IDPhong char(4) not null,
    IDDiemThi char(3) not null,
    CanBo char(5),
    SoBan int,
    ThietBi nvarchar(50),

    primary key (IDPhong, IDDiemThi)
)

create table THISINH
(
    SBD char(4) not null,
    DiemThi char(3),
    HoTen nvarchar(50),
    DiaChi nvarchar(20),
    NgaySinh date,
    PhongThi char(4),

    primary key (SBD)
)

create table GIAOVIEN
(
    MaGV char(5) not null,
    TenGV nvarchar(50),
    DiaChi nvarchar(50),
    VaiTro nvarchar(10),

    primary key (MaGV)
)


-- 2.
alter table PHONGTHI add constraint FK_PHONGTHI_CanBo foreign key (CanBo) references GIAOVIEN(MaGV)
alter table THISINH add constraint FK_THISINH_PhongThiDiemThi foreign key (PhongThi,DiemThi) references PHONGTHI(IDPhong,IDDiemThi)


-- 3.
insert into GIAOVIEN values ('GV001', N'Trần Thị Bé', N'31 Nguyễn Xí Q. Bình Thạnh', N'Cán bộ')
insert into GIAOVIEN values ('GV002', N'Nguyễn Minh Tâm', N'2 Trần Hưng Đạo', N'Giám sát')
insert into GIAOVIEN values ('GV003', N'Trần Văn Lí', N'30 Hà Tồn Quyền Q5', N'Cán bộ')

insert into PHONGTHI values ('P001', 'DD1', 'GV001', 25, N'Mic - Loa - TV')
insert into PHONGTHI values ('P002', 'DD1', 'GV002', 30, N'Mic - Loa - TV')
insert into PHONGTHI values ('P001', 'DD2', 'GV003', 15, null)

SET DATEFORMAT DMY
insert into THISINH values ('0231', 'DD1', N'Nguyễn Quan Tùng', N'TPHCM', '30/11/2000', 'P001')
insert into THISINH values ('0230', 'DD2', N'Lưu Phi Nam', N'Hải Phòng', '12/2/2000', 'P001')
insert into THISINH values ('0234', 'DD1', N'Lê Quang Bảo', N'Hà Nội', '13/2/2000', 'P002')
insert into THISINH values ('0233', 'DD2', N'Hà Ngọc Thúy', N'TPHCM', '24/4/2000', 'P001')


-- 4.
select P.IDPhong, P.IDDiemThi, G.TenGV
from PHONGTHI as P
	join GIAOVIEN as G on P.CanBo = G.MaGV
    join THISINH as T on P.IDPhong = T.PhongThi and P.IDDiemThi = T.DiemThi
where G.VaiTro like N'Giám sát'
    and P.SoBan > 15
    and T.DiaChi like N'Hải Phòng'