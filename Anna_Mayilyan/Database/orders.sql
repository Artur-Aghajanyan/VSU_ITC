create database shop;

use shop;

create table customer (
    id int auto_increment not null,
    name varchar(40) not null,
    phone int not null,
    primary key(id)
);

create table supplier (
    id int auto_increment not null,
    name varchar(40) not null,
    phone int not null,
    primary key(id)
);

create table goods (
    id int auto_increment not null,
    name varchar(40) not null,
    supplier_id int not null,
    primary key(id),
    foreign key (supplier_id) references supplier(id)
);

create table orderlines (
    id int auto_increment not null,
    goods_id int not null,
    data date not null,
    time time not null,
    price int not null,
    primary key(id),
    foreign key (goods_id) references goods(id)
);

create table ord (
    ord_id int not null,
    customer_id int not null,
    is_placed boolean not null,
    foreign key(ord_id) references orderlines(id),
    foreign key (customer_id) references customer(id)
);

insert into
    supplier (name, phone)
values
    ('John', 077458795),
    ('Jake', 095478577),
    ('Kate', 076458712);

insert into
    customer (name, phone)
values
    ('Mery', 045847585),
    ('John', 077785478),
    ('Mike', 077777714),
    ('Ann', 077777784);

insert into
    goods (name, supplier_id)
values
    ('apple', 3),
    ('orange', 3),
    ('lemon', 1),
    ('cherry', 1),
    ('grapes', 2);

insert into
    orderlines (goods_id, data, time, price)
values
    (1, '2020-05-01', '12:20:20', 300),
    (2, '2020-05-11', '12:01:20', 700),
    (3, '2020-05-11', '15:01:01', 900),
    (3, '2020-05-11', '11:01:01', 900);

insert into
    ord (ord_id, customer_id, is_placed)
values
    (1, 4, true),
    (2, 3, true),
    (3, 1, true),
    (4, 2, false);

select
    supplier.id,
    supplier.name,
    goods.name
from
    supplier
    inner join goods on supplier.id = goods.supplier_id
order by
    id;

select
    orderlines.id,
    orderlines.data,
    orderlines.time,
    goods.name
from
    orderlines
    inner join goods on goods.id = orderlines.goods_id;

select
    count(*)
from
    ord
where
    is_placed = false;

select
    customer.id,
    customer.name,
    goods.name
from
    customer
    inner join ord on customer.id = ord.customer_id
    inner join orderlines on ord.ord_id = orderlines.id
    inner join goods on goods.id = orderlines.goods_id
order by
    id;

select
    count(*)
from
    goods;

select
    id,
    sum(price)
from
    orderlines
group by
    goods_id;

drop table ord;

drop table orderlines;

drop table goods;

drop table customer;

drop table supplier;

drop database shop;
