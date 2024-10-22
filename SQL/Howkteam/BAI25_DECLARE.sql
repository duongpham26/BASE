USE HowKteam
GO

--PROBLEM--------------------------------------------
-- tìm ra mã giao viên có lương thấp nhất
SELECT MAGV FROM GIAOVIEN
WHERE LUONG = (SELECT MIN(LUONG) FROM GIAOVIEN)

-- lấy ra tuỏi giáo viên có lương thấp nhất 
SELECT YEAR(GETDATE()) - YEAR(NGSINH) FROM GIAOVIEN
WHERE MAGV = (SELECT MAGV FROM GIAOVIEN WHERE LUONG = (SELECT MIN(LUONG) FROM GIAOVIEN))

--solution-------------------------------------------
DECLARE @MinSalaryMGV char(10)
SELECT @MinSalaryMGV = MAGV FROM GIAOVIEN WHERE LUONG = (SELECT MIN(LUONG) FROM GIAOVIEN)

SELECT YEAR(GETDATE()) - YEAR(NGSINH) FROM GIAOVIEN WHERE MAGV =  @MinSalaryMGV

-----------------------------------------------------------------
--khởi tạo
DECLARE @I INT
DECLARE @J INT = 0

-- SET GIA TRI
SET @I += 1
SET @I = @J



-- EXAMPLES-------------------------------------------------
-- 1. Xuất ra số lương người thân của giao viên 001
-- Lưu mã giao viên 001
-- tìm ra số lượng người thân tương ứng mã giaovien 

SELECT GIAOVIEN.MAGV, COUNT(*) FROM GIAOVIEN, NGUOITHAN
WHERE GIAOVIEN.MAGV = NGUOITHAN.MAGV
GROUP BY GIAOVIEN.MAGV

DECLARE @MGV CHAR(10) = '001'
SELECT COUNT(*) FROM NGUOITHAN
WHERE NGUOITHAN.MAGV = @MGV


-- 2. xuất tên giáo viên thấp nhất 
DECLARE @MINLUONG INT
DECLARE @TENGIAOVIEN NVARCHAR(100)

SELECT @MINLUONG = MIN(LUONG) FROM GIAOVIEN
SELECT @TENGIAOVIEN = HOTEN FROM GIAOVIEN WHERE LUONG = @MINLUONG

PRINT @TENGIAOVIEN
