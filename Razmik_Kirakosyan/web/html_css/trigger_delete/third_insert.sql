create database human;
use human;
create table person (id int not null, person_name varchar(255) not null, person_surname varchar(255) not null);

delimiter //
create trigger changing_third_insert
before insert
on person for each row
    if ((select count(*) from person) +1) % 3 = 0
        then set new.id = 0, new.person_name = "***", new.person_surname = "!!!";  
    end if;//

 delimiter ;   
    
insert into person (id, person_name, person_surname) values (1, "Tom", "Hanks");
insert into person (id, person_name, person_surname) values (2, "Will", "Smith");
insert into person (id, person_name, person_surname) values (3, "Johnny", "Depp");
insert into person (id, person_name, person_surname) values (4, "Jon", "Travolta");
insert into person (id, person_name, person_surname) values (5, "Antony", "hopkins");
insert into person (id, person_name, person_surname) values (6, "Leo", "di Caprio");
insert into person (id, person_name, person_surname) values (7, "JDwayne", "Jonson");

select * from person;


drop database human;
