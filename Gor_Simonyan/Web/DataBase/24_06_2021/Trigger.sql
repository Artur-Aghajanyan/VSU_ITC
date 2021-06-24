create database Trig;
use Trig;

create table table1(id1 INT NOT NULL PRIMARY KEY);

delimiter //
create trigger trig1 
    before delete on table1 for each row 
        begin 
            delete from table2 where table2.id2 = old.id1;
            delete from table3 where table3.id3 = old.id1;
        end //
create trigger trig2
    before insert on table1 for each row 
        if ((select count(*) from table1) + 1) % 3 = 0 then set new.id1 = new.id1 + 100; end if;//
delimiter ;

insert into table1(id1) values (1),(2),(3),(4),(5),(6);

create table table2(id2 INT NOT NULL,FOREIGN KEY(id2) REFERENCES table1(id1));
insert into table2(id2) values (1),(2);

create table table3(id3 INT NOT NULL,FOREIGN KEY(id3) REFERENCES table1(id1));
insert into table3(id3) values (4),(5);

select * from table1;
select * from table2;
select * from table3;

delete from table1 where id1 = 1;
delete from table1 where id1 = 5;

select * from table1;
select * from table2;
select * from table3;

drop database Trig;