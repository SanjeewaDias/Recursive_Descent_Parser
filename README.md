# Recursive_Descent_Parser
Includes recursive descent parsers for converting Polish notaion to Reverse Polish notation

Production Rules*************************

expr   -> expr + term | expr - term | term
term   -> term * factor | term / factor | factor
factor -> (expr) | digit
digit  -> 0|1|2|3|4|5|6|7|8|9  


Syntax Directed Translation**************This is to include semantic actions(Print) to the Grammar

expr -> expr + term {print("+")}
      | expr - term {print("-")}
      | term

term -> term * factor {print("*")}
      | term / factor {print("/")}
      | factor
 
factor -> (expr) | digit          

digit  -> 0 {print("0")}
        | 1 {print("1")}
        ...
        ...
        | 9 {print("9")} 

Left Recursion Elimination****************

expr  -> term expr'

expr' -> +  term {print("+")} expr'
        | -  term {print("-")} expr'
        | epsilon
term  -> factor term'

term' -> *  factor {print("*")} term'
        | /  factor {print("/")} term'
        | epsilon
factor -> (expr) | digit
digit  -> 0 {print("0")}
        | 1 {print("1")}
        ...
        ...
        | 9 {print("9")}     
