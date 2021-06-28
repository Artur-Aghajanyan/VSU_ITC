create database Work;
use Work;

create table department (
    id int not null,
    primary key(id)
);

create table project (
    id int not null,
    isActive varchar(3),
    name varchar(40),
    primary key(id)
);

create table worker (
    id int not null,
    did int not null,
    name varchar(255),
    surname varchar(255),
    start_date datetime,
    primary key(id),
    foreign key(did) references department(id)
);

create table wp (
    wid int not null,
    pid int not null,
    foreign key(wid) references worker(id),
    foreign key(pid) references project(id)
);

create table date_time (
    date_ date,
    time_ int,
    pid int not null,
    foreign key(pid) references project(id)
);

insert into department
values (1),
       (2),
       (3),
       (4);
       
insert into worker
values (1, 1, 'Lusine', 'Stepanyan', '2021-05-20 09:00:00'),
       (2, 1, 'Artyom', 'Harutunyan', '2021-05-20 09:00:00'),
       (3, 1, 'Eliza', 'Harutunyan', '2021-04-01 09:00:00'),
       (4, 1, 'Gor', 'Harutunyan', '2021-05-30 09:00:00'),
       (5, 2, 'Anna', 'Xachatryan', '2021-04-01 09:00:00'),
       (6, 2, 'Artur', 'Soxikyan', '2021-04-01 09:00:00'),
       (7, 3, 'Margarita', 'Pozlikyan', '2021-05-20 09:00:00'),
       (8, 3, 'Ani', 'Abovyan', '2021-04-01 09:00:00'),
       (9, 3, 'Karen', 'Xechumyan', '2021-05-30 09:00:00'),
       (10, 4, 'Anjela', 'Matinyan', '2021-05-20 09:00:00'),
       (11, 4, 'Norayr', 'Amirxanyan', '2021-05-30 09:00:00'),
       (12, 4, 'Eduarda', 'Markosyan', '2021-04-01 09:00:00'),
       (13, 4, 'Nikolay', 'Voskanyan', '2021-05-20 09:00:00');
       
insert into project
values (1, 'yes', 'Bigfish'),
       (2, 'yes', 'Kascade'),
       (3, 'no', 'Chario');
       
insert into wp
values (1, 3),
       (1, 2),
       (2, 2),
       (2, 1),
       (2, 3),
       (3, 1),
       (3, 3),
       (4, 3),
       (4, 1),
       (5, 1),
       (5, 2),
       (5, 3),
       (6, 1),
       (6, 2),
       (7, 2),
       (7, 1),
       (8, 1),
       (8, 3),
       (9, 3),
       (9, 1),
       (9, 2),
       (10, 2),
       (10, 1),
       (11, 3),
       (11, 1),
       (11, 2),
       (12, 3),
       (12, 1),
       (13, 2);
       
insert into date_time
values ('2021-06-23', 8, 1),
       ('2021-06-23', 4, 1),
       ('2021-06-23', 5, 1),
       ('2021-06-24', 6, 1),
       ('2021-06-24', 2, 1),
       ('2021-06-24', 5, 1),
       ('2021-06-24', 7, 1),
       ('2021-06-24', 8, 1),
       ('2021-06-25', 4, 1),
       ('2021-06-25', 1, 1),
       ('2021-06-25', 3, 1),
       ('2021-06-25', 3, 1),
       ('2021-06-25', 6, 1),
       ('2021-06-25', 7, 1),
       ('2021-06-25', 4, 1),
       ('2021-06-25', 8, 1),
       ('2021-06-25', 8, 1),
       ('2021-06-25', 7, 1),
       ('2021-06-21', 8, 2),
       ('2021-06-21', 4, 2),
       ('2021-06-21', 5, 2),
       ('2021-06-22', 6, 2),
       ('2021-06-22', 2, 2),
       ('2021-06-22', 5, 2),
       ('2021-06-23', 7, 2),
       ('2021-06-23', 8, 2),
       ('2021-06-23', 4, 2),
       ('2021-06-23', 1, 2),
       ('2021-06-24', 3, 2),
       ('2021-06-24', 3, 2),
       ('2021-06-24', 6, 2),
       ('2021-06-24', 7, 2),
       ('2021-06-25', 4, 2),
       ('2021-06-25', 8, 2),
       ('2021-06-25', 2, 2),
       ('2021-06-25', 1, 2),
       ('2021-06-25', 4, 2),
       ('2021-06-25', 6, 2),
       ('2021-06-25', 5, 2),
       ('2021-06-25', 3, 2),
       ('2021-06-25', 8, 2),
       ('2021-06-21', 8, 3),
       ('2021-06-21', 4, 3),
       ('2021-06-22', 5, 3),
       ('2021-06-22', 6, 3),
       ('2021-06-22', 2, 3),
       ('2021-06-23', 5, 3),
       ('2021-06-23', 7, 3),
       ('2021-06-23', 8, 3),
       ('2021-06-23', 4, 3),
       ('2021-06-24', 1, 3),
       ('2021-06-24', 3, 3),
       ('2021-06-24', 3, 3),
       ('2021-06-24', 6, 3),
       ('2021-06-24', 7, 3),
       ('2021-06-25', 4, 3),
       ('2021-06-25', 8, 3),
       ('2021-06-25', 2, 3),
       ('2021-06-25', 1, 3),
       ('2021-06-25', 4, 3),
       ('2021-06-25', 6, 3),
       ('2021-06-25', 5, 3),
       ('2021-06-25', 3, 3),
       ('2021-06-25', 8, 3);

select count(isActive) from project where project.isActive = 'yes';

select wp.pid, project.name, worker.name, worker.surname
from wp inner join project
on project.id = wp.pid
inner join worker 
on worker.id = wp.wid
and pid = 1;

select sum(time_) 
from date_time inner join project 
where project.id = 1 and project.id = date_time.pid;

drop database Work;
