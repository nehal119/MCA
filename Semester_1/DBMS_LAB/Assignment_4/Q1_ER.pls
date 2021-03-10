-- create table Ecompany(
--   Supplier varchar2(10),
--   Customer
--   Product
--   Category
--   Order
--   Payment
-- );

CREATE TABLE Suppliers(
  sup_id varchar2(7) NOT NULL PRIMARY KEY,
  sup_name varchar2(20),
  sup_city varchar2(20),
  sup_num number(10)
);
insert into Suppliers values('SUP101', 'TNT Services', 'New Delhi', 1234567890);
insert into Suppliers values('SUP102', 'SOP Services', 'Mumbai', 1234547890);
insert into Suppliers values('SUP103', 'KMN Services', 'Agra', 1234567690);
select * from Suppliers;

CREATE TABLE Customers(
  cus_id varchar2(7) NOT NULL PRIMARY KEY,
  cus_name varchar2(20),
  cus_city varchar2(20),
  cus_num number(10)
);
insert into Customers values('CUS101', 'Aman', 'Bengaluru', 1214567890);
insert into Customers values('CUS102', 'Manish', 'Lucknow', 1214547890);
insert into Customers values('CUS103', 'Suraj', 'Goa', 1234567190);
select * from Customers;

CREATE TABLE Categories(
  cat_id varchar2(7) NOT NULL PRIMARY KEY,
  cat_name varchar2(20)
);

insert into Categories values('CAT101', 'Groceries');
insert into Categories values('CAT102', 'Amenities');
insert into Categories values('CAT103', 'Vegetables');
insert into Categories values('CAT104', 'Fruits');
select * from Categories;

CREATE TABLE Products(
  prod_id varchar2(7) NOT NULL PRIMARY KEY,
  prod_name varchar2(20),
  prod_price number(10),
  cat_id varchar2(7),
  FOREIGN KEY(cat_id) REFERENCES Categories(cat_id)
);
insert into Products values('PROD101', 'Potato', 60, 'CAT103');
insert into Products values('PROD102', 'Lemon', 100, 'CAT103');
insert into Products values('PROD103', 'Bedsheet', 600, 'CAT102');
insert into Products values('PROD104', 'Apple', 200, 'CAT104');
insert into Products values('PROD105', 'Rice', 100, 'CAT101');
select * from Products;

CREATE TABLE Orders(
  ord_id varchar2(7) NOT NULL PRIMARY KEY,
  ord_name varchar2(20),
  ord_price number(10),
  ord_quantity number(10),
  payment number(10),
  payment_mode varchar2(20),
  order_date DATE DEFAULT SYSDATE,
  sup_id varchar2(7),
  cus_id varchar2(7),
  prod_id varchar2(7),
  FOREIGN KEY(sup_id) REFERENCES Suppliers(sup_id),
  FOREIGN KEY(cus_id) REFERENCES Customers(cus_id),
  FOREIGN KEY(prod_id) REFERENCES Products(prod_id)
);
insert into Orders values('ORD101', 'Order 1', 600, 10, 600, 'Debit Card', '01jan2019', 'SUP101', 'CUS101', 'PROD101');
insert into Orders values('ORD102', 'Order 2', 2000, 20, 2000, 'Credit Card', '01jun2018', 'SUP101', 'CUS102', 'PROD102');
insert into Orders values('ORD103', 'Order 3', 1200, 2, 1000, 'COD', '15jan2017', 'SUP103', 'CUS101', 'PROD103');
insert into Orders values('ORD104', 'Order 4', 2000, 10, 2000, 'Debit Card', '01aug2019', 'SUP103', 'CUS102', 'PROD104');
insert into Orders values('ORD105', 'Order 5', 100, 1, 80, 'Master Card', '21jan2021', 'SUP102', 'CUS103', 'PROD105');
select * from Orders;

-- a)  Give a list of all customers whose name begins with ‘P’?
select * from Customers where cus_name LIKE 'S%'

-- b)  Display the names of suppliers who provide kitchen articles?

-- c)  What was the total sale of the company in the month of March 2018?
select SUM(payment) from Orders where to_char(order_date,'mm') = 03 AND to_char(order_date,'yyyy') = 2018;

-- d)  Find out each customer’s minimum and maximum order?
select cus_id, MAX(payment), MAX(payment) from Orders group by cus_id;

-- e) What were the top selling products along with their categories during the sale of JUNE-AUGUST 2018?
select prod_id, MAX(ord_quantity) from Orders
where order_date >= '01jun2018' AND order_date <= '31aug2018'
group by prod_id;

-- f)  Display a list of customers who bought for more than Rs. 10,000 in a month?

-- g) List all orders with their order details (name of buyer, mode of payment, products bought).
-- h) List all customers according to their state/union territory of their delivery address.
-- i)  Create a view containing the names of all the products and their categories.
-- j)  Find out each customers highest and least chosen mode of payment.
-- k)  List the name of all suppliers who sell more than two categories of products. 
-- l)  Prepare a list of least selling products for the last year.
-- m) Select the total amount in orders for each customer for whom this total is greater than the amount of the largest order in the table.
-- n) Find out which customersproduce largest and smallest orders on each date