USE HowKteam
GO



DECLARE @LUONGTRUNGBINH INT 
DECLARE @SOLUONGGIAOVIEN INT

SELECT @LUONGTRUNGBINH = AVG(LUONG) FROM GIAOVIEN
SELECT @SOLUONGGIAOVIEN = COUNT(*) FROM GIAOVIEN
PRINT @LUONGTRUNGBINH
PRINT @SOLUONGGIAOVIEN

DECLARE @MAGV char(10)= '001'
DECLARE @LuongMaGV int = 0

SELECT @LuongMaGV = LUONG FROM GIAOVIEN WHERE MAGV = @MAGV

IF @LuongMaGV > @LUONGTRUNGBINH
BEGIN
	PRINT 'LON HON'
	PRINT @LUONGTRUNGBINH
	PRINT @LuongMaGV
END
ELSE
BEGIN
	PRINT 'NHO HON'
	PRINT @LUONGTRUNGBINH
	PRINT @LuongMaGV
END