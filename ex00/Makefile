
NAME = btc

CXX = c++ 

CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address -g --std=c++98

SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re