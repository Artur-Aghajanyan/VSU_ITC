create database job;
use job;

CREATE TABLE department (
  dno int NOT NULL auto_increment,
  dname varchar(45) NOT NULL,
  PRIMARY KEY (dno)
) ;

CREATE TABLE employee (
    eno int NOT NULL auto_increment,
    ename varchar(45) NOT NULL,
    dno int  NOT NULL,
    PRIMARY KEY (eno),
    FOREIGN KEY (dno) REFERENCES department (dno)
);

CREATE TABLE project (
    pno int NOT NULL auto_increment ,
    pname varchar(45) NOT NULL,
    statuss varchar(45) NOT NULL,
    pstart date DEFAULT NULL,
    pfinal date DEFAULT NULL,
    empl_id int not null,
    PRIMARY KEY (pno),
    FOREIGN KEY (empl_id) REFERENCES employee(eno)
);


INSERT INTO department(dname) VALUES( 'System Admin');
INSERT INTO department( dname) VALUES( 'Marketing');
INSERT INTO department(dname) VALUES( 'Finance');
INSERT INTO department( dname) VALUES('Production');
INSERT INTO department( dname) VALUES( 'Development');
INSERT INTO department(dname) VALUES( 'Sales');

INSERT INTO employee (ename,dno) Values
('Armen',1),
('Ani', 2),
('Aram', 3),
('Lilit', 4),
('Anna', 5),
('Karine',5)
;  

insert into project (pname, statuss, pstart, pfinal, empl_id) values
('Bigfish', 'passive', '2021-05-02 18:15:12', '2021-06-05 18:12:33', 1),
('Cascade', 'passive', '2021-07-03 17:12:20', '2021-07-08 14:23:45', 2),
('Cheerio', 'passive', '2021-09-07 12:03:15', '2021-09-30 14:15:03', 3),
('Cinnamon', 'active', '2021-05-08 15:05:20', CURRENT_TIMESTAMP(), 5),
('Project', 'active', '2021-05-08 15:05:20', CURRENT_TIMESTAMP(), 4);

select * from department;
select * from employee;
select * from project;

select employee.eno, employee.ename, employee.dno, department.dname, project.pno, project.pname  from employee
inner join department on department.dno = employee.dno
inner join project on project.empl_id =  employee.eno;



select project.pname, project.empl_id, employee.ename, timediff(pfinal, pstart)
  from project  inner join  employee on employee.eno = project.empl_id;

select pno, pname, statuss from project where statuss= "active";
drop table project;
drop table employee;
drop table department;


drop database job;


