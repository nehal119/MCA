DECLARE 
    n number; 
    counter number; 
    flag number; 
BEGIN 
    n := 30; 
    counter := 2; 
	flag := 0; 
    FOR counter IN 2..n/2 LOOP 
        IF mod(n,counter) = 0 
        THEN 
            flag := 1; 
            EXIT; 
        END IF; 
    END LOOP; 
    IF flag = 0 
    THEN 
        dbms_output.put_line('The given number is prime'); 
    ELSE 
        dbms_output.put_line('The given number is not prime'); 
    END IF; 
END;