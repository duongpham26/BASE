﻿USE HowKteam
GO

/**
-- Nếu có nhu cầu duyệt từng phần tử của bảng và tường phần tử có cách sử lý riêng 
-- CÁCH DÙNG --
-- DECLARE <TÊN CON TRỎ> CURSOR FOR <CÂU SELECT>
-- OPEN <TÊN CON TRỎ> 
-- FETCH NEXT FROM <TÊN CONTROR> INTO <DANH SÁCH BIẾN TUONG ỨNG KẾT QUẢ TRUY VẤN>
-- CLOSE <TÊN CON TRỎ>
-- DEALLOCATE <CURSOR NAME>
*/
SELECT *, YEAR(GETDATE()) - YEAR(NGSINH)FROM GIAOVIEN

DECLARE GiaoVienCursor CURSOR FOR SELECT MAGV, YEAR(GETDATE()) - YEAR(NGSINH) FROM GIAOVIEN
DECLARE @MAGV CHAR(10)
DECLARE @TUOI INT

OPEN GiaoVienCursor

FETCH NEXT FROM GiaoVienCursor INTO @MAGV, @TUOI
WHILE @@FETCH_STATUS = 0
BEGIN
	IF @TUOI > 40
	BEGIN 
		UPDATE GIAOVIEN SET LUONG = 2500 WHERE MAGV = @MAGV
	END
	ELSE 
	IF @TUOI > 30
	BEGIN
		UPDATE GIAOVIEN SET LUONG = 2000 WHERE MAGV = @MAGV
	END
	FETCH NEXT FROM GiaoVienCursor INTO @MAGV, @TUOI
END

CLOSE GiaoVienCursor
DEALLOCATE GiaoVienCursor