
#include "RPN.hpp"

/**
 * Exemplos:
 * 
 * $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
 *  42
 * $> ./RPN "7 7 * 7 -"
 *  42
 * $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
 *  0
 * $> ./RPN "(1 + 1)"
 *  Error
 * $>
*/


// Order must be number number operator number operator


int main(int ac, char **av)
{

    if (ac != 2)
    {
        std::cerr << "Error: Usage of program: ./RPN 'Rpn Expression'" << std::endl;
        return (1);
    }

    std::stack<int> stack;
    // int digit_counter = 0;
    // int operator_counter = 0;
     
    for (size_t i = 0; av[1][i] != '\0'; i++)
    {
        if (av[1][i] == ' ')
            continue;
        if (is_digit(av[1][i]))
        {
            // digit_counter++;
            stack.push(av[1][i] - '0');
            if (av[1][i + 1] != ' ' && av[1][i + 1] != '\0')
            {
                std::cerr << "Error, number must be with one digit only and separated by spaces" << std::endl;
                return (1);
            }
        }
        else if (is_operator(av[1][i]))
        {
            // operator_counter++;   
            if (!add_stacks(stack, av[1][i]))
            {
                std::cerr << "Error, operator must have only or at least two numeric operandus to work it" << std::endl;
                return (1);
            }
        }
    }
    // if (digit_counter < 2)
    // {
    //     std::cerr << "Error, at least 2 digits" << std::endl;
    //     return (1);  
    // }
    if (stack.size() == 2)
    {
        std::cerr << "Error, Operator missing" << std::endl;
        return (1);
    }
    std::cout << "result: " << stack.top() << std::endl;
    return (0);
}