/* Create Table employees  */
CREATE TABLE employees (
    ID NUMBER(5),
    Name VARCHAR2(30),
    Email VARCHAR2(25),
    Mobileno NUMBER(10),
    JobId VARCHAR2(10),
    Salary NUMBER(8,2)
);

/* (a) Insert the records or populate the table with few records(5 to 10)  */
INSERT INTO employees(ID, Name, Email, Mobileno, JobId, Salary)
VALUES(10002, 'Employee 2', 'user2@user.com', 9879879872, 50002, 200000);
INSERT INTO employees(ID, Name, Email, Mobileno, JobId, Salary)
VALUES(10003, 'Employee 3', 'user3@user.com', 9879879873, 50003, 100000);
INSERT INTO employees(ID, Name, Email, Mobileno, JobId, Salary)
VALUES(10004, 'Employee 4', 'user4@user.com', 9879879874, 50004, 100000);
INSERT INTO employees(ID, Name, Email, Mobileno, JobId, Salary)
VALUES(10005, 'Employee 5', 'user5@user.com', 9879879875, 50005, 100000);
INSERT INTO employees(ID, Name, Email, Mobileno, JobId, Salary)
VALUES(10006, 'Employee 6', 'user6@user.com', 9879879876, 50006, 100000);

/* (b) Display all records in the table  */
SELECT * FROM employees;

/* (c) Update a record in a table to change salary of a person with specific name  */
UPDATE employees SET Salary = 555555 WHERE Name = 'Employee 4';

/* (d) Delete all rows of a table  */
DELETE FROM employees;