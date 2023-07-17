//Checking for symbols and infix and postfix adapted from GeeksForGeeks.com article: Convert Infix expression to Postfix expression

#include "ExpressionMachine.h"
#include <stack>
#include <string>


void ExpressionMachine::readExpression() {
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, expression); //Gets the users input and puts it into the private variable expression
    if (isBalanced(expression)) {       //Runs it through isBalanced to check if there is the correct amount of symbols
        std::cout << "Expression is balanced\n";
        std::cout << "Postfix expression: " << infixToPostfix(expression) << "\n"; //If it is a balanced equation, then it runs it through infixToPostfix to change the expression
    }
    else {
        std::cout << "Expression is not balanced\n"; // Else it tells the user it is not balanced 
    }
}

int ExpressionMachine::prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool ExpressionMachine::isBalanced(std::string expr) {
    std::stack<char> temp;
    for (char& ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            temp.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (temp.empty()) {
                return false;
            }
            if ((temp.top() == '(' && ch == ')') ||
                (temp.top() == '{' && ch == '}') ||
                (temp.top() == '[' && ch == ']')) {
                temp.pop();
            }
            else {
                return false;
            }
        }
    }
    return temp.empty();
}

std::string ExpressionMachine::infixToPostfix(std::string s) {
    std::stack<char> st;
    std::string result;

    for (char c : s) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty()
                && prec(c) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

