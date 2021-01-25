/* Create Table STUDIES  */
CREATE TABLE STUDIES (
    PNAME VARCHAR(20),
    SPLACE VARCHAR(20),
    COURSE VARCHAR(20),
    CCOST NUMBER(8)
);

INSERT INTO STUDIES(PNAME, SPLACE, COURSE, CCOST)
VALUES('Amar', 'Department of CS', 'PGDCA', 5000);
INSERT INTO STUDIES(PNAME, SPLACE, COURSE, CCOST)
VALUES('Vivek', 'Department of CS', 'BCA', 7000);
INSERT INTO STUDIES(PNAME, SPLACE, COURSE, CCOST)
VALUES('Saurabh', 'Department of Engg', 'B.Tech', 10000);
INSERT INTO STUDIES(PNAME, SPLACE, COURSE, CCOST)
VALUES('Rakesh', 'Department of CS', 'MCA', 8000);
INSERT INTO STUDIES(PNAME, SPLACE, COURSE, CCOST)
VALUES('Jatin', 'Delhi Univ', 'M.Tech', 10000);
SELECT * FROM STUDIES;

/* Create Table SOFTWARE  */
CREATE TABLE SOFTWARE (
    PNAME VARCHAR(20),
    TITLE VARCHAR(20),
    DEVIN VARCHAR(20),
    SCOST NUMBER(8),
    DCOST NUMBER(8),
    SOLD NUMBER(8)
);
INSERT INTO SOFTWARE(PNAME, TITLE, DEVIN, SCOST, DCOST, SOLD)
VALUES('Vivek', 'Google Map', 'JAVA', 1500, 10000, 100);
INSERT INTO SOFTWARE(PNAME, TITLE, DEVIN, SCOST, DCOST, SOLD)
VALUES('Jatin', 'Health Tracker', 'Oracle', 800, 50000, 30);
INSERT INTO SOFTWARE(PNAME, TITLE, DEVIN, SCOST, DCOST, SOLD)
VALUES('Rakesh', 'Online Portal', 'C', 2000, 20000, 5000);
INSERT INTO SOFTWARE(PNAME, TITLE, DEVIN, SCOST, DCOST, SOLD)
VALUES('Rakesh', 'Online Portfolio', 'SQL', 1000, 25000, 1500);
INSERT INTO SOFTWARE(PNAME, TITLE, DEVIN, SCOST, DCOST, SOLD)
VALUES('Saurabh', 'Student Record', 'Oracle', 4000, 40000, 221);
SELECT * FROM SOFTWARE;

/* Create Table PROGRAMMER  */
CREATE TABLE PROGRAMMER (
    PNAME VARCHAR(20),
    DOB DATE,
    DOJ DATE,
    SEX CHAR,
    PROF1 VARCHAR(20),
    PROF2 VARCHAR(20),
    SAL NUMBER(8)
);
INSERT INTO PROGRAMMER(PNAME, DOB, DOJ, SEX, PROF1, PROF2, SAL)
VALUES('Amar', '31dec1998', '31dec2018', 'M', 'JAVA', 'SQL', 700000);
INSERT INTO PROGRAMMER(PNAME, DOB, DOJ, SEX, PROF1, PROF2, SAL)
VALUES('Vivek', '1apr1995', '1dec2015', 'M', 'C', 'C++', 1000000);
INSERT INTO PROGRAMMER(PNAME, DOB, DOJ, SEX, PROF1, PROF2, SAL)
VALUES('Saurabh', '15jul1999', '1aug2017', 'M', 'PASCAL', 'SQL', 500000);
INSERT INTO PROGRAMMER(PNAME, DOB, DOJ, SEX, PROF1, PROF2, SAL)
VALUES('Rakesh', '31mar1997', '1jan2016', 'M', 'C++', 'Oracle', 800000);
INSERT INTO PROGRAMMER(PNAME, DOB, DOJ, SEX, PROF1, PROF2, SAL)
VALUES('Jatin', '21dec1990', '11feb2010', 'M', 'Oracle', 'JAVA', 1500000);
SELECT * FROM PROGRAMMER;

/* 1.Find out the selling cost average for packages developed in Oracle. */
SELECT AVG(SCOST) FROM SOFTWARE WHERE DEVIN = 'Oracle';

/* 2.Display the names, ages and experience of all programmers. */
SELECT
  PNAME,
  TRUNC(TO_NUMBER(SYSDATE - TO_DATE(DOB)) / 365.25) AS AGE,
  TRUNC(TO_NUMBER(SYSDATE - TO_DATE(DOJ)) / 365.25) AS EXPERIENCE
FROM PROGRAMMER;

/* 3.Display the names of those who have done the PGDCA course. */
SELECT PNAME FROM STUDIES WHERE COURSE = 'PGDCA';

/* 4.What is the highest number of copies sold by a package? */
SELECT MAX(SOLD) FROM SOFTWARE;

-- 5.Display the names and date of birth of all programmers born in April.
SELECT PNAME, DOB FROM PROGRAMMER WHERE to_char(DOB, 'MONTH') = 'APRIL';

-- 6.Display the lowest course fee.
SELECT MIN(CCOST) "Lowest course fee" FROM STUDIES;

-- 7.How many programmers have done the DCA course.
SELECT COUNT(COURSE) "Programmers that have done the BCA course" FROM STUDIES WHERE COURSE = 'BCA';

-- 8.How much revenue has been earned through the sale of packages developed in C.
SELECT SUM(SOLD) 'Revenue from C packages' FROM SOFTWARE WHERE DEVIN = 'C';

-- 9.Display the details of software developed by Rakesh.
SELECT * FROM SOFTWARE WHERE PNAME = 'Rakesh';

-- 10.How many programmers studied at Department of CS.
SELECT COUNT(PNAME) FROM STUDIES WHERE SPLACE = 'Department of CS';

-- 11.Display the details of packages whose sales crossed the 5000 mark.
SELECT * FROM SOFTWARE WHERE SOLD > 5000 ;

-- 12.Find out the number of copies which should be sold in order to recover the development cost of each package.
SELECT TITLE, ROUND(DCOST/SCOST) "copies needs to be sold to retrive development cost" FROM SOFTWARE;

-- 13.Display the details of packages for which the development cost has been recovered.
SELECT * FROM SOFTWARE WHERE SCOST * SOLD > DCOST;

-- 14.What is the price of costliest software developed in Oracle?
SELECT MAX(DCOST) "Costliest software developed in Oracle" FROM SOFTWARE WHERE DEVIN = 'Oracle';

-- 15.How many packages were developed in Oracle ?
SELECT COUNT(PNAME) "Packages were developed in Oracle" FROM SOFTWARE WHERE DEVIN = 'Oracle';

-- 16.How many programmers studied at Delhi Univ?
SELECT COUNT(PNAME) FROM PROGRAMMER WHERE PNAME IN (SELECT PNAME FROM STUDIES WHERE SPLACE = 'Department of CS');

-- 17.How many programmers paid 10000 to 15000 for the course?
SELECT COUNT(PNAME) FROM PROGRAMMER WHERE PNAME IN (SELECT PNAME FROM STUDIES WHERE CCOST BETWEEN 10000 AND 15000);

-- 18.What is the average course fee?
SELECT AVG(CCOST) "average course fee" FROM STUDIES;

-- 19.Display the details of programmers knowing C.
SELECT * FROM PROGRAMMER WHERE PROF1 = 'C' OR PROF2 = 'C';

-- 20.How many programmers know either C or Pascal?
SELECT COUNT(PNAME) FROM PROGRAMMER WHERE PROF1 = 'C' OR PROF2 = 'C' OR PROF1 = 'Pascal' OR PROF2 = 'Pascal';

-- 21.How many programmers don’t know C and C++?
SELECT COUNT(PNAME) FROM PROGRAMMER WHERE PROF1 NOT IN ('C', 'C++') OR PROF2 NOT IN ('C', 'C++');

-- 22.How old is the oldest male programmer?
SELECT TRUNC(TO_NUMBER(SYSDATE - TO_DATE(DOB)) / 365.25) "AGE"
FROM PROGRAMMER
WHERE DOB = (SELECT MIN(DOB) FROM PROGRAMMER)
AND SEX = 'M';

-- 23.What is the average age of female programmers?
SELECT AVG(TRUNC(TO_NUMBER(SYSDATE - TO_DATE(DOB)) / 365.25)) FROM PROGRAMMER WHERE SEX = 'F';

-- 24.Calculate the experience in years for each programmer and display along with their names in descending order.
SELECT
  PNAME,
  TRUNC(TO_NUMBER(SYSDATE - TO_DATE(DOJ)) / 365.25) AS EXPERIENCE
FROM PROGRAMMER ORDER BY DOJ DESC;

-- 25.Who are the programmers who celebrate their birthdays during the current month?

-- 26.How many female programmers are there?
SELECT COUNT(PNAME) FROM PROGRAMMER WHERE SEX = 'F'; 

-- 27.What are the languages known by the male programmers?  
-- SELECT PROF1, PROF2 FROM PROGRAMMER;
-- select PROF1 || ' ' || PROF2 from PROGRAMMER;
SELECT PROF1 AS languages FROM PROGRAMMER
UNION
SELECT PROF2 AS languages FROM PROGRAMMER;

28.What is the average salary?
29.How many people draw 5000 to 7500?
30.Display the details of those who don’t know C, C++ or Pascal.
31.Display the costliest package developed by each programmer.
32.Produce the following output for all the male programmersProgrammer