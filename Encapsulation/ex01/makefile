NAME = graphPrinter

HEADER = Graph.hpp Vector2.hpp 

SRC = main.cpp Graph.cpp Vector2.cpp 

OBJ = $(SRC:.cpp=.o)

CC = c++

CXXFLAGES = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CXXFLAGES) -c $< -o $@


$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CXXFLAGES) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re