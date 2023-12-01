0x1/ex01/MakefileCXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

NAME = Moar_brainz

SRC = main.cpp Zombie.cpp

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
