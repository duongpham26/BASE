USE HowKteam
GO

CREATE PROCEDURE TESTPR @MAGV CHAR(10) AS SELECT * FROM GIAOVIEN WHERE MAGV = @MAGV
GO

DROP PROCEDURE TESTPR;
GO

EXECUTE TESTPR @MAGV = '001'
EXEC TESTPR '001'