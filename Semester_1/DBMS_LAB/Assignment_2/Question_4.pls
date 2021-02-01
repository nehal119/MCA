CREATE TABLE Salesmen(
  SNUM NUMBER(4) NOT NULL PRIMARY KEY,
  SNAME VARCHAR2(10),
  CITY VARCHAR2(15),
  COMMISSION NUMBER(3)
);

INSERT INTO Salesmen Values(1001, 'Piyush', 'London', 12);
INSERT INTO Salesmen Values(1002, 'Sejal', 'Surat', 13);
INSERT INTO Salesmen Values(1004, 'Miti', 'London', 11);
INSERT INTO Salesmen Values(1007, 'Rajesh', 'Baroda', 15);
INSERT INTO Salesmen Values(1003, 'Anand', 'New Delhi', 10);

SELECT * FROM Salesmen;

CREATE TABLE Customers(
  CNUM NUMBER(4) NOT NULL PRIMARY KEY,
  CNAME VARCHAR2(10),
  CITY VARCHAR2(15),
  RATING NUMBER(4),
  SNUM NUMBER(4),
  FOREIGN KEY(SNUM) REFERENCES Salesmen(SNUM)
);
INSERT INTO Customers Values(2001, 'Harsh', 'London', 100, 1001);
INSERT INTO Customers Values(2002, 'Gita', 'Rome', 200, 1003);
INSERT INTO Customers Values(2003, 'Lalit', 'Surat', 200, 1002);
INSERT INTO Customers Values(2004, 'Govind', 'Bombay', 300, 1002);
INSERT INTO Customers Values(2006, 'Chirag', 'London', 100, 1001);
INSERT INTO Customers Values(2008, 'Chinmay', 'Surat', 300, 1007);
INSERT INTO Customers Values(2007, 'Pratik', 'Rome', 100, 1004);
SELECT * FROM Customers;

CREATE TABLE Orders(
  ONUM NUMBER(4) NOT NULL PRIMARY KEY,
  AMOUNT NUMBER(10,2),
  ODATE DATE,
  CNUM NUMBER(4),
  SNUM NUMBER(4),
  FOREIGN KEY(CNUM) REFERENCES Customers(CNUM),
  FOREIGN KEY(SNUM) REFERENCES Salesmen(SNUM)
);
INSERT INTO Orders VALUES(3001, 18.69, '03oct1997', 2008, 1007);
INSERT INTO Orders VALUES(3003, 767.19, '03oct1997', 2001, 1001);
INSERT INTO Orders VALUES(3005, 5160.45, '03oct1997', 2003, 1002);
INSERT INTO Orders VALUES(3006, 1098.16, '03oct1997', 2008, 1007);
INSERT INTO Orders VALUES(3009, 1713.23, '04oct1997', 2002, 1003);
INSERT INTO Orders VALUES(3007, 75.75, '04oct1997', 2004, 1002);
INSERT INTO Orders VALUES(3008, 4723.00, '05oct1997', 2006, 1001);
INSERT INTO Orders VALUES(3010, 1309.95, '06oct1997', 2004, 1002);
INSERT INTO Orders VALUES(3011, 9891.88, '06oct1997', 2006, 1001);
SELECT * FROM Orders;

-- a.Find out the largest orders of salesman 1002 and 1007.
SELECT SNUM, MAX(AMOUNT) FROM Orders WHERE SNUM IN (1002, 1007) GROUP BY SNUM;

-- b.Count all orders of October 3, 1997.
SELECT COUNT(ONUM) FROM Orders WHERE ODATE = '03oct1997';

-- c.Calculate the total amount ordered.
SELECT SUM(AMOUNT) FROM Orders;

-- d.Calculate the average amount ordered.
SELECT AVG(AMOUNT) FROM Orders;

-- e.Count the no. of salesmen currently having orders.
-- SELECT COUNT(SNUM) FROM Orders GROUP BY SNUM;
SELECT COUNT(S.SNUM) FROM Salesmen S, Orders O WHERE O.ODATE=SYSDATE AND S.SNUM=O.SNUM;

-- f.Find the largest order taken by each salesman on each date.
SELECT SNUM, MAX(AMOUNT), ODATE FROM Orders GROUP BY SNUM, ODATE;

-- g.Find the largest order taken by each salesman on 10/03/1997.
SELECT SNUM, MAX(AMOUNT), ODATE FROM Orders WHERE ODATE = '03oct1997' GROUP BY SNUM, ODATE;

-- h.Count the no. of different non NULL cities in the Customer table.
SELECT COUNT(CITY) FROM Customers WHERE CITY != NULL;

-- i.Find out each customer's smallest order.
SELECT CNUM, MIN(AMOUNT) FROM Orders GROUP BY CNUM;

-- j.Find out the first customer in alphabetical order whose name  begins with 'G'.
SELECT CNUM, CNAME FROM Customers WHERE CNAME LIKE 'G%' ORDER BY CNAME;

-- k.Count the no. of salesmen registering orders for each day
SELECT ODATE, COUNT(SNUM) FROM Orders GROUP BY ODATE; 