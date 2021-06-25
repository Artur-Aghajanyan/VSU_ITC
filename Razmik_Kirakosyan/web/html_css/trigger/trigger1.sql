create database art;
use art;
create table painters (id int not null, painter_name varchar(255),painter_surname varchar(255),primary key(id));
insert into painters (id, painter_name, painter_surname) values (1, "Martiros", "Saryan");
insert into painters (id, painter_name, painter_surname) values (2, "Vardges", "Surenyants");
insert into painters (id, painter_name, painter_surname) values (3, "Gevorg",  "Bashinjaghyan");
insert into painters (id, painter_name, painter_surname) values (4, "Arshil", "Gorki");
insert into painters (id, painter_name, painter_surname) values (5, "Minas", "Avetisyan");

create table paintings (id int not null, painting_name varchar(255), p_id int not null,foreign key(p_id) references painters(id));
insert into paintings (id, painting_name, p_id) values (1, "Hayastan", 1);
insert into paintings (id, painting_name, p_id) values (2, "Salome", 2);
insert into paintings (id, painting_name, p_id) values (3, "Aravoty Sevanum", 3);
insert into paintings (id, painting_name, p_id) values (4, "Nkarichn u Mayry", 4);
insert into paintings (id, painting_name, p_id) values (5, "Jajur", 5);

select * from  painters;
select * from  paintings;

CREATE TRIGGER deleteing 
    BEFORE DELETE ON painters 
    FOR EACH ROW DELETE FROM paintings
        where paintings.p_id=old.id;
delete from painters where id=1;
select * from  painters;
select * from  paintings;

drop database art;