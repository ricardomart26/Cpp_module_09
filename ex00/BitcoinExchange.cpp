#include "BitcoinExchange.hpp"

bool    is_in_string(const std::string &str, char c)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == c)
            return true;
    }
    return false;
}

std::vector<std::string> split(const std::string &s, std::string delim)
{
    std::vector<std::string> elems;
    std::string::const_iterator begin = s.begin();
    while (is_in_string(delim, *begin))
        begin++;
    for (std::string::const_iterator end = begin; end != s.end(); end++)
    {
        if (is_in_string(delim, *end) && begin != end)
        {
            elems.push_back(std::string(begin, end));
            while (is_in_string(delim, *end) && end != s.end())
                end++;
            begin = end;
            if (end == s.end()) // ESTE IF DOESNT MAKE ANY SENSE
                break;
        }
    }
    if (begin != s.end())
        elems.push_back(std::string(begin, s.end()));
    return elems;
}

BitcoinExchange::BitcoinExchange(const std::string filename): _icsv(filename)
{
    // if (_icsv.fail()); // Send exception
}

void    BitcoinExchange::parse_csv_file()
{
    std::getline(_icsv, _header);
    while (_icsv.good())
    {
        std::string line;
        std::getline(_icsv, line);
        if (line.empty())
            continue;
        std::vector<std::string> values = split(line, ",");
        _data.push_back(std::make_pair(values[0], atof(values[1].c_str())));
    }
}

float    BitcoinExchange::find_last_date(std::string date)
{
    std::vector<std::pair<std::string, float> >::iterator it = _data.begin();
    float last_value = 0;
    for (; it != _data.end(); it++)
    {
        if (it->first.compare(date) >= 0)
        {
            if (it->first.compare(date) == 0)
                return it->second;
            return last_value;
        }
        last_value = it->second;
    }
    return last_value;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    (void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    (void)other;
    return *this;
}

