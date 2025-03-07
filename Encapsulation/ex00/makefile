NAME = bankSystem
NAME_B = bankSystemBonus

HEADER = Account.hpp Bank.hpp 
HEADER_B = Bank_bonus.hpp 

SRC = main.cpp Account.cpp Bank.cpp
SRC_B = main_bonus.cpp Account_bonus.cpp Bank_bonus.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_B = $(SRC_B:.cpp=.o)

CC = c++

CXXFLAGES = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CXXFLAGES) -c $< -o $@


$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CXXFLAGES) $(SRC) -o $(NAME)

${NAME_B} : $(OBJ_B) $(HEADERB)
			$(CC) $(CXXFLAGES) $(SRC_B) -o $(NAME_B)

all: $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all

bonus: $(NAME_B)

.PHONY: all clean fclean re bonus