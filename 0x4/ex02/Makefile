CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

NAME = Animals

SRC = AAnimal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
