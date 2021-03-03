DECLARE 
    num1 number;
    num2 number;
    num3 number;
BEGIN 
  num1 := 22;
  num2 := 33;
  num3 := 11;
  IF num1 > num2 THEN
    IF num1 > num3 THEN
      dbms_output.put_line(num1);
    ELSE
      dbms_output.put_line(num3);
    END IF;
  ELSE
    IF num2 > num3 THEN 
      dbms_output.put_line(num2);
    ELSE
      dbms_output.put_line(num3);
    END IF;
  END IF;
END;