-- create table Ecompany(
--   Supplier varchar2(10),
--   Customer
--   Product
--   Category
--   Order
--   Payment
-- );

CREATE TABLE Suppliers(
  sup_id NUMBER(5) NOT NULL PRIMARY KEY,
  sup_name varchar2(10),
  sup_city varchar2(10),
  sup_num number(10)
);
CREATE TABLE Customers(
  cus_id NUMBER(5) NOT NULL PRIMARY KEY,
  cus_name varchar2(10),
  cus_city varchar2(10),
  cus_num number(10)
);
CREATE TABLE Products(
  prod_id NUMBER(5) NOT NULL PRIMARY KEY,
  prod_name varchar2(10),
  prod_price number(10),
  cat_id NUMBER,
  FOREIGN KEY(cat_id) REFERENCES Categories(cat_id)
);
CREATE TABLE Categories(
  cat_id NUMBER(5) NOT NULL PRIMARY KEY,
  cat_name varchar2(10),
);
CREATE TABLE Orders(
  ord_id NUMBER(5) NOT NULL PRIMARY KEY,
  ord_name varchar2(10),
  ord_price number(10),
  payment number(10),
  sup_id NUMBER,
  cus_id NUMBER,
  prod_id NUMBER,
  FOREIGN KEY(sup_id) REFERENCES Suppliers(sup_id)
  FOREIGN KEY(cus_id) REFERENCES Customers(cus_id)
  FOREIGN KEY(prod_id) REFERENCES Products(prod_id)
);