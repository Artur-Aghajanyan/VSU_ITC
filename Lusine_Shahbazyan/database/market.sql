create database Market;
Use Market;

create Table Customrs(
    id int not null auto_increment,
    name varchar(20),
    surname varchar(20),
    PRIMARY KEY(id)
);
create Table Suppliers(
    id int not null auto_increment,
    name varchar(20),
    surname varchar(20),
    PRIMARY KEY(id)
);
create Table Goods(
    id int not null auto_increment,
    name varchar(20),
    sup_id int,
    good_count int,
    price int,
    PRIMARY KEY(id),
    foreign key(sup_id) references Suppliers(id)
);
create Table Orders(
    id int not null auto_increment,
    cust_id int not null,
    ordStatus boolean,
    orderDate DATETIME,
    PRIMARY KEY(id),
    foreign key(cust_id) references Customrs(id)
);
create Table OrderLines(
    id int not null auto_increment,
    ord_id int,
    good_id int,
    good_count int,
    price int,
    PRIMARY KEY(id),
    foreign key(good_id) references Goods(id),
    foreign key(ord_id) references Orders(id)
);

insert into Customrs(name, surname) values
    ('Ani', 'Andreasyan'),
    ('Meri', 'Araqelyan'),
    ('Ashot', 'Poxosyan'),
    ('Alen', 'Stepanyan');

insert into Suppliers(name, surname) values
    ('Mher', 'Atoyan'),
    ('Lilit', 'Zalyan'),
    ('Arman', 'Arayan'),
    ('Davit', 'Petrosyan');

insert into Orders(cust_id, ordStatus, orderDate) values
    (1, true, CURRENT_TIMESTAMP()),
    (1, false, CURRENT_TIMESTAMP()),
    (2, true, CURRENT_TIMESTAMP()),
    (2, true, CURRENT_TIMESTAMP()),
    (3, false, CURRENT_TIMESTAMP()),
    (3, true, CURRENT_TIMESTAMP()),
    (4, false, CURRENT_TIMESTAMP());

insert into Goods(name, sup_id, good_count, price) values
    ('milk', 1, 50, 250),
    ('butter', 1, 20, 2500),
    ('bread', 2, 80, 200),
    ('apply', 2, 30, 250),
    ('orange', 4, 15, 650),
    ('cheese', 3, 12, 1900),
    ('sugar', 2, 42, 420),
    ('spaghetti', 4, 26, 400),
    ('meat', 3, 16, 3000);

insert into OrderLines(ord_id, good_id, good_count, price) values
    (1, 1, 3, 500),  
    (2, 1, 6, 120),
    (2, 5, 2, 520),
    (3, 5, 1, 100),
    (4, 3, 3, 400),
    (5, 5, 2, 230),
    (4, 1, 3, 200),
    (1, 1, 3, 500),  
    (2, 1, 6, 120),
    (2, 5, 2, 520),
    (3, 5, 1, 100),
    (4, 3, 3, 400),
    (5, 5, 2, 230),
    (4, 1, 3, 200);
/* List of products ordered by the customer */
select O.id, C.name, C.surname, G.name, G.price, OL.good_count from Customrs C 
    inner join Orders O on C.id = O.cust_id 
    inner join OrderLines OL on O.id = OL.ord_id 
    inner join Goods G on G.id = OL.good_id;

/* Date / time of order */
select cust_id, orderDate from Orders;

/* Open orders */
select * from Orders where Orders.ordStatus = false;

/* Count of products in stock */
select * from Goods;
select sum(good_count) from Goods;

/* Which supplier provides the product */
select Goods.name, Suppliers.name, Suppliers.surname from Goods 
    inner join Suppliers on Goods.sup_id = Suppliers.id;

/* Total cost of the order */
select OrderLines.ord_id, OrderLines.price from OrderLines where 
    ord_id = 2;
select sum(price) from OrderLines where 
    ord_id = 2;
  
drop Table OrderLines;
drop Table Orders;
drop Table Goods;
drop Table Suppliers;
drop Table Customrs;
drop database Market;