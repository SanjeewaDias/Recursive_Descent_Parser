#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

class Parser {
    public:

    Parser() {
        std::string str;
        std::cout << "Enter PN string : ";
        std::cin >> str;
        stream = std::stringstream(str);
        lookahead = stream.get();
    }

    void parse() {
        //Start grammar (expr ->)
        expr();

        //Print output
        print_translated_string();
    }

    private:
    
    char lookahead; //Fetch the char value at the pointer
    std::string rpn_str = "Output in RPN : ";
    std::stringstream stream;

    void createOutStr(char terminal) { //Concatenates the terminals
        rpn_str += terminal;
    }

    void print_translated_string() { //Display converted string(in RPN)
        std::cout << rpn_str << std::endl; 
    }

    std::string error_message(char lookahead) {
        return "Syntax error near " + std::string(1, lookahead); //Generate Syntax error
    }

    void fetchNextChar(char terminal) {
        if (terminal == lookahead) {
            lookahead = stream.get();
        }
        else {
            throw std::invalid_argument(error_message(lookahead)); //throw CFG syntax exception
        }
    }

    void digit() {
        createOutStr(lookahead);
        fetchNextChar(lookahead);
    }

    void term() {

        //term -> digit
        if (isdigit(lookahead)) {
            digit();  
        }

        // term -> (expr)
        else if (lookahead == '(') {
            fetchNextChar('(');
            expr();
            fetchNextChar(')');
        }
        else {
            throw std::invalid_argument(error_message(lookahead)); //throw CFG syntax exception
        }
    }

    void expr() {     
        term();  //expr -> term expr'

        while (true) {
            if (lookahead == '+') {    //expr' -> term {print("+")} expr
                fetchNextChar('+');
                term();
                createOutStr('+');
            }
            else if (lookahead == '-') { //expr' -> term {print("-")} expr
                fetchNextChar('-');
                term();
                createOutStr('-');
            }
            else {
                return; //expr' -> Epsilon
            }
        }
    }
};

int main() {
    Parser parser;
    try {
        parser.parse();
    }
    catch(const std::invalid_argument invldArg){
        std::cout << invldArg.what() << std::endl;
    }
    return 0;
}