create database employees;
use employees;
create table unit (id int not null, unit_name varchar(255) not null, primary key (id));
insert into unit (id, unit_name) values (1, "programming");
insert into unit (id, unit_name) values (2, "architecture");
insert into unit (id, unit_name) values (3, "design");
insert into unit (id, unit_name) values (4, "movie");
insert into unit (id, unit_name) values (5, "gaming");
insert into unit (id, unit_name) values (7, "agriculture");
insert into unit (id, unit_name) values (8, "photography");
insert into unit (id, unit_name) values (9, "animation");
insert into unit (id, unit_name) values (10, "economics");
insert into unit (id, unit_name) values (11, "art");

create table employee (id int not null, emp_name varchar(255) not null,emp_surname varchar(255) not null, unit_id int not null, primary key(id), foreign key(unit_id) references unit(id));
insert into employee (id, emp_name, emp_surname, unit_id) values (1, "Artak", "Vardanyan", 1);
insert into employee (id, emp_name, emp_surname, unit_id) values (2, "Narek", "Petrosyan", 4);
insert into employee (id, emp_name, emp_surname, unit_id) values (3, "Vardges", "Parsadanyan",7);
insert into employee (id, emp_name, emp_surname, unit_id) values (4, "Arman", "Sargsyan", 5);
insert into employee (id, emp_name, emp_surname, unit_id) values (5, "Armine", "Sahakyan", 2);

create table project (id int not null, project_name varchar(255) not null, project_status varchar(255) not null, primary key(id));
insert into project (id, project_name, project_status ) values (1, "second_project", "finished");
insert into project (id, project_name, project_status) values  (2, "first_project", "not finished");
insert into project (id, project_name, project_status ) values (3, "third_project", "not finished");
insert into project (id, project_name, project_status) values  (4, "fourth_project", "not finished");
insert into project (id, project_name, project_status) values  (5, "fifth_project", "finished");

create table project_employee(p_id int not null, emp_id int not null, pr_start datetime, pr_end datetime, foreign key (p_id) references project(id), foreign key (emp_id) references employee(id));
insert into project_employee(p_id,emp_id, pr_start, pr_end) values (1,1, "2021-06-21  15:27:09", "2021-07-24 17:00:00");
insert into project_employee(p_id,emp_id, pr_start, pr_end) values (1,2, "2021-06-17  00:15:27", null);
insert into project_employee(p_id,emp_id, pr_start, pr_end) values (1,3, "2021-06-16  02:17:00", null);
insert into project_employee(p_id,emp_id, pr_start, pr_end) values (2,4, "2021-06-22  23:10:00", null);
insert into project_employee(p_id,emp_id, pr_start, pr_end) values (3,5, "2021-06-10 15:10:00","2021-06-21  13:25:00");





select * from unit;
select * from employee;
select * from project;
select * from project_employee;

select project.id, project.project_name, employee.emp_name, emp_surname  
from 
    project_employee INNER JOIN
    employee INNER JOIN
    project ON project_employee.emp_id = employee.id
    and project_employee.p_id = project.id;

select count(*) from project where project.project_status="not finished";
select p_id,  sum(time_format(timediff(ifnull(pr_end, now()), pr_start),'%H,:%i:%s')) from project_employee group by p_id;




drop database employees;