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
VALUES(1003, 'Saurabh', 'Researcher', 1002, '09mar2016', 30000, 30000, 1);
INSERT INTO EMP(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO)
VALUES(1004, 'Vikas', 'Researcher', 1002, '09jul2016', 35000, 35000, 1);

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

-- 1.List all the employees who have at least one person reporting to them.
SELECT * FROM EMP WHERE EMPNO IN (SELECT MGR FROM EMP);

-- 2.List the employee details if and only if more than 3 employees are present in department no 5.
SELECT * FROM EMP
WHERE DEPTNO IN (SELECT DEPTNO FROM EMP GROUP BY DEPTNO HAVING COUNT(EMPNO)>3 AND DEPTNO=5);

-- 3.List the name of the employees with their immediate higher authority.
SELECT A.ENAME "EMPLOYEE", B.ENAME "REPORTS TO" FROM EMP A, EMP B WHERE A.MGR = B.EMPNO;

-- 4.List all the employees who do not manage any one.
SELECT A.ENAME "NOT MANAGING ANYONE" FROM EMP A WHERE A.EMPNO NOT IN (SELECT MGR FROM EMP);

-- 5.List the employee details whose salary is greater than the lowest salary of an employee belonging to deptno 5.
SELECT * FROM EMP
WHERE SAL > (SELECT MIN(SAL) FROM EMP WHERE DEPTNO=5);

-- 6.List the details of the employee earning more than the highest paid manager.
SELECT * FROM EMP
WHERE SAL > (SELECT MAX(SAL) FROM EMP WHERE JOB = 'Manager');

-- 7.List the highest salary paid for each job.
SELECT JOB, MAX(SAL) FROM EMP GROUP BY JOB ;

-- 8.Find the most recently hired employee in each department.
SELECT * FROM EMP WHERE (DEPTNO, HIREDATE) IN (SELECT DEPTNO, MAX(HIREDATE) FROM EMP GROUP BY DEPTNO);

-- 9.In which year did most people join the company? Display the year and the number of employees.
SELECT TO_CHAR(HIREDATE,'YYYY'), COUNT(EMPNO) FROM EMP
GROUP BY TO_CHAR(HIREDATE,'YYYY')
HAVING COUNT(EMPNO) = (SELECT MAX(COUNT(EMPNO)) FROM EMP
GROUP BY TO_CHAR(HIREDATE,'YYYY'));

-- 10.Which department has the highest annual remuneration bill?
SELECT DEPTNO, SUM(SAL) FROM EMP GROUP BY DEPTNO
HAVING SUM(SAL) = (SELECT MAX(SUM(SAL)) FROM EMP GROUP BY DEPTNO);

-- 11.Write a query to display a ‘*’ against the row of the most recently hired employee.
SELECT LPAD(' ', 2, '*') "RECENTLY HIRED", ENAME, HIREDATE FROM EMP WHERE HIREDATE = (SELECT MAX(HIREDATE) FROM EMP)
UNION
SELECT LPAD(' ', LENGTH(ENAME)) "RECENTLY HIRED", ENAME, HIREDATE FROM EMP WHERE HIREDATE != (SELECT MAX(HIREDATE) FROM EMP);

-- 12.Write a correlated sub-query to list out the employees who earn more than the average salary of their department.
-- SELECT DEPTNO, AVG(SAL) FROM EMP GROUP BY DEPTNO;
SELECT * FROM EMP E WHERE E.SAL > (SELECT AVG(F.SAL) FROM EMP F WHERE E.DEPTNO = F.DEPTNO);

-- 13.Find the nth maximum salary.


-- 14.Select the duplicate records (Records, which are inserted, that already exist) in the EMP table.
SELECT * FROM EMP A WHERE A.EMPNO
IN (SELECT EMPNO FROM EMP GROUP BY EMPNO HAVING COUNT(EMPNO) > 1);

-- 15.Write a query to list the length of service of the employees (of the form n years and m months)
SELECT ENAME "EMPLOYEE", TO_CHAR(TRUNC(MONTHS_BETWEEN(SYSDATE,HIREDATE)/12))
||' YEARS '||
TO_CHAR(TRUNC(MOD(MONTHS_BETWEEN (SYSDATE, HIREDATE),12)))
||' MONTHS ' "LENGTH OF SERVICE"
FROM EMP;