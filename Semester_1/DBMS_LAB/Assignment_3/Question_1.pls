CREATE TABLE Departments(
  DEPARTMENT_ID NUMBER(2) NOT NULL PRIMARY KEY,
  DEPARTMENT_NAME VARCHAR2(20)
);

INSERT INTO Departments VALUES(20, 'Accounting');
INSERT INTO Departments VALUES(30, 'IT');
INSERT INTO Departments VALUES(40, 'Marketing');

CREATE TABLE Employees(
  EMPLOYEE_ID NUMBER(3) NOT NULL PRIMARY KEY,
  FIRST_NAME VARCHAR2(10),
  LAST_NAME VARCHAR2(10),
  SALARY NUMBER(8),
  DEPARTMENT_ID NUMBER(4),
  FOREIGN KEY(DEPARTMENT_ID) REFERENCES Departments(DEPARTMENT_ID)
);
INSERT INTO Employees VALUES(111, 'Steven', 'King', 24000, 20);
INSERT INTO Employees VALUES(112, 'John', 'Hopkings', 12000, 30);
INSERT INTO Employees VALUES(113, 'Alexender', 'Roy', 10000, 20);
INSERT INTO Employees VALUES(114, 'Carlie', 'Nayer', 23000, 20);
INSERT INTO Employees VALUES(115, 'Julies', 'Ceaser', 8000, 40);
INSERT INTO Employees VALUES(116, 'James', 'Mathew', 9000, 30);
INSERT INTO Employees VALUES(117, 'Andrew', 'Matt', 5500, 30);
INSERT INTO Employees VALUES(118, 'Sunil', 'Pal', 25000, 20);
INSERT INTO Employees VALUES(119, 'Roshan', 'Kumar', 15000, 40);
INSERT INTO Employees VALUES(120, 'Rahul', 'Kapoor', 16000, 40);
SELECT * FROM Employees;

-- a)Find the names (first name as well as last name) and salaries of the employees
-- who have higher salary than the employee whose last name is Hopkings.
SELECT FIRST_NAME, LAST_NAME, SALARY FROM Employees
WHERE SALARY > (SELECT SALARY FROM Employees WHERE LAST_NAME = 'Hopkings');

-- b)Find the names (first and last name both) of all the employees who work in the IT department.
SELECT FIRST_NAME, LAST_NAME FROM Employees
WHERE DEPARTMENT_ID = (SELECT DEPARTMENT_ID FROM Departments WHERE DEPARTMENT_NAME = 'IT');

-- c) Find the names (first_name, last_name), salary of the employees whose salary is greater than the average salary.
SELECT FIRST_NAME, LAST_NAME, SALARY FROM Employees
WHERE SALARY > (SELECT AVG(SALARY) FROM Employees);

-- d)Find the names (first_name, last_name), salary of the employees who earn more than the average salary and who works in any of the IT departments.
SELECT FIRST_NAME, LAST_NAME, SALARY FROM Employees
WHERE SALARY > (SELECT AVG(SALARY) FROM Employees) AND DEPARTMENT_ID = (SELECT DEPARTMENT_ID FROM Departments WHERE DEPARTMENT_NAME = 'IT');

-- e)Find the details of the employees who earn the same salary as the minimum salary for all departments.
-- minimum salary for all departments.
SELECT MIN(SALARY), DEPARTMENT_ID FROM Employees GROUP BY DEPARTMENT_ID;
SELECT * FROM Employees WHERE SALARY IN (SELECT MIN(SALARY) FROM Employees GROUP BY DEPARTMENT_ID);

-- f)Find the details of the employees whose salary is greater than average salary of all department.
-- average salary for all departments.
SELECT AVG(SALARY), DEPARTMENT_ID FROM Employees GROUP BY DEPARTMENT_ID;
SELECT * FROM Employees E WHERE
SALARY > (SELECT AVG(SALARY) FROM Employees H WHERE E.DEPARTMENT_ID = H.DEPARTMENT_ID GROUP BY DEPARTMENT_ID );