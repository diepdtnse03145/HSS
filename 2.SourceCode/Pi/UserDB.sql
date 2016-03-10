Create table UserDB (ID int(11), User Char(64), Password Char(64) ) ;
Insert into UserDB (id,user,password)
values (1,'Tom Cat','1234');
Insert into UserDB (id,user,password)
values (2,'Hung','5678');
Insert into UserDB (id,user,password)
values (3,'Cuong','abcd');
select * from UserDB;
SELECT COUNT(User) FROM UserDB
WHERE User="Hung";


