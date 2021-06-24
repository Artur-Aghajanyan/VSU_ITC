create database shoping;
use shoping;
show databases;
create table customers (id int not null, name varchar(255) not null,surname varchar(255) not null,primary key(id));
insert into customers (id, name, surname) values (1, "Artak", "Vardanyan");
insert into customers (id, name, surname) values (2, "Narek", "Petrosyan");
insert into customers (id, name, surname) values (3, "Robert", "Qocharyan");
insert into customers (id, name, surname) values (4, "Arman", "Babajanyan");
insert into customers (id, name, surname) values (5, "Edith", "Piaf");

create table suppliers (id int not null, name varchar(255) not null, surname varchar(255) not null,primary key(id));
insert into suppliers (id, name, surname) values (1, "John", "Smith");
insert into suppliers (id, name, surname) values (2, "Martin", "Skorsezze");
insert into suppliers (id, name, surname) values (3, "Giuseppe ", "Tornatore");
insert into suppliers (id, name, surname) values (4, "Gaspar", "Noe");
insert into suppliers (id, name, surname) values (5, "Emir", "Kusturica");

create table goods (id int not null, title varchar(255) not null, warehouse_product_quantity int not null,supp_id int not null, primary key(id),foreign key(supp_id) references suppliers(id));
insert into goods (id, title, warehouse_product_quantity, supp_id) values (1, "karag", 1, 2);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (2, "hac", 3, 3);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (3, "mis", 5, 1);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (4, "elak", 12, 4);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (5, "sxtor", 34, 5);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (6, "shaqaravaz", 23, 1);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (7, "dzu", 7, 1);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (8, "dzuk", 18, 1);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (9, "hanqayin jur", 8, 2);
insert into goods (id, title, warehouse_product_quantity, supp_id) values (10, "xndzor", 11, 4);

create table order_lines (id int not null, goods_id int not null, foreign key(goods_id) references goods(id));
insert into order_lines (id, goods_id) values (1, 10);
insert into order_lines (id, goods_id) values (1, 8);
insert into order_lines (id, goods_id) values (2, 3);
insert into order_lines (id, goods_id) values (3, 6);
insert into order_lines (id, goods_id) values (4, 7);
insert into order_lines (id, goods_id) values (5, 1);
insert into order_lines (id, goods_id) values (5, 2);
insert into order_lines (id, goods_id) values (6, 9);
insert into order_lines (id, goods_id) values (7, 5);
insert into order_lines (id, goods_id) values (8, 10);
insert into order_lines (id, goods_id) values (8, 8);
insert into order_lines (id, goods_id) values (9, 4);
insert into order_lines (id, goods_id) values (9, 5);
insert into order_lines (id, goods_id) values (9, 6);
insert into order_lines (id, goods_id) values (9, 7);
insert into order_lines (id, goods_id) values (10,10);

create table orders (id int not null, order_time varchar(255),cust_id int not null, orderlines_id int not null, foreign key(cust_id) references customers(id));
insert  into orders (id, order_time, cust_id, orderlines_id) values (1,"24.06. 2021 10:10", 2, 7);
insert  into orders (id, order_time, cust_id, orderlines_id) values (2,"11.06. 2021 23:14", 1, 3);
insert  into orders (id, order_time, cust_id, orderlines_id) values (3,"10.05. 2021 08:26", 3, 6);
insert  into orders (id, order_time, cust_id, orderlines_id) values (4,"24.06. 2021 12:13", 4, 8);
insert  into orders (id, order_time, cust_id, orderlines_id) values (5,"24.06. 2021 22:18", 5, 10);
insert  into orders (id, order_time, cust_id, orderlines_id) values (6,"24.06. 2021 17:23", 2, 7);
insert  into orders (id, order_time, cust_id, orderlines_id) values (7,"24.06. 2021 09:01", 2, 7);

show tables;

select * from customers;
select * from suppliers;
select * from goods;
select * from orders;
select * from order_lines order by id asc;

select sum(warehouse_product_quantity) from  goods;
select customers.id, goods.title from customers INNER JOIN orders INNER JOIN order_lines INNER JOIN goods ON orders.cust_id = customers.id and orders.orderlines_id = order_lines.id and order_lines.goods_id = goods.id;
select id, order_time from orders;
select goods.id, title, suppliers.id, name, surname from goods INNER JOIN suppliers ON goods.supp_id = suppliers.id;

drop database shoping;