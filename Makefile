SRCS_FILE =  push_swap.c \
			 parsing.c \
			 instruction.c \
			 radix.c \
			 ft_lstlast_ps.c \
			 ft_lstadd_back_ps.c \
			 ft_lstadd_front_ps.c \
			 ft_lstclear_ps.c \
			 ft_lstdelone_ps.c \
			 ft_lstnew_ps.c \

OBJECT_FILE = $(SRCS_FILE:.c=.o)

CC = cc

DEBUG = -g3 -fsanitize=address

CFLAGS = -Wall -Wextra -Werror $(DEBUG)

LIBFT = libft.a

NAME = push_swap

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C libft bonus
	mv libft/$(LIBFT) ./$(LIBFT)

$(NAME): $(LIBFT) $(OBJECT_FILE)
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
