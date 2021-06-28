create database Company;
Use Company;

create Table Categories(
    id int not null auto_increment primary key,
    categName varchar(20)
);

create Table Employees(
    id int not null auto_increment primary key,
    name varchar(20),
    surname varchar(20),
    categ_id int,
    foreign key(categ_id) references Categories(id)
);

create Table Projects(
    id int not null auto_increment primary key,
    projectName varchar(20),
    projStatus boolean,
    startDate DATETIME,
    endDate DATETIME
);
create Table Employee_project(
    emp_id int, 
    prj_id int,
    foreign key (emp_id) references Employees(id),
    foreign key (prj_id) references Projects(id)
);

insert into Categories(categName) values
    ("front_end"),
    ("back_end");

insert into Employees(name, surname, categ_id) values
    ('Ani', 'Andreasyan', 1),
    ('Meri', 'Araqelyan', 1),
    ('Ashot', 'Poxosyan', 2),
    ('Aren', 'Caturyan', 1),
    ('Marine', 'Davtyan', 2);

insert into Projects(projectName, projStatus, startDate, endDate) values
    ('taxservice', true, "2021-06-25 13:10:11", CURRENT_TIMESTAMP()),
    ('tourCompany', false, "2021-06-10 12:15:11", "2021-06-18 13:10:11"),
    ('bookinist', false, "2021-06-12 15:05:11", "2021-06-16 13:10:11"),
    ('onlineSchool', true, "2021-06-25 16:45:11", CURRENT_TIMESTAMP());

insert into Employee_project(emp_id, prj_id) values
    (1, 1),
    (1, 4),
    (2, 2),
    (2, 3),
    (2, 4),
    (3, 3),
    (3, 3),
    (4, 1),
    (4, 3),
    (4, 4);

/* Employees working on the project 'taxservice' */
select Employee_project.prj_id, Projects.projectName, Employees.name, Employees.surname
    from  Employee_project  
    inner join  Projects on Projects.id = Employee_project.prj_id
    inner join Employees on Employees.id = Employee_project.emp_id
    where Projects.id = 1;

/* The time spent on program */
select timediff(Projects.endDate, Projects.startDate) 
    as "Working time  on program 'onlineSchool'"
    from Projects where Projects.id = 4;

/* Active projects */
select * from Projects where Projects.projStatus = true;

drop Table Employee_project;
drop Table Projects;
drop Table Employees;
drop Table Categories;
drop database Company; 