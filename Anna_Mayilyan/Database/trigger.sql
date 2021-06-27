create database stud;
use stud;

CREATE TABLE    department    (
    id   INT(10)  NOT NULL AUTO_INCREMENT,
    dept_name   VARCHAR(50) NOT NULL,
    PRIMARY KEY(id)
) ;

CREATE TABLE    student    (
     id    INT(10)  NOT NULL AUTO_INCREMENT ,
     stud_name    VARCHAR(30) NOT NULL,
     stud_dept    int NOT NULL,
     PRIMARY KEY(id),
  FOREIGN KEY (   stud_dept   ) REFERENCES    department    (  id   )
) ;

INSERT INTO department (dept_name) VALUES
  ("Computer Science"),
  ("Economics"),
  ("Art"),
  ("Business"),
  ("Music"),
  ("Math"),
  ("Statistics");

INSERT INTO student ( stud_name ,  stud_dept) VALUES
  ( "Mary", 1),
  ( "Kate",  1),
  ( "Mike", 1),
  ("Tom", 2),
  ( "Jake",  5);

select * from student;
select * from department;

CREATE TRIGGER delete_related_info BEFORE DELETE ON department FOR EACH ROW delete from student where student.stud_dept = OLD.id;

Delete from department where id = 1;
select * from student;
select * from department;

DELIMITER //
CREATE TRIGGER change before insert ON student
FOR EACH ROW 
if  new.id mod 2 = 0 then set   new.stud_name = 'student' ; end if;
//
DELIMITER ;

select * from student;
INSERT INTO student ( stud_name ,  stud_dept) VALUES ( "John 2", 5);

select * from student;
drop table student;
drop table department;
drop database stud;
