﻿USE HowKteam
GO


SELECT * FROM dbo.BOMON

SELECT MABM, TENBM FROM dbo.BOMON

-- Đổi tên hiển thị
SELECT MABM AS 'Ma Bo Mon' FROM DBO.BOMON

SELECT BOMON.MABM, MAGV, TENBM FROM dbo.BOMON, dbo.GIAOVIEN