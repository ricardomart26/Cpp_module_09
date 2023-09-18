#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<std::string> split(const std::string &s, std::string delim);


class BitcoinExchange
{
    public:

        BitcoinExchange(const std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void    parse_csv_file();
        float   find_last_date(std::string date);

    private:

        int             _year;
        int             _month;
        int             _day;
        float           _current_value;
        std::vector<std::pair<std::string, float> > _data;
        std::string     _header;
        std::ifstream   _icsv;

        void            _get_values_from_line(const std::string &line);

};


#endif