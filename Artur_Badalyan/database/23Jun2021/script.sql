CREATE DATABASE magazin;
USE magazin;

CREATE TABLE customer(customerID INT AUTO_INCREMENT PRIMARY KEY,
                        firstname VARCHAR(40),
                        lastname VARCHAR(40));

CREATE TABLE orders(orderID INT AUTO_INCREMENT,
                    customerID INT,
                    totalPrice INT NULL,
                    orderDATE DATETIME,
                    PRIMARY KEY(orderID),
                    FOREIGN KEY (customerID) REFERENCES customer(customerID));

CREATE TABLE supplier(supplierID INT AUTO_INCREMENT,
                      companyName VARCHAR(40),
                      phone VARCHAR(40) NULL,
                      PRIMARY KEY(supplierID));

CREATE TABLE product(productID INT AUTO_INCREMENT,
                     supplierID INT,
                     productName VARCHAR(50),
                     unitPrice INT,
                     quantityStock INT,
                     PRIMARY KEY(productID),
                     FOREIGN KEY (supplierID) REFERENCES supplier(supplierID));

CREATE TABLE orderItem(orderID INT,productID INT,
                       quantity INT,
                       FOREIGN KEY (orderID) REFERENCES orders(orderID),
                       FOREIGN KEY (productID) REFERENCES product(productID));

/* CUSTOMER INSERT */

INSERT INTO customer(firstname,lastname) VALUES ("Karen","Petrosyan");
INSERT INTO customer(firstname,lastname) VALUES ("Tigran","Mazmanyan");
INSERT INTO customer(firstname,lastname) VALUES ("Hovik","Tigranyan");

/* ORDERS INSERT */

INSERT INTO orders(customerID, orderDATE) VALUES(1, CURRENT_TIMESTAMP());
INSERT INTO orders(customerID, orderDATE) VALUES(2, CURRENT_TIMESTAMP());
INSERT INTO orders(customerID, orderDATE) VALUES(3, CURRENT_TIMESTAMP());

/* SUPPLIER INSERT */

INSERT INTO supplier(companyName,phone) VALUES ("Smile","+374 98 86 23 55");
INSERT INTO supplier(companyName,phone) VALUES ("Gntunik","+374 55 88 20 31");
INSERT INTO supplier(companyName,phone) VALUES ("Pirajok","+374 77 88 45 00");

/* PRODUCT INSERT (MENU)*/

INSERT INTO product(productName,unitPrice,quantityStock,supplierID) VALUES ("Apple",550,55,1);
INSERT INTO product(productName,unitPrice,quantityStock,supplierID) VALUES ("Pears",425,156,1);
INSERT INTO product(productName,unitPrice,quantityStock,supplierID) VALUES ("Strawberry",857,66,1);

INSERT INTO product(productName,unitPrice,quantityStock,supplierID) VALUES ("Bread",589,365,2);
INSERT INTO product(productName,unitPrice,quantityStock,supplierID) VALUES ("Cake",480,752,2);

INSERT INTO product(productName,unitPrice,quantityStock,supplierID) VALUES ("Fries",800,253,3);

/* ORDER ITEM INSERT */

INSERT INTO orderItem(quantity,orderID,productID) VALUES (77,1,3);
INSERT INTO orderItem(quantity,orderID,productID) VALUES (10,1,2);
INSERT INTO orderItem(quantity,orderID,productID) VALUES (7,1,2);
INSERT INTO orderItem(quantity,orderID,productID) VALUES (9,2,3);
INSERT INTO orderItem(quantity,orderID,productID) VALUES (12,3,6);

SELECT * FROM customer;
SELECT * FROM orders;

SELECT * FROM supplier;
SELECT * FROM product;

SELECT * FROM orderItem;

/* Data and production of the quantity and price of goods */

SELECT customer.customerID,firstname,lastname,o.orderID,productName,product.unitPrice,orderItem.quantity,
       product.unitPrice * orderItem.quantity as totalPrice,orderDATE FROM customer
       inner join orders o on customer.customerID = o.customerID
       inner join orderItem on orderItem.orderID = o.orderID
       inner join product on product.productID= orderItem.productID;

CREATE VIEW queries as SELECT customer.customerID,firstname,lastname,o.orderID,productName,product.unitPrice,orderItem.quantity,
        product.unitPrice * orderItem.quantity as totalPrice,orderDATE FROM customer
        inner join orders o on customer.customerID = o.customerID
        inner join orderItem on orderItem.orderID = o.orderID
        inner join product on product.productID= orderItem.productID;

/* combining by buyer and getting the total price */

SELECT customerID,firstname,lastname,SUM(totalPrice) as totalPrice FROM queries
        GROUP BY customerID ORDER BY customerID;

DROP TABLE orderItem;

DROP TABLE orders;
DROP TABLE customer;

DROP TABLE product;
DROP TABLE supplier;

DROP DATABASE magazin;

