create table EmployeeDetails(
  EmpId number(5) NOT NULL PRIMARY KEY,
  FullName varchar2(20) NOT NULL,
  ManagerId varchar2(20) NOT NULL,
  DateOfJoining date,
  City varchar2(20) NOT NULL
);

insert into EmployeeDetails values(121, 'John Snow', 321, '31jan2014', 'Toronto');
insert into EmployeeDetails values(321, 'Walter White', 986, '30jan2015', 'California');
insert into EmployeeDetails values(421, 'Kuldeep Rana', 876, '27nov2016', 'New Delhi');

CREATE TABLE EmployeeSalary (
    Project VARCHAR2(20) NOT NULL,
    Salary number(10) NOT NULL,
    EVariable number(10) NOT NULL,
    EmpId NUMBER(5),
    FOREIGN KEY(EmpId) REFERENCES EmployeeDetails(EmpId)
);
insert into EmployeeSalary(Project, Salary, EVariable, EmpId) values('P1', 8000, 500, 121);
insert into EmployeeSalary(Project, Salary, EVariable, EmpId) values('P2', 10000, 1000, 321);
insert into EmployeeSalary(Project, Salary, EVariable, EmpId) values('P3', 12000, 0, 421);

SELECT * FROM EmployeeDetails;
SELECT * FROM EmployeeSalary;

SELECT EmpId FROM EmployeeDetails INTERSECT SELECT EmpId FROM EmployeeSalary;