#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
using namespace std;
  
string getInfix(string exp)
{
    stack <string> infixStack;
 
    for (int i=0; exp[i]!='\0'; i++)
    {
        if (isdigit(exp[i]))
        {
           string op(1, exp[i]);
           infixStack.push(op);
        }
 
        else
        {
            string op1 = infixStack.top();
            infixStack.pop();
            string op2 = infixStack.top();
            infixStack.pop();
            infixStack.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }

    return infixStack.top();
}
 
int main()
{
    std::string str;
    std::cout << "Enter RPN string : ";
    std::cin >> str;
    cout << getInfix(str);
    return 0;
}