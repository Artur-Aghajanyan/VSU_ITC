create database data;
use data;

create table Sections(id INT NOT NULL PRIMARY KEY,name VARCHAR(255) NOT NULL);
insert into Sections(id,name) values(1,"Developer"),(2,"Web Designer"),(3,"Manager");

create table Actives(id INT NOT NULL PRIMARY KEY,name VARCHAR(255) NOT NULL,surname VARCHAR(255) NOT NULL,s_id INT NOT NULL,FOREIGN KEY(s_id) REFERENCES Sections(id));
insert into Actives(id,name,surname,s_id) values(1,"Ani","Darbinyan",2),(2,"Hakop","Axajanyan",1),(3,"Armen","Meliqyan",1),(4,"Meri","Minasyan",3),(5,"Samvel","Sahakyan",2);

create table Projects(id INT NOT NULL PRIMARY KEY,name VARCHAR(255) NOT NULL);
insert into Projects(id,name) values(1,"Site"),(2,"art. intelligence"),(3,"Excel"),(4,"Web Server");

create table Proj_Act(p_id iNT NOT NULL,a_id INT NOT NULL,Work_Date_start DATETIME NOT NULL,Work_Date_end DATETIME);
insert into Proj_Act(p_id,a_id,Work_Date_start,Work_Date_end) values(1,1,"2021-06-23 14:02:00","2021-06-28 16:20:00"),(1,5,"2021-06-22 12:00:00","2021-06-25 12:00:00"),(1,3,"2021-06-22 23:10:00","2021-06-28 16:20:00"),(2,2,"2021-06-19 11:00:00","2021-06-25 20:20:00"),(2,3,"2021-06-23 09:05:00",NULL),(3,4,"2021-06-27 14:05:00","2021-06-28 23:50:00"),(4,1,"2021-06-20 14:00:00","2021-06-24 16:40:00"),(4,2,"2021-06-23 14:00:00","2021-06-24 16:47:00"),(4,5,"2021-06-23 17:02:00","2021-06-28 17:00:00");

select Projects.id as Projects_id,Projects.name as Projects_name,Actives.name as Active_name,Actives.surname as Active_surname from Projects inner join Actives inner join Proj_Act where Projects.id = Proj_Act.p_id and Actives.id = Proj_Act.a_id;

select p_id as project_id, sum(time_format(timediff(ifnull(Work_Date_end,now()),Work_Date_start),'%H:%i:%s')) / 3 as Time from Proj_Act GROUP BY p_id;

select id,name as project,Work_Date_start from Projects inner join Proj_Act where Projects.id = Proj_Act.p_id and Proj_Act.Work_Date_end is NULL;

drop database data; 
