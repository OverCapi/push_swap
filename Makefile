SRCS_FILE =  push_swap.c \
			 instruction.c

OBJECT_FILE = $(SRCS_FILE:.c=.o)

CC = cc

DEBUG = -g3 -fsanitize=address

CFLAGS = -Wall -Wextra -Werror $(DEBUG)

LIBFT = libft.a

NAME = push_swap

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

lib:
	make -C libft bonus
	mv libft/$(LIBFT) ./$(LIBFT)

$(NAME): lib $(OBJECT_FILE)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILE) $(LIBFT)

clean:
	rm -f $(OBJECT_FILE) $(LIBFT)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run: all
	./$(NAME)

.PHONY: all re fclean clean
