#include <iostream>
#include <stack>


class ExpressionMachine {
public:
    void readExpression();
    bool isBalanced(std::string expr);
    std::string infixToPostfix(std::string expr);

private:
    std::string expression;
    int prec(char c);
};