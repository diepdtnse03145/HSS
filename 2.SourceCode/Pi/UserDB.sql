-- Tao database voi 3 cot: ID, User, Password --
Create table UserDB (ID int(11), User Char(64), Password Char(64) ) ;
Insert into UserDB (id,user,password) -- add thong tin cua user vao database --
values (1,'Tom Cat','1234'); -- id = 1, user = Tom Cat, password = 1234 --
Insert into UserDB (id,user,password)
values (2,'Hung','5678');
Insert into UserDB (id,user,password)
values (3,'Cuong','abcd');
select * from UserDB; -- lay database ra output --
SELECT COUNT(User) FROM UserDB -- dem so luong user co ten user la "Hung" --
WHERE User="Hung";


SELECT COUNT(*) FROM HSS_USER WHERE ID = 'DiepDTN' AND PW = 'MoeMoe'
UPDATE HSS_USER SET PW = 'moe' WHERE ID = 'DiepDTN2'
