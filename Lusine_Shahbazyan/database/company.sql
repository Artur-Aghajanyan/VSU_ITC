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
    empl_id int not null,
    projectName varchar(20),
    projStatus boolean,
    startDate DATETIME,
    foreign key(empl_id) references Employees(id)
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

insert into Projects(projectName, projStatus, startDate, empl_id) values
    ('market', true, "2021-06-25 13:10:11", 1),
    ('tourCompany', false, "2021-06-10 12:15:11", 3),
    ('bookinist', true, "2021-06-12 15:05:11", 2),
    ('onlineSchool', true, "2021-06-20 16:45:11", 1),
    ('Market', true, "2021-06-25 13:10:11", 2),
    ('tourCompany', false, "2021-06-10 12:15:11", 3),
    ('bookinist', true, "2021-06-12 15:05:11", 4),
    ('onlineSchool', true, "2021-06-01 16:45:11", 5),
    ('fasebook', false, "2021-05-03 17:20:11", 5),
    ('fasebook', false, "2021-05-03 17:20:11", 5);


/* Employees working on the project 'bookinist' */
select Employees.name, Employees.surname, Projects.projectName
    from Employees 
    inner join  Projects  where Employees.id = Projects.empl_id and Projects.id = 3;

/* The time spent on program */
select timediff(CURRENT_TIMESTAMP(), Projects.startDate) 
    as "Working time of Ani Andreasyan on program 'onlineSchool'"
    from Projects where Projects.id = 4;

/* Active projects */
select * from Projects where Projects.projStatus = true;

drop Table Projects;
drop Table Employees;
drop Table Categories;
drop database Company; 