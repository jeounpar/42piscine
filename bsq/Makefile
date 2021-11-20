NAME=bsq

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=srcs/alloc_free.c srcs/file_manage.c srcs/ft_atoi.c srcs/ft_find_square.c srcs/ft_find_square2.c srcs/ft_getinfo.c srcs/main.c srcs/make_map.c srcs/ft_print.c srcs/valid_map.c
OBJS=$(SRCS:%.c=%.o)
HDRS=includes/bsq.h

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
