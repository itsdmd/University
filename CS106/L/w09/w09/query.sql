use QLGV
go

-- 1. Cho ds cac gv thuoc bo mon CNPM co tham gia tat ca de tai co kinh phi > 20
select *
from GiaoVien as GV1
where GV1.MaBM = 'CNPM'
	and GV1.MaGV not in ( select GV2.MaGV
							from GiaoVien as GV2,
								DeTai,
								ThamGiaDT
							where DeTai.MaDT = ThamGiaDT.MaDT
								and ThamGiaDT.MaGV = GV2.MaGV
								and KinhPhi > 20 )
go
						
-- 2. Voi moi bo mon, cho biet bo mon nao co so luong gv chu nhiem de tai cap DHQG nhieu nhat
select GV1.MaBM, count(GV1.MaGV) as SoLuong
from GiaoVien as GV1,
	DeTai as DT1,
	ThamGiaDT as TG1
where GV1.MaGV = TG1.MaGV
	and TG1.MaDT = DT1.MaDT
	and DT1.CapQL = N'ĐHQG'
group by GV1.MaBM
having count(GV1.MaGV) >= ALL ( select count(GV2.MaGV)
								from GiaoVien as GV2,
									DeTai as DT2,
									ThamGiaDT as TG2
								where GV2.MaGV = TG2.MaGV
									and TG2.MaDT = DT2.MaDT
									and DT2.CapQL = N'ĐHQG'
									and GV2.MaBM = GV1.MaBM
								group by GV2.MaBM )
go

-- 3. Viet store xuat danh sach cac de tai da ket thuc trong nam 2021
create procedure sp_XuatDSDT
as
begin
	select *
	from DeTai
	where YEAR(NgayKT) = 2021
end
go

execute sp_XuatDSDT
go