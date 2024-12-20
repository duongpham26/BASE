﻿USE HowKteam
GO

SELECT GIAOVIEN.MAGV, HOTEN, TEN FROM dbo.GIAOVIEN, dbo.NGUOITHAN
WHERE GIAOVIEN.MAGV = NGUOITHAN.MAGV

-- Lấy ra giáo viên nhỏ 60 tuổi
SELECT HOTEN, NGSINH, YEAR(GETDATE()) - YEAR(NGSINH) AS Tuoi FROM dbo.GIAOVIEN
WHERE YEAR(GETDATE()) - YEAR(NGSINH) < 60

-- Lấy ra giao viên là trưởng bộ môn
SELECT * FROM GIAOVIEN, BOMON
WHERE GIAOVIEN.MAGV = BOMON.TRUONGBM

-- Đếm số lượng giáo viên có mã là 007
-- COUNT(*) đếm có bao nhiều trường 
-- COUNT(TEN TRUONG) đếm có bao nhiêu trường đó 
SELECT * FROM GIAOVIEN
SELECT COUNT(HOTEN) AS TEN FROM GIAOVIEN
WHERE PHAI = N'Nữ'

SELECT COUNT(*) AS 'SO LUONG NGUOI THAN CUA 007' FROM GIAOVIEN, NGUOITHAN
WHERE GIAOVIEN.MAGV = '007' AND GIAOVIEN.MAGV = NGUOITHAN.MAGV

-- Truy vấn giáo viên và tên đề tài tham gia
SELECT * FROM GIAOVIEN
SELECT * FROM DETAI
SELECT * FROM THAMGIADT
SELECT HOTEN, TENDT FROM GIAOVIEN, DETAI, THAMGIADT
WHERE GIAOVIEN.MAGV = THAMGIADT.MAGV AND THAMGIADT.MADT = DETAI.MADT


--*******************************
-- truy vấn và xem giao viến đó đã tham gia đề tài đó bao nhiên lần???? 