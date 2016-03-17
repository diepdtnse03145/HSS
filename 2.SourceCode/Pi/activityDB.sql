Create table ActivityDB (Time time, Pushmessage char(100)) ; /*create database*/
Insert into ActivityDB (time, pushmessage)				/*add data to database*/
values ('01:23','Someone has pressed the doorbell');
select * from ActivityDB; /*show database/*
