NAME = Logger

HEADER = dateHeaderProvider.hpp defaultHeaderProvider.hpp fileLoger.hpp generateLogHeader.hpp iHeaderProvider.hpp \
	iLogger.hpp streamLogger.hpp

SRC = main.cpp

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
	rm -rf $(NAME) file_* 2025*

re : fclean all

.PHONY: all clean fclean re