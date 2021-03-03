DECLARE 
    num number; 
    checkPalindrome number; 
    rev number; 
BEGIN
    num := 303; 
    checkPalindrome := num; 
	  rev := 0;
    WHILE num != 0 LOOP 
      rev := (rev * 10);
      rev := rev + mod(num,10);
      num := trunc(num / 10);
    END LOOP;
    IF checkPalindrome = rev
    THEN 
        dbms_output.put_line('The given number is a palindrome'); 
    ELSE 
        dbms_output.put_line('The given number is not palindrome'); 
    END IF; 
END;