create database Stor;
use Stor;

create Table Customrs(
    id int not null auto_increment,
    name varchar(20),
    surname varchar(20),
    PRIMARY KEY(id)
);
create Table Orders(
    id int not null auto_increment,
    cust_id int not null,
    orderDate DATETIME,
    PRIMARY KEY(id),
    foreign key(cust_id) references Customrs(id)
);

insert into Customrs(name, surname) values
    ('Ani', 'Andreasyan'),
    ('Meri', 'Araqelyan'),
    ('Ashot', 'Poxosyan'),
    ('Alen', 'Stepanyan');

insert into Orders(cust_id, orderDate) values
    (1, CURRENT_TIMESTAMP()),
    (1, CURRENT_TIMESTAMP()),
    (2, CURRENT_TIMESTAMP()),
    (2, CURRENT_TIMESTAMP()),
    (3, CURRENT_TIMESTAMP()),
    (3, CURRENT_TIMESTAMP()),
    (4, CURRENT_TIMESTAMP());

select * from Customrs;
select * from Orders; 


create trigger deleteData
    before  delete on Customrs for each row
    delete from Orders where Orders.cust_id=OLD.id;

delete from Customrs where id=3;
select * from Customrs;
select * from Orders;  

delimiter //
create trigger actionInsert
    before insert on Customrs for each row 
        if ((select count(*) from Customrs) + 1) % 3 = 0 
        then set new.name='HELLO'; 
        end if;//
delimiter ;
    
insert into Customrs(name, surname) values
    ('Ani', 'Andreasyan'),
    ('Meri', 'Araqelyan'),
    ('Ashot', 'Poxosyan'),
    ('Alen', 'Stepanyan'),
    ('Ani', 'Andreasyan'),
    ('Meri', 'Araqelyan'),
    ('Ashot', 'Poxosyan'),
    ('Meri', 'Araqelyan'),
    ('Alen', 'Stepanyan');

select * from Customrs;   

drop Table Orders;
drop Table Customrs;
drop database Stor;
