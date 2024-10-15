USE HowKteam
GO

-- inner join kieu cu
SELECT * FROM dbo.BOMON, dbo.GIAOVIEN
WHERE GIAOVIEN.MABM = BOMON.MABM


-- nên viết kiểu này, kiểu mới và đúng chuẩn (giống a giao b) ( INNER JOIN  + ON = JOIN + ON)
SELECT * FROM dbo.GIAOVIEN INNER JOIN dbo.BOMON 
ON BOMON.MABM = GIAOVIEN.MABM