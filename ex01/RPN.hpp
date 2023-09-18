#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <iostream>
#include <stack>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& rhs);
    private:
    
};

bool    add_stacks(std::stack<int> &stack, char oper);
bool    is_digit(unsigned char c);
bool    is_operator(unsigned char c);
int     strlen(const char *str);

#endif