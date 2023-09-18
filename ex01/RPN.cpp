#include "RPN.hpp"


RPN::RPN() {
    std::cout << "RPN constructor" << std::endl;
}

RPN::~RPN() {
    std::cout << "RPN destructor" << std::endl;
}

RPN::RPN(const RPN& other) {}

RPN& RPN::operator=(const RPN& rhs) {

}


bool    is_digit(unsigned char c)
{
    return (c >= '0' && c <= '9');
}

bool    is_operator(unsigned char c)
{
    return (c >= '+' || c == '-' || c == '/' || c == '*');
}

bool    add_stacks(std::stack<int> &stack, char oper)
{
    if (stack.size() < 2)
        return (false);
    int top = stack.top();
    stack.pop(); 
    int bottom = stack.top();
    stack.pop();
    if (oper == '+')
        stack.push(bottom + top);
    else if (oper == '-')
        stack.push(bottom - top);
    else if (oper == '*')
        stack.push(bottom * top);
    else if (oper == '/')
        stack.push(bottom / top);
    return (true);
}

int strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
