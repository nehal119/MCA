/* Create Table department  */
CREATE TABLE department (
    DepartmentId NUMBER(4),
    DeptName VARCHAR2(20),
    ManagerId NUMBER(4),
    Manager_Name VARCHAR2(20),
    LocationId NUMBER(4)
);

/* (a) Insert 5 records into the above table.  */
INSERT INTO department(DepartmentId, DeptName, ManagerId, Manager_Name, LocationId)
VALUES(1, 'Department 1', 1, 'Manager 1', 1);
INSERT INTO department(DepartmentId, DeptName, ManagerId, Manager_Name, LocationId)
VALUES(2, 'Department 2', 2, 'Manager 2', 2);
INSERT INTO department(DepartmentId, DeptName, ManagerId, Manager_Name, LocationId)
VALUES(3, 'Department 3', 3, 'Manager 3', 3);
INSERT INTO department(DepartmentId, DeptName, ManagerId, Manager_Name, LocationId)
VALUES(4, 'Department 4', 4, 'Manager 4', 4);
INSERT INTO department(DepartmentId, DeptName, ManagerId, Manager_Name, LocationId)
VALUES(5, 'Department 5', 5, 'Manager 5', 5);

/* (b) Display Department and their name.  */
SELECT DepartmentId, DeptName FROM department;

/* (c) Display Deptname and their manager  */
SELECT DeptName, Manager_Name FROM department;

/* (d) Delete all rows of the table  */
DELETE FROM department;

# To list all
SELECT * FROM department;
