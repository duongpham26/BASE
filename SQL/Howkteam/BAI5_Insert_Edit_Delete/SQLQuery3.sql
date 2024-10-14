

CREATE TABLE test 
(
	Id int,
	ten nvarchar(30),
	BirthDay date,
	Sex bit,
)

--DROP TABLE test

INSERT test --(Id, ten, BirthDay, Sex)
VALUES (21200376, N'Pham', '20020510', 1)


DELETE test WHERE Id = 21200375

UPDATE test SET Id = 1


UPDATE test set ten = N'DuongPham' WHERE Id = 21200376 
