/* Create Table Department  */
CREATE TABLE Department (
    deptno NUMBER(5) NOT NULL PRIMARY KEY,
    dname VARCHAR2(30) NOT NULL,
    loc VARCHAR2(25) NOT NULL
);
INSERT INTO Department(deptno, dname, loc) VALUES(10001, 'Department 1', 'Location 1');
INSERT INTO Department(deptno, dname, loc) VALUES(10002, 'Department 2', 'Location 2');
INSERT INTO Department(deptno, dname, loc) VALUES(10003, 'Department 3', 'Location 3');
SELECT * FROM Department;


/* Create Table Employee  */
CREATE TABLE Employee (
    empno NUMBER(5) NOT NULL PRIMARY KEY,
    ename VARCHAR2(30) NOT NULL,
    job VARCHAR2(10),
    hiredate DATE DEFAULT SYSDATE,
    /* hiredate timestamp DEFAULT systimestamp,  */
    deptno NUMBER,
    FOREIGN KEY(deptno) REFERENCES Department(deptno)
);
INSERT INTO Employee(empno, ename, job, deptno) VALUES(20001, 'Employee 1', 'Job 1', 10001);
INSERT INTO Employee(empno, ename, job, deptno) VALUES(20002, 'Employee 2', 'Job 2', 10002);
INSERT INTO Employee(empno, ename, job, deptno) VALUES(20003, 'Employee 3', 'Job 3', 10003);
SELECT * FROM Employee;
