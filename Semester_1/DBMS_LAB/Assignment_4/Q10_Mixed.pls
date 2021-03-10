CREATE TABLE Company(
  cid NUMBER(5) NOT NULL PRIMARY KEY,
  cname varchar2(10),
  ccity varchar2(10),
  empnumber number(10)
);
INSERT INTO Company VALUES(5001, 'Air India', 'Delhi', 10001);
INSERT INTO Company VALUES(5002, 'Airborn', 'Texas', 10002);
INSERT INTO Company VALUES(5003, 'Facebook', 'California', 10003);
INSERT INTO Company VALUES(5004, 'Whatsapp', 'California', 10004);

CREATE TABLE Emp(
  eid NUMBER(5) NOT NULL PRIMARY KEY,
  ename varchar2(10),
  ecity varchar2(10),
  salary number(7),
  enumber number(10),
  eaddress  varchar2(20),
  depttname varchar2(10),
  cid NUMBER,
  FOREIGN KEY(cid) REFERENCES Company(cid)
);
INSERT INTO Emp VALUES(7001, 'Aman', 'Delhi', 40000, 12549871, 'D Block', 'Sales', 5001);
INSERT INTO Emp VALUES(7002, 'John', 'Lucknow', 50000, 36599871, 'E Block', 'Market', 5002);
INSERT INTO Emp VALUES(7003, 'Ratan', 'Mumbai', 45000, 36649871, 'A Block', 'IT', 5003);
INSERT INTO Emp VALUES(7004, 'Saurabh', 'Kanpur', 60000, 16541871, 'A Block', 'IT', 5004);

-- a)Create a view having ename and ecity.
CREATE VIEW view1 AS SELECT ename, ecity FROM Emp;
SELECT * FROM view1;

-- b)In the above view change the ecity to ‘Delhi’ where ename is ‘John’.
UPDATE view1 SET ecity = 'Delhi' WHERE ename = 'John';

-- c)Create a view having attributes from both the tables.
-- LIST ALL COLUMNS
-- SELECT column_name FROM user_tab_cols WHERE table_name=UPPER('Emp');
-- CREATE VIEW view2 AS SELECT E.ename, E.ecity, E.salary, E.enumber, E.eaddress, E.depttname, C.cname, C.ccity, C.empnumber
-- FROM Emp E, Company C;
-- SELECT * FROM view2;

CREATE VIEW view2 AS SELECT
E.ename, E.ecity, E.salary, E.enumber, E.eaddress, E.depttname, cname, ccity
FROM Emp E
INNER JOIN Company C ON E.cid = C.cid;
SELECT * FROM view2;

-- d)Update the above view and increase the salary of all employees of IT department by Rs.1000.
UPDATE view2 SET salary = salary + 1000 WHERE depttname = 'IT';

-- Now solve the following queries using PL/SQL:-
-- e)Calculate the average salary from table ‘Emp’ and print ‘Increase the salary’ 
-- if the average salary is less than 10,000.
DECLARE
  e_avg_value Emp.salary%type;
  CURSOR e_avg IS SELECT AVG(salary) FROM Emp;
begin
  open e_avg;
  fetch e_avg into e_avg_value;
  DBMS_OUTPUT.PUT_LINE('Average salary is: ' || e_avg_value);
  if e_avg_value < 10000 then
    DBMS_OUTPUT.PUT_LINE('Increase the salary');
  else 
    DBMS_OUTPUT.PUT_LINE('No need to increase salary');
  end if;
  close e_avg;
end;
-- f)Print the deptno from the employee table using the case statement if the deptname is ‘Technical’
-- then deptno is 1, if the deptname is ‘HR’ then the deptno is 2 else deptno is 3.
DECLARE
  dept_name Emp.depttname%type;
  CURSOR c_dept IS SELECT depttname FROM Emp;
begin
  open c_dept;
  loop
    fetch c_dept into dept_name;
    exit when c_dept%notfound;
    case dept_name
      when 'IT' then 
        DBMS_OUTPUT.PUT_LINE('deptno is 1');
      when 'Sales' then 
        DBMS_OUTPUT.PUT_LINE('deptno is 2');
      else 
        DBMS_OUTPUT.PUT_LINE('deptno is 3');
    end case;
  end loop;
  close c_dept;
end;