
CREATE TABLE TestPrimayKey 
(
	ID int not null,
	FULL_NAME NVARCHAR(20),

	PRIMARY KEY(ID)
)

INSERT TestPrimayKey(ID, FULL_NAME)
VALUES(2, N'DUONGPHAM')

CREATE TABLE TestPrimayKey2 
(
	ID int not null,
	FULL_NAME NVARCHAR(20),
)

ALTER table TestPrimayKey2 ADD PRIMARY KEY(ID)


CREATE TABLE TestPrimayKey3
(
	ID int not null,
	FULL_NAME NVARCHAR(20) DEFAULT N'Phạm Thanh Dương',
)


INSERT TestPrimayKey3(ID)
VALUES (1)
ALTER table TestPrimayKey3 ADD CONSTRAINT key3 PRIMARY KEY(ID)