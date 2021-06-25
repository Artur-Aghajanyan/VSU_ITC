create database Market;
use Market;

create table Customers (
  id int not null,
  name varchar(255),
  surname varchar(255),
  primary key(id)
);

create table Suppliers(
  id int not null,
  name varchar(255),
  surname varchar(255),
  primary key(id)
);

create table Goods(
  id int not null,
  sid int not null,
  count_of_goods int,
  product varchar(255),
  primary key(id),
  foreign key(sid) references Suppliers(id)
);

create table Orders(
  id int not null,
  cid int not null,
  gid int not null,
  date_of_order date not null,
  time_of_order time not null,
  delivered varchar(255) not null,
  price int not null,
  primary key(id),
  foreign key(cid) references Customers(id),
  foreign key(gid) references Goods(id)
);

create table OrderLines(
  id int not null,
  cid int not null,
  gid int not null,
  count_of_product int,
  primary key(id),
  foreign key(cid) references Customers(id),
  foreign key(gid) references Goods(id)
);

insert into Suppliers
values (1, "C1", "D1"),
       (2, "C2", "D2");
       
insert into Goods
values (1, 2, 50, "pizza"), 
       (2, 2, 50, "coca-cola"), 
       (3, 1, 50, "hamburger"), 
       (4, 2, 50, "fanta");
       
insert into Customers
values (1, "A1", "B1"),
       (2, "A2", "B2");
       
insert into OrderLines (id, cid, gid, count_of_product)
values (1, 1, 1, 2),
       (2, 1, 2, 4), 
       (3, 2, 3, 3);
       
insert into Orders
values (1, 1, 1, '2021-06-24', '11:55', 'delivered', 2000),
       (2, 1, 2, '2021-06-25', '13:14', 'not delivered', 800), 
       (3, 2, 3, '2021-06-25', '8:30', 'delivered', 2500);

select Customers.name, Customers.surname, Goods.product, OrderLines.count_of_product
from Customers inner join Goods
               inner join OrderLines on OrderLines.gid = Goods.id and OrderLines.cid = Customers.id and Customers.id = 1;
               
select Goods.product, Orders.date_of_order, Orders.time_of_order
from Goods inner join Orders on Orders.gid = Goods.id and Goods.id = 1;

select count(delivered) from Orders where Orders.delivered='not delivered';
select sum(count_of_goods) from Goods;

select Goods.product, Suppliers.name, Suppliers.surname
from Suppliers inner join Goods on Goods.sid = Suppliers.id and Goods.id = 1;

select sum(price) from Orders where Orders.cid = 1;
