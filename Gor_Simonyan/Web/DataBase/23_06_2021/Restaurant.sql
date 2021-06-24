create database Restaurant;
use Restaurant;

create table Customers(id INT NOT NULL, name VARCHAR(255) NOT NULL, surname VARCHAR(255) NOT NULL, PRIMARY KEY(id));
insert into Customers(id, name, surname) values(1,"Ani","Andreasyan");
insert into Customers(id, name, surname) values(2,"Armen","Madoyan");
insert into Customers(id, name, surname) values(3,"Meri","Hunanyan");
insert into Customers(id, name, surname) values(4,"Inga","Abrahamyan");

create table Suppliers(id INT NOT NULL, name VARCHAR(255) NOT NULL, surname VARCHAR(255) NOT NULL, phone VARCHAR(255), PRIMARY KEY(id));
insert into Suppliers(id, name, surname, phone) values(1,"Aren","Manukyan","+37496254551");
insert into Suppliers(id, name, surname, phone) values(2,"Meliq","Hambarcumyan","+37433452145");
insert into Suppliers(id, name, surname, phone) values(3,"Hakop","Safaryanyan","+374334455");
insert into Suppliers(id, name, surname, phone) values(4,"Anna","Sepxanyanyan","+37455874520");

create table Goods(id INT NOT NULL, name VARCHAR(255) NOT NULL, s_id INT NOT NULL, g_count INT NOT NULL, prise INT NOT NULL, PRIMARY KEY(id), FOREIGN KEY(s_id) REFERENCES Suppliers(id));
insert into Goods(id, name, s_id, g_count, prise) values(1, "Brindz", 3, 125, 120);
insert into Goods(id, name, s_id, g_count, prise) values(2, "Gazar", 4, 250, 100);
insert into Goods(id, name, s_id, g_count, prise) values(3, "Banan", 3, 510, 250);
insert into Goods(id, name, s_id, g_count, prise) values(4, "Kat", 1, 12, 45);
insert into Goods(id, name, s_id, g_count, prise) values(5, "Kartofil", 2, 416, 65);
insert into Goods(id, name, s_id, g_count, prise) values(6, "Jur", 2, 2000, 85);
insert into Goods(id, name, s_id, g_count, prise) values(7, "Xndzor", 3, 741, 26);
insert into Goods(id, name, s_id, g_count, prise) values(8, "Vosp", 4, 1200, 112);
insert into Goods(id, name, s_id, g_count, prise) values(9, "Hac", 2, 20, 30);
insert into Goods(id, name, s_id, g_count, prise) values(10, "Lavash", 2, 20, 32);

create table Orders(id INT NOT NULL, c_id INT NOT NULL, ol_id INT NOT NULL, o_date VARCHAR(255), derivered VARCHAR(255), PRIMARY KEY(id), FOREIGN KEY(c_id) REFERENCES Customers(id));
insert into Orders(id, c_id, ol_id, o_date, derivered) values(1, 2, 1, "26.06.2021 15:26", "yes");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(2, 1, 4, "26.06.2021 15:45", "yes");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(3, 1, 7, "26.06.2021 16:10", "yes");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(4, 4, 3, "26.06.2021 16:55", "yes");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(5, 3, 2, "26.06.2021 17:05", "yes");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(6, 3, 9, "26.06.2021 17:34", "no");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(7, 4, 10, "26.06.2021 18:47", "no");
insert into Orders(id, c_id, ol_id, o_date, derivered) values(8, 1, 5, "26.06.2021 19:00", "no");

create table OrderLines(id INT NOT NULL, g_id INT NOT NULL, FOREIGN KEY(g_id) REFERENCES Goods(id));
insert into OrderLines(id, g_id) values(1,3);
insert into OrderLines(id, g_id) values(1,4);
insert into OrderLines(id, g_id) values(1,5);
insert into OrderLines(id, g_id) values(2,1);
insert into OrderLines(id, g_id) values(3,1);
insert into OrderLines(id, g_id) values(3,7);
insert into OrderLines(id, g_id) values(4,9);
insert into OrderLines(id, g_id) values(4,10);
insert into OrderLines(id, g_id) values(4,1);
insert into OrderLines(id, g_id) values(4,7);
insert into OrderLines(id, g_id) values(5,3);
insert into OrderLines(id, g_id) values(5,2);
insert into OrderLines(id, g_id) values(6,8);
insert into OrderLines(id, g_id) values(7,9);
insert into OrderLines(id, g_id) values(7,10);
insert into OrderLines(id, g_id) values(8,5);
insert into OrderLines(id, g_id) values(8,4);
insert into OrderLines(id, g_id) values(8,1);
insert into OrderLines(id, g_id) values(9,7);
insert into OrderLines(id, g_id) values(10,8);

select Customers.id as Customer_id, group_concat(DISTINCT Goods.name) as Goods_name from Customers inner join Orders inner join OrderLines inner join Goods on Goods.id = OrderLines.g_id and OrderLines.id = Orders.ol_id and Orders.c_id = Customers.id GROUP BY Customers.id;

select id as Order_id, o_date as Order_date from Orders;

select * from Orders where derivered = "no";

select sum(g_count) as Goods_in_warehouse from Goods;

select Goods.id as Good_id, Goods.name as Good, Suppliers.name as Supplier_name, Suppliers.surname as Supplier_surname, Suppliers.phone as Supplier_phone from Goods inner join Suppliers on Goods.s_id = Suppliers.id order by Goods.id asc;

select Orders.id as Order_id, sum(Goods.prise) as Prise from Orders inner join OrderLines inner join Goods on Orders.ol_id = OrderLines.id and OrderLines.g_id = Goods.id GROUP BY Orders.id order by Orders.id asc;

drop database Restaurant;
