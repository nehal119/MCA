CREATE TABLE Customers(
  ID NUMBER(3) NOT NULL PRIMARY KEY,
  NAME VARCHAR2(20),
  AGE NUMBER(3),
  ADDRESS VARCHAR2(30),
  SALARY NUMBER(10,2)
);

INSERT INTO Customers VALUES(001, 'Ramesh', 32, 'Ahmedabad', 2000.00);
INSERT INTO Customers VALUES(002, 'Khalid', 25, 'Delhi', 1500.00);
INSERT INTO Customers VALUES(003, 'Kaushik', 23, 'Kota', 2000.00);
INSERT INTO Customers VALUES(004, 'Chaitali', 25, 'Mumbai', 6500.00);
INSERT INTO Customers VALUES(005, 'Hardik', 27, 'Bopal', 8500.00);
INSERT INTO Customers VALUES(006, 'Komal', 22, 'MP', 4500.00);
INSERT INTO Customers VALUES(007, 'Muffy', 24, 'Indore', 10000.00);

-- a)Create a view called view1 on Customers table that should include ID, NAME and AGE from Customers.
CREATE VIEW view1 AS SELECT ID, NAME, AGE FROM Customers;
SELECT * FROM view1;

-- b)Create a view called view2 on Customers table that should include the records of
-- Customers whose salaries are greater than 5000.
CREATE VIEW view2 AS SELECT * FROM Customers WHERE SALARY > 5000;
SELECT * FROM view2;

-- d)Change the name of customer Komal to ABC by using view1.
-- Display the results of view1 as well as the base table Customers.
-- Update view1 set name =’ABC’ where name =’komal’;
UPDATE view1 SET NAME = 'ABC' WHERE NAME = 'Komal';
SELECT * FROM view1;
SELECT * FROM Customers;

-- e)Modify the salary and age of Muffy in view2 to 15000 and 26 respectively.
UPDATE view2 SET SALARY = 15000, AGE = 26 WHERE NAME = 'Muffy';
SELECT * FROM view2;

-- f)Delete a record from view1 whose ID is 004. Display the results of view1, view2 and the base table Customers.
DELETE FROM view1 WHERE ID = 004;
SELECT * FROM view1;
SELECT * FROM view2;
SELECT * FROM Customers;

-- g)Destroy the structure of view2.
DROP VIEW view2;

-- h)Create a view called view3 on Customers table with name and age. Add check option on age to be not null.


-- i)Insert a record in view3 (‘Rohan’, NULL) and (‘Joe’, 42). Display the results of view3 and Customers table