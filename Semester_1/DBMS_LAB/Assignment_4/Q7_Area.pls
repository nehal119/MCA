DECLARE 
    r number;
    area  number;
    parameter number;
    pi  number;
BEGIN 
  r := 4;
  pi := 3.14;
  area := 0;
  parameter := 0;
  area := pi * power(r,2);
  parameter := 2 * pi * r;
  dbms_output.put_line('Area is: ' || area);
  dbms_output.put_line('Parameter is: ' || parameter);
END;