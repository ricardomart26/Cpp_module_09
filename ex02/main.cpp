#include "PmergeMe.hpp"
#include <ctime>

std::vector<int> merge_sort_vector(std::vector<int> v)
{
    if (v.size() == 1)
        return v;

    size_t half_size = v.size() / 2;

    std::vector<int> sorted_vector = merge_sort_vector(std::vector<int>(v.begin(), v.begin() + half_size));
    std::vector<int> sorted_vector2 = merge_sort_vector(std::vector<int>(v.begin() + half_size, v.end()));
    std::vector<int> merged_vector;
    for (size_t i = 0, j = 0; i + j < sorted_vector.size() + sorted_vector2.size();)
    {
        if (j == sorted_vector2.size() || (i < sorted_vector.size() && sorted_vector[i] < sorted_vector2[j]))
            merged_vector.push_back(sorted_vector[i++]);
        else if (j < sorted_vector2.size() || i == sorted_vector.size())
            merged_vector.push_back(sorted_vector2[j++]);
    }
    return (merged_vector);
}

template <typename T>
void    print_container(T container, const std::string message)
{
    std::cout << message << ":";
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

std::list<int> merge_sort_list(std::list<int> l)
{
    if (l.size() == 1)
        return l;

    size_t half_size = l.size() / 2;

    std::list<int>::iterator half_it = l.begin();
    for (size_t i = 0; i < half_size; i++)
        half_it++;
    std::list<int> sorted_list = merge_sort_list(std::list<int>(l.begin(), half_it));
    std::list<int> sorted_list2 = merge_sort_list(std::list<int>(half_it, l.end()));
    std::list<int> merged_list;
    std::list<int>::iterator it = sorted_list.begin();
    std::list<int>::iterator it2 = sorted_list2.begin();
    for (; it != sorted_list.end() || it2 != sorted_list2.end();)
    {
        if (it2 == sorted_list2.end() || (it != sorted_list.end() && *it < *it2))
            merged_list.push_back(*(it++));
        else if ((it == sorted_list.end() || it2 != sorted_list2.end()))
            merged_list.push_back(*(it2++));
    }
    return (merged_list);
}


int main(int ac, char **av)
{
    // TODO: Test at least 3000 numbers

    if (ac == 1)
    {
        std::cout << "Usage: ./PmergeMe [numbers to organize]\n";
        return 1;
    }

    std::vector<int> numbers_vector;
  
    for (size_t i = 1; i < (size_t)ac; i++)
    {
        int num = atoi(av[i]);
        if (num < 0)
        {
            std::cerr << "Negative number not allowed: " << num << std::endl;
            return (1);
        }
        numbers_vector.push_back(num);
    }

    std::clock_t clock_begin_vector = std::clock();
    std::vector<int> merged_vector = merge_sort_vector(numbers_vector);
    std::clock_t clock_end_vector = std::clock();

    std::list<int> numbers_list;
    for (size_t i = 1; i < (size_t)ac; i++)
    {
        int num = atoi(av[i]);
        if (num < 0)
        {
            std::cerr << "Negative number: " << num << std::endl;
            return (1);
        }
        numbers_list.push_back(num);
    }
    std::clock_t clock_begin_list = std::clock();
    std::list<int> merged_list = merge_sort_list(numbers_list);
    std::clock_t clock_end_list = std::clock();

 
    std::cout << "Before:";
    for (size_t i = 1; i < (size_t)ac; i++)
        std::cout << " " << av[i];
    std::cout << std::endl;


    print_container<std::vector<int > >(merged_vector, "After");
    std::cout << std::fixed << "Time to process a range of " << numbers_list.size() << " elements with std::vector : " << (double((clock_end_vector - clock_begin_vector)) / CLOCKS_PER_SEC) << "s\n";
    std::cout << "Time to process a range of " << numbers_list.size() << " elements with std::list : " << (double((clock_end_list - clock_begin_list)) / CLOCKS_PER_SEC)  << "s\n";
    return (0);
}