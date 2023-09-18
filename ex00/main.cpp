
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


size_t count_characters(std::string &s, char delim)
{
    size_t count = 0;
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
    {
        if (*it == delim)
            count++;
    }
    return count;
}

bool check_date(std::string& date)
{
    size_t characters_ammount = count_characters(date, '-');
    if (characters_ammount != 2)
        return false;
    std::vector<std::string> split_date = split(date, " -");
    if (split_date.size() != 3)
        return false;
    // size_t year = atoi(split_date[0].c_str());
    size_t month = atoi(split_date[1].c_str());
    if (month < 1 || month > 12)
        return false;
    int day = atoi(split_date[2].c_str());
    if (day < 1 || day > 31)
        return false;

    // std::cout << year << "-" << month << "-" << day << std::endl;
    return true;
}

int main(int ac, char **av)
{
    std::ifstream ifs(av[1]);
    if (ac < 2 || ifs.fail())
    {
        std::cout << "Error: could not open file";
        return (1);
    }
    
    BitcoinExchange btc("data.csv");

    btc.parse_csv_file();
    
    std::vector<std::string> lines;
    while (ifs.good())
    {
        std::string line;
        std::getline(ifs, line);
        lines.push_back(line);
    }
    
    for (size_t i = 0; i < lines.size(); i++)
    {
        std::vector<std::string> split_line = split(lines[i], " |");
        if (split_line.size() != 2)
        {
            std::cout << "Error: bad input => " << lines[i] << std::endl;
            continue;
        }
        std::string date = split_line[0];
        float value = atof(split_line[1].c_str());
        if (!check_date(date))
        {
            std::cout << "Error: bad date => " << date << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        float btc_value = btc.find_last_date(date);
        std::cout << date << " => " << value << " = " <<  btc_value * value << std::endl;
    }
}

