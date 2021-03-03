DECLARE 
  num number;
BEGIN 
  num := 22;
  IF mod(num,2) = 0 THEN
    dbms_output.put_line('Number is even');
  ELSE
    dbms_output.put_line('Number is odd');
  END IF;
END;