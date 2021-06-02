DECLARE 
    lim number;
    itr  number;
    prevIdx number;
    currIdx  number;
    reserve number;
BEGIN 
  lim := 5;
  prevIdx := 0; 
  currIdx := 1;
  reserve := 0;
  IF lim = 0 THEN
    dbms_output.put_line('Not a valid length');
    ELSIF lim = 1 THEN
      dbms_output.put_line(prevIdx);
    ELSE
      FOR itr IN 1..lim LOOP
        dbms_output.put_line(prevIdx);
        reserve := prevIdx + currIdx;
        prevIdx := currIdx;
        currIdx := reserve;
      END LOOP; 
  END IF;
END;