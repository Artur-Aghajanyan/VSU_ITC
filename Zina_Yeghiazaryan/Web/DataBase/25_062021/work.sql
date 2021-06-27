create database Work;
use Work;

create table department (
  id int not null,
  primary key(id)
);

create table project (
  id int not null,
  isActive varchar(3),
  primary key(id)
);

create table worker (
  id int not null,
  did int not null,
  pid int not null,
  name varchar(255),
  surname varchar(255),
  start_date datetime,
  primary key(id),
  foreign key(did) references department(id),
  foreign key(pid) references project(id)
);

insert into department
values (1),
       (2),
	     (3),
	     (4);

insert into worker
values (1, 1, 3, 'Lusine', 'Stepanyan', '2021-05-20 09:00:00'),
       (2, 1, 2, 'Artyom', 'Harutunyan', '2021-05-20 09:00:00'),
	     (3, 1, 1, 'Eliza', 'Harutunyan', '2021-04-01 09:00:00'),
	     (4, 1, 3, 'Gor', 'Harutunyan', '2021-05-30 09:00:00'),
	     (5, 2, 1, 'Anna', 'Xachatryan', '2021-04-01 09:00:00'),
	     (6, 2, 1, 'Artur', 'Soxikyan', '2021-04-01 09:00:00'),
	     (7, 3, 2, 'Margarita', 'Pozlikyan', '2021-05-20 09:00:00'),
	     (8, 3, 1, 'Ani', 'Abovyan', '2021-04-01 09:00:00'),
	     (9, 3, 3, 'Karen', 'Xechumyan', '2021-05-30 09:00:00'),
	     (10, 4, 2, 'Anjela', 'Matinyan', '2021-05-20 09:00:00'),
	     (11, 4, 3, 'Norayr', 'Amirxanyan', '2021-05-30 09:00:00'),
	     (12, 4, 1, 'Eduarda', 'Markosyan', '2021-04-01 09:00:00'),
	     (13, 4, 2, 'Nikolay', 'Voskanyan', '2021-05-20 09:00:00');
	   
insert into project
values (1, 'yes'),
       (2, 'yes'),
       (3, 'no');
	   
select project.id, worker.name, worker.surname
from project inner join worker
on project.id = 1 and project.id = worker.pid;

select sum(time_format(timediff(CURRENT_TIMESTAMP(), worker.start_date ),'%H:%i:%s') - 24 * time_format(timediff(CURRENT_TIMESTAMP(), worker.start_date ),'%H:%i:%s') / 84 - 15 * (time_format(timediff(CURRENT_TIMESTAMP(), worker.start_date ),'%H:%i:%s') - 24 * time_format(timediff(CURRENT_TIMESTAMP(), worker.start_date ),'%H:%i:%s') / 84) / 24)
from project inner join worker where project.id = 2 and project.id = worker.pid;

select count(isActive) from project where project.isActive = 'yes';
