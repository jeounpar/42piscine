CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SRCS:.c=.o)
INC = includes/ft.h

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(TARGET): $(OBJECTS)
	ar rc $@ $^
	ranlib $@

all: $(TARGET)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(OBJECTS)

re: fclean all

.PHONY: .c.o all clean fclean re
