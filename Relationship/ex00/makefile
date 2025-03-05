NAME = relationship

HEADER = Data.hpp Hammer.hpp Shovel.hpp Tool.hpp Worker.hpp Workshop.hpp Simulation.hpp 

SRC = main.cpp Data.cpp Hammer.cpp Shovel.cpp Tool.cpp Worker.cpp Workshop.cpp Simulation.cpp

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