/* Create Table classmates  */
CREATE TABLE classmates (
    RollNo NUMBER(2),
    Name VARCHAR2(30),
    Address VARCHAR2(6),
    Mobileno NUMBER(10),
    Marks_In_Test NUMBER(3)
);

/* (a) Insert the records or populate the table with few records(5-10)  */
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(21, 'Classmate 1', 'Addr 1', 9879879871, 61);
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(22, 'Classmate 2', 'Addr 2', 9879879872, 87);
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(23, 'Classmate 3', 'Addr 3', 9879879873, 91);
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(24, 'Classmate 4', 'Addr 4', 9879879874, 62);
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(25, 'Classmate 5', 'Addr 5', 9879879875, 99);
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(41, 'Classmate 6', 'Addr 6', 9879879871, 100);
INSERT INTO classmates(RollNo, Name, Address, Mobileno, Marks_In_Test)
VALUES(52, 'Classmate 7', 'Addr 7', 9879879872, 66);

/* (b) Display Students with roll numbers between 20 to 30  */
SELECT * FROM classmates WHERE RollNo > 20 AND RollNo < 30;
SELECT * FROM classmates WHERE RollNo BETWEEN 20 AND 30;

/* (c) Sort the table in increasing order of their roll numbers.  */
SELECT * FROM classmates ORDER BY RollNo ASC;

/* (d) Display names of students with their percentage.  */
Select Name, (Marks_In_Test * 100 / 200) as Percentage From classmates;