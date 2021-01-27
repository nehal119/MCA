/* Create Table DEPT  */
CREATE TABLE DEPT (
    DEPTNO NUMBER(2) NOT NULL PRIMARY KEY,
    DNAME VARCHAR2(14),
    LOC VARCHAR2(13)
);

INSERT INTO DEPT(DEPTNO, DNAME, LOC) VALUES(1, 'Research', '1st Floor');
INSERT INTO DEPT(DEPTNO, DNAME, LOC) VALUES(2, 'Marketing', '2nd Floor');
INSERT INTO DEPT(DEPTNO, DNAME, LOC) VALUES(3, 'Finance', '3rd Floor');
INSERT INTO DEPT(DEPTNO, DNAME, LOC) VALUES(4, 'Management', '4th Floor');
INSERT INTO DEPT(DEPTNO, DNAME, LOC) VALUES(5, 'Production', '5th Floor');
SELECT * FROM DEPT;

/* Create Table EMP  */
CREATE TABLE EMP (
    EMPNO NUMBER(4) NOT NULL PRIMARY KEY,
    ENAME VARCHAR2(10),
    JOB VARCHAR2(15),
    MGR NUMBER(4),
    HIREDATE DATE,
    SAL NUMBER(7,2),
    COMM NUMBER(7,2),
    DEPTNO NUMBER(2),
    FOREIGN KEY(DEPTNO) REFERENCES DEPT(DEPTNO)
);

INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1001, 'Amar', 'Manager', 1005, '25jun2015', 90000, 90000, 4);

INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1002, 'Aman', 'Research Sr', 1001, '09mar2013', 40000, 40000, 1);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1003, 'Saurabh', 'Researcher', 1003, '09mar2016', 30000, 30000, 1);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1004, 'Vikas', 'Researcher', 1003, '09jul2016', 35000, 35000, 1);

INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1005, 'Jatin', 'Market Sr', 1001, '25dec2019', 25000, 25000, 2);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1006, 'Rajesh', 'Market', 1005, '05feb2018', 10000, 10000, 2);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1007, 'Rashi', 'Market', 1005, '20dec2019', 15000, 15000, 2);

INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1008, 'Vivek', 'Account', 1001, '05jan2020', 35000, 35000, 3);

INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1009, 'Rakesh', 'Developer Sr', 1001, '01jan2010', 20000, 20000, 5);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1010, 'Srishti', 'Developer', 1009, '15jan2016', 40000, 40000, 5);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1011, 'Saqib', 'Developer', 1009, '15jan2016', 40000, 40000, 5);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1012, 'Suraj', 'Developer', 1009, '15jan2016', 40000, 40000, 5);

SELECT * FROM EMP;

1.List all the employees who have at least one person reporting to them.
2.List the employee details if and only if more than 10 employees are present in department no 10.
3.List the name of the employees with their immediate higher authority.
4.List all the employees who do not manage any one.
5.List the employee details whose salary is greater than the lowest salary of an employee belonging to deptno 20.
6.List the details of the employee earning more than the highest paid manager.
7.List the highest salary paid for each job.
8.Find the most recently hired employee in each department.
9.In which year did most people join the company? Display the year and the number of employees.
10.Which department has the highest annual remuneration bill?
11.Write a query to display a ‘*’ against the row of the most recently hired employee.
12.Write a correlated sub-query to list out the employees who earn more than the average salary of their department.
13.Find the nth maximum salary.
14.Select the duplicate records (Records, which are inserted, that already exist) in the EMP table.
15.Write a query to list the length of service of the employees (of the form n years and m months)