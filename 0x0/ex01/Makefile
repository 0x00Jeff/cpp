CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98

NAME = PhoneBook

SRC = main.cpp Contact.cpp PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
