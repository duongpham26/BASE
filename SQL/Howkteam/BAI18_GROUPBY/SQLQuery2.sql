USE HowKteam
GO

-- xuất ra danh sách tên bộ môn và số lượng giáo viên của bộ môn đó
SELECT BOMON.MABM, COUNT(*) FROM dbo.GIAOVIEN, DBO.BOMON
WHERE GIAOVIEN.MABM = BOMON.MABM
GROUP BY BOMON.MABM

-- lấy ra danh sách giao viên có lương lớn hơn lương tb của giáo viên 
SELECT * FROM dbo.GIAOVIEN 
WHERE LUONG > (SELECT SUM(lUONG) FROM dbo.GIAOVIEN )/ (SELECT COUNT(MAGV) FROM DBO.GIAOVIEN)

-- xuất ra giao viên và số lượng đề tài 

/*
bt1. Xuất ra tên giáo viên và số lượng người thân của giao viên đó
bt2. xuất ra tên giáo viên và số lượng đề tài đã hoàn thành mà giáo viên đó tham gia
bt3. xuất ra tên khoa có tổng số lương của giao viên trong khóa là lớn nhất 
*/

--bt1 
SELECT GIAOVIEN.HOTEN, COUNT(GIAOVIEN.MAGV) AS 'HH' FROM dbo.GIAOVIEN, dbo.NGUOITHAN
WHERE GIAOVIEN.MAGV = NGUOITHAN.MAGV
GROUP BY GIAOVIEN.MAGV, GIAOVIEN.HOTEN

--BT2
SELECT GIAOVIEN.MAGV, COUNT(*) AS 'SO LUONG DA HOANG THANH' FROM dbo.GIAOVIEN, DBO.THAMGIADT
WHERE GIAOVIEN.MAGV = THAMGIADT.MAGV AND THAMGIADT.KETQUA = N'Đạt'
GROUP BY GIAOVIEN.MAGV

-- BT3 ??
SELECT MAXSL.MAKHOA, MAX(MAXSL.SL) FROM (SELECT KHOA.MAKHOA, KHOA.TENKHOA, COUNT(*) AS SL FROM dbo.GIAOVIEN, dbo.BOMON, dbo.KHOA
WHERE GIAOVIEN.MABM = BOMON.MABM AND BOMON.MAKHOA = KHOA.MAKHOA
GROUP BY KHOA.MAKHOA, KHOA.TENKHOA) AS MAXSL



