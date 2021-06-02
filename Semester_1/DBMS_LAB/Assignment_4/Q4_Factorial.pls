DECLARE 
    num number; 
    counter number;
    fact  number;
BEGIN 
  num := 5; 
  counter := 1; 
  fact := 1;
  FOR counter IN 1..num LOOP 
      fact := (fact * counter);
  END LOOP; 
  dbms_output.put_line('Factorial is: ' || fact); 
END;