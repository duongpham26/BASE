﻿-- copy dữ liệu vào bảng đã tồn tại

USE HowKteam
GO

SELECT * INTO TABLECLONE FROM dbo.GIAOVIEN
WHERE 1 = 0

INSERT INTO TABLECLONE SELECT * FROM DBO.GIAOVIEN

SELECT * FROM TABLECLONE