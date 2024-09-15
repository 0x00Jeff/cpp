CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -g -ggdb3 #-fsanitize=address

NAME = RPN

SRC = main.cpp Rpn.cpp

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
