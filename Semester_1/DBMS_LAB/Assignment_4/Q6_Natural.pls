DECLARE 
    lim number;
    itr  number;
    sumResult number;
BEGIN 
  lim := 10;
  sumResult := 0;
  FOR itr IN 1..lim LOOP
    sumResult := sumResult + itr;
  END LOOP; 
  dbms_output.put_line(sumResult);
END;