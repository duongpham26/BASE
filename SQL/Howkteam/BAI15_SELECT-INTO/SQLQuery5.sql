﻿-- Tạo bảng trên dữ liệu bảng đã có sẵn

USE HowKteam
GO

SELECT * INTO TABLEA FROM dbo.GIAOVIEN

SELECT HOTEN INTO TABLEB FROM dbo.GIAOVIEN
WHERE LUONG > 2000
SELECT * FROM TABLEB

SELECT MAGV, HOTEN, TENBM INTO TABLEC FROM dbo.GIAOVIEN, dbo.BOMON
WHERE GIAOVIEN.MABM = BOMON.MABM

SELECT * FROM TABLEC

SELECT * INTO TABLED FROM dbo.GIAOVIEN
WHERE 1>2