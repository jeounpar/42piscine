CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SRCS:.c=.o)
INC = includes/ft.h

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME): $(OBJECTS)
	ar rc $@ $^
	ranlib $@

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(OBJECTS)

re: fclean all

.PHONY: .c.o all clean fclean re
