----login
--sp_addlogin [ @loginame = ] ‘login_name’ [ , [ @passwd = ] 'password' ] [ , [ @defdb = ]‘default_database’ ] 
--sp_password [[@old =]   ‘old_pass’,] {[@new=] ‘new_pass} [,[@loginame=] ‘login’]
--sp_grantlogin [@loginame =]   ‘windows_account’
--sp_revokelogin [@loginame=] ‘login’]
--sp_droplogin [@loginame =]   ‘login_name
--sp_defaultdb [@loginame =]   ‘login_name’, [@defdb=] ‘database_name’
-----user--------------------------------------------------------------------
--sp_grantdbaccess [@loginame =]‘login_name’[,[@name_in_db =] ‘user_name’]
--CREATE USER user_name  
--[ { FOR | FROM } { LOGIN login_name}]    
--[ WITH DEFAULT_SCHEMA =schema_name ] 
--sp_revokedbaccess 	‘user_name’

----role--------------------------------------------------------------------
--sp_addrole [ @rolename = ] 'role'  [ , [ @ownername = ] 'owner' ] 
--sp_addsrvrolemember [ @loginame = ] 'login',[ @rolename = ] 'role’
--sp_dbfixedrolepermission [ [ @rolename = ] 'role' ]  
--sp_helprolemember [ [ @rolename = ] 'role' ]  
--CREATE ROLE role_name [ AUTHORIZATION owner_name ]  
--ALTER ROLE  role_name {  
--       ADD MEMBER database_principal  
--    |  DROP MEMBER database_principal  
--   |  WITH NAME = new_name  
--}  
--[;]  
--DROP ROLE [ IF EXISTS ] role_name  
--sp_droprole [ @rolename= ] 'role' 
--sp_addrolemember [ @rolename = ] 'role', [ @membername = ] 'security_account'  
--sp_droprolemember [ @rolename = ] 'role', [ @membername = ] 'security_account'  
--EXEC sp_dbfixedrolepermission;  

--GRANT { ALL | statement [ ,...n ] } 	TO security_account [ ,...n ] 

--GRANT { ALL | permission [ ,...n ] } {    [ ( column [ ,...n ] ) ] ON { table | view } 
--		   | ON { table | view } [ ( column [ ,...n ] ) ] 
--	     | ON { stored_procedure}      | ON { user_defined_function }    } TO security_account [ ,...n ] [ WITH GRANT OPTION ] [ AS  role  ] 

--DENY  { ALL | statement [ ,...n ] } TO	 security_account [ ,...n ] 

--DENY{ ALL | permission [ ,...n ] } {    [ ( column [ ,...n ] ) ] ON { table | view } 
	--	   | ON { table | view } [ ( column [ ,...n ] ) ] 
	  --   | ON { stored_procedure}      | ON { user_defined_function }    } TO security_account [ ,...n ] [CASCADE]

--REVOKE { ALL | statement [ ,...n ] } From security_account [ ,...n ] 

--REVOKE{ ALL | permission [ ,...n ] } {    [ ( column [ ,...n ] ) ] ON { table | view } 
 --      | ON { table | view } [ ( column [ ,...n ] ) ] 
--	    | ON { stored_procedure}     | ON { user_defined_function }    } FROM security_account [ ,...n ] [CASCADE]
--	[ AS  role  ] 

----
--Tạo login để đăng nhập vào hệ quản trị (SQL login)
sp_addlogin 'GV02','123'
go
--Đổi password của login (dùng sa)
sp_password null, '123','gv02' --ko cần cấp pass
--Đổi pass của login (dùng gv02)
sp_password '111', '123','gv02' --phải cấp pass cũ
--Xóa login
sp_droplogin 'gv02'
--Tạo user
CREATE USER gv02
FOR LOGIN GV02
WITH DEFAULT_SCHEMA = GV02
--Cấp quyền thực hiện câu lệnh
GRANT CREATE TABLE TO GV02 
--Cấp quyền thao tác dữ liệu
go
create 
--alter
view v_XemThongTinCaNhan
as
select *
from GIAOVIEN
where MAGV = CURRENT_USER
go
grant select,update on v_XemThongTinCaNhan to gv02
--cấp quyền và cho gv02 đem quyền cấp cho người khác
grant select,update on v_XemThongTinCaNhan to gv02
with grant option
--Thu hồi quyền alter đã cấp
revoke alter from gv02
--thu hồi quyền select đã cấp cho gv02 và các quyền mà gv02 cấp cho người khác
revoke select on v_XemThongTinCaNhan from gv02
cascade
--Cấm quyền select của gv02
Deny select on v_XemThongTinCaNhan to gv02
--thêm role mới
sp_addrole 'quanly' , 'dbo'
--add user vào role
sp_addrolemember 'quanly','gv01'  
--cấp quyền select, update cho role giaovien
grant select on ketqua to giaovien
grant update on ketqua(diem) to giaovien
grant select, insert on v_XemKetQua to giaovien
--tạo view xem kết quả của giáo viên chấm
go
create view v_XemKetQua
as
select kq.*
from KETQUA kq join SINHVIEN sv on sv.MaSV = kq.MaSV
join GV_LOP gvl on gvl.MaLop = sv.MaLop
where gvl.MaGV = CURRENT_USER
--cấp tất cả quyền trên monhoc cho quản lý
grant all on monhoc to quanly
with grant option
--cấm quyền xem thông tin cá nhân cho sv01
deny select on v_XemThongCaNhan to sv01
--thu hồi lệnh cấm=> ko còn cấm mà cũng ko có quyền select luôn
revoke select on v_XemThongCaNhan from sv01
--cấp quyền thực thi thủ tục
grant execute on usp1 to gv01
--tạo thủ tục test
create proc usp1
as
	print 'abc'
go
--xóa role
DROP ROLE giaovien
sp_droprolemember 'giaovien','gv02'
--add login vào role của server
sp_addsrvrolemember  'gv01','setupadmin'