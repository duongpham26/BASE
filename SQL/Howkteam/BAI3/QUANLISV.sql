
USE QUANLISV

CREATE TABLE GiaoVien 
(
	MaGV NVARCHAR(10),
	NAME NVARCHAR(10)
)

CREATE TABLE HocSinh 
(
	MaHS NVARCHAR(10),
	NAME NVARCHAR(10)
)
--gỡ bảng 
DROP TABLE HocSinh

--Xoa du lieu
truncate table HocSinh

ALTER TABLE HocSinh ADD NgaySinh Date
