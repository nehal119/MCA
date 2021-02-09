-- SOLUTION - 1
DECLARE 
   c_deptno EMP.DEPTNO%type; 
   c_id EMP.EMPNO%type; 
   c_sal EMP.SAL%type; 
   CURSOR c_emp is SELECT DEPTNO, EMPNO, SAL FROM EMP; 
BEGIN 
   OPEN c_emp; 
   LOOP 
   FETCH c_emp into c_deptno, c_id, c_sal; 
      EXIT WHEN c_emp%notfound;
      UPDATE EMP SET SAL = c_sal + (c_sal*0.05) WHERE DEPTNO = c_deptno AND DEPTNO = 20;
      INSERT INTO emp_raise(emp_no, date_of_raise, actual_raise) VALUES(c_id, SYSDATE, c_sal*0.05)
   END LOOP; 
   CLOSE c_emp; 
END;

-- SOLUTION - 2
CREATE TABLE Circle (
        r number,
        diameter number,
        radius  number
);

DECLARE 
  r number(1);
  pi number(5,2) := 3.14;
  area number(10,10);
  diameter  number(10,10); 
BEGIN
  FOR r IN 10..20 LOOP
    area := pi * r * r;
    diameter  := 2 * r;
    INSERT INTO Circle(r, diameter, radius) VALUES(r, diameter, area);
  END loop;
END; 

--   SELECT * FROM Circle;
--   DELETE FROM Circle;



-- BEGIN
--     UPDATE employee SET salary = salary + (salary * 0.05)
--     -- WHERE emp_code = &emp_code;
--     WHERE department = 20;
--     IF SQL%FOUND THEN
--         DBMS_OUTPUT.PUTLINE('Record Updated')
--     ELSE
--         DBMS_OUTPUT.PUTLINE('Employee no not found')
-- END; 

-- --   SELECT * FROM Circle;
-- --   DELETE FROM Circle;


-- DECLARE  
--   total_rows number(2); 
-- BEGIN 
--   UPDATE EMP SET SAL = SAL + SAL*0.05 WHERE DEPTNO = 1; 
--   IF sql%notfound THEN 
--       dbms_output.put_line('no customers selected'); 
--   ELSIF sql%found THEN 
--       total_rows := sql%rowcount;
--       dbms_output.put_line( total_rows || ' customers selected '); 
--   END IF;  
-- END;
