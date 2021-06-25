create database Trigger;
use Trigger;

create table a (
  id int not null,
  name varchar(255),
  surname varchar(255),
  age int not null,
  primary key(id)
);

create table b (
  id int not null,
  aid int not null,
  height int not null,
  foreign key(aid) references a(id)
);

insert into a 
values (1, 'A1', 'B1', 56),
       (2, 'A2', 'B2', 29),
       (3, 'A3', 'B3', 4), 
       (4, 'A4', 'B4', 73);

insert into b
values (1, 2, 180),
       (2, 4, 170), 
       (3, 3, 100), 
       (4, 1, 175);

select * from a;
select * from b;

delimiter //
create trigger aa
after delete
  on b for each row
begin
    delete from a
    where a.id = old.aid;
end//
  
delimiter ;
  
delete from b
where id = 1;

select * from a;
select * from b;

create table c (
  id int not null,
  name varchar(255),
  surname varchar(255)
);

delimiter //
create trigger cc
before insert
  on c for each row
begin
    if new.id % 3 = 0 then
      set new.name = "bzz";
    end if;
end//
  
delimiter ;

insert into c
values (1, 'C1', 'D1'),
       (2, 'C2', 'D2'), 
       (3, 'C3', 'D3'), 
       (4, 'C4', 'D4'), 
       (5, 'C5', 'D5'), 
       (6, 'C6', 'D6');

select * from c;
