create database work;
use work;


CREATE TABLE department (
  dno int NOT NULL auto_increment,
  dname varchar(45) NOT NULL,
  PRIMARY KEY (dno)
) ;


create table employee(
id int auto_increment not null,
name varchar(40) not null,
dep_id int not null,
primary key(id),
foreign key (dep_id) references department(dno)
);

create table project(
    id int auto_increment not null,
    p_name varchar(40) not null,
    status varchar(45) NOT NULL,
    pstart date DEFAULT NULL,
    pfinal date DEFAULT NULL,
    primary key(id)
);

create table work_on_project
(
    proj_id int not null,
    empl_id int not null,
    foreign key (proj_id) references project (id),
    foreign key (empl_id) references employee (id)
);

INSERT INTO department(dname) VALUES( 'System Admin');
INSERT INTO department( dname) VALUES( 'Marketing');
INSERT INTO department(dname) VALUES( 'Finance');
INSERT INTO department( dname) VALUES('Production');
INSERT INTO department( dname) VALUES( 'Development');
INSERT INTO department(dname) VALUES( 'Sales');

insert into employee (name, dep_id) values
('Jane', 1),
('Kate', 2),
('Tom', 4),
('Mary', 3),
('Ann', 5);

insert into project(p_name, status, pstart, pfinal) values 
('Bigfish', 'passive', '2021-05-02 18:15:12', '2021-06-05 18:12:33'),
('Cascade', 'passive', '2021-07-03 17:12:20', '2021-07-08 14:23:45'),
('Cheerio', 'passive', '2021-09-07 12:03:15', '2021-09-30 14:15:03'),
('Cinnamon', 'active', '2021-05-08 15:05:20', CURRENT_TIMESTAMP()),
('Project', 'active', '2021-05-08 15:05:20', null)
;

insert into work_on_project (proj_id, empl_id) values 
(1,5),
(1,4),
(1,2),
(2,1);

select work_on_project.proj_id,  project.p_name, employee.name from work_on_project 
inner join project on  project.id = work_on_project.proj_id
inner join employee on employee.id = work_on_project.empl_id  where proj_id = 1;

select   work_on_project.proj_id, work_on_project.empl_id, project.p_name,  employee.name, timediff(pfinal, pstart)
  from work_on_project  inner join  project on project.id =work_on_project.proj_id
  inner join employee on employee.id = work_on_project.empl_id;

  select id, p_name, status from project where status= "active";

drop table work_on_project;
drop table employee;
drop table project;
drop database work;
