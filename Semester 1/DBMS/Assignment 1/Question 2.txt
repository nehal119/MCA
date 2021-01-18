/* Create Table friends  */
CREATE TABLE friends (
    Friend_Name VARCHAR2(15),
    Address VARCHAR2(30),
    Mobileno NUMBER(10),
    Highest_Degree VARCHAR2(6),
    Marks_in_Highest_Degree NUMBER(3)
);

/* (a) Insert the records or populate the table with few records(5 to 10)  */
INSERT INTO friends(Friend_Name, Address, Mobileno, Highest_Degree, Marks_in_Highest_Degree)
VALUES('Friend 1', 'Address 1', 9879879871, 'Deg 1', 91);
INSERT INTO friends(Friend_Name, Address, Mobileno, Highest_Degree, Marks_in_Highest_Degree)
VALUES('Friend 2', 'Address 2', 9879879872, 'Deg 2', 92);
INSERT INTO friends(Friend_Name, Address, Mobileno, Highest_Degree, Marks_in_Highest_Degree)
VALUES('Friend 5', 'Address 5', 9879879875, 'Deg 5', 95);
INSERT INTO friends(Friend_Name, Address, Mobileno, Highest_Degree, Marks_in_Highest_Degree)
VALUES('Post 1', 'Address 6', 9879879876, 'Deg 6', 96);
INSERT INTO friends(Friend_Name, Address, Mobileno, Highest_Degree, Marks_in_Highest_Degree)
VALUES('Friend 3', 'Address 3', 9879879873, 'Deg 3', 93);
INSERT INTO friends(Friend_Name, Address, Mobileno, Highest_Degree, Marks_in_Highest_Degree)
VALUES('Friend 4', 'Address 4', 9879879874, 'Deg 4', 94);

/* (b) Display Name, Highest Degree and Marks in Highest Degree of all the friends  */
SELECT Friend_Name, Highest_Degree, Marks_in_Highest_Degree  FROM friends;

/* (c) Sort the table according to names.  */
SELECT * FROM friends ORDER BY Friend_Name;

/* (d) Delete records from the table based on the condition no friend’s name can start from Letter P.  */
DELETE FROM friends WHERE Friend_Name LIKE 'P%';

/* (e) Display the names of friends in the decreasing order of their marks.  */
SELECT Friend_Name FROM friends ORDER BY Marks_in_Highest_Degree DESC;
