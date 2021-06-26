create database data;
use data;

create table Sections(id INT NOT NULL PRIMARY KEY,name VARCHAR(255) NOT NULL);
insert into Sections(id,name) values(1,"Developer"),(2,"Web Designer"),(3,"Manager");

create table Actives(id INT NOT NULL PRIMARY KEY,name VARCHAR(255) NOT NULL,surname VARCHAR(255) NOT NULL,s_id INT NOT NULL,FOREIGN KEY(s_id) REFERENCES Sections(id));
insert into Actives(id,name,surname,s_id) values(1,"Ani","Darbinyan",2),(2,"Hakop","Axajanyan",1),(3,"Armen","Meliqyan",1),(4,"Meri","Minasyan",3),(5,"Samvel","Sahakyan",2);

create table Projects(id INT NOT NULL PRIMARY KEY,name VARCHAR(255) NOT NULL);
insert into Projects(id,name) values(1,"Site"),(2,"art. intelligence"),(3,"Excel"),(4,"Web Server");

create table Proj_Act(p_id iNT NOT NULL,a_id INT NOT NULL,Work_Date_start VARCHAR(255) NOT NULL,Work_Date_end VARCHAR(255),Time INT NOT NULL);
insert into Proj_Act(p_id,a_id,Work_Date_start,Work_Date_end,Time) values(1,1,"23.06.2021","25.06.2021",7),(1,5,"23.06.2021","24.06.2021",4),(1,3,"23.06.2021","24.06.2021",5),(2,2,"20.06.2021","26.06.2021",23),(2,3,"20.06.2021","NULL",42),(3,4,"24.06.2021","25.06.2021",10),(4,1,"23.06.2021","25.06.2021",6),(4,2,"23.06.2021","26.06.2021",7),(4,5,"23.06.2021","25.06.2021",2);

select Projects.id as Projects_id,Projects.name as Projects_name,Actives.name as Active_name,Actives.surname as Active_surname from Projects inner join Actives inner join Proj_Act where Projects.id = Proj_Act.p_id and Actives.id = Proj_Act.a_id;

select p_id as Project_id, sum(Time) as Time from Proj_Act GROUP BY p_id;

select id,name as project,Work_Date_start,Time from Projects inner join Proj_Act where Projects.id = Proj_Act.p_id and Proj_Act.Work_Date_end = "NULL";

drop database data;