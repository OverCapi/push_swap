SRCS_FILE =  push_swap.c \
			 sort_algo_utils.c \
			 update.c \
			 push_cost.c \
			 target_node.c \
			 parsing.c \
			 instruction.c \
			 instruction_double.c \
			 sort_algo.c \
			 ft_clearstack.c \
			 ft_newstack.c \
			 ft_stackadd_back.c \
			 ft_stacklast.c \
			 ft_stackadd_front.c

OBJECT_FILE = $(SRCS_FILE:.c=.o)

CC = cc

DEBUG = -g3 -fsanitize=address

CFLAGS = -Wall -Wextra -Werror $(DEBUG)

LIBFT = libft.a
FT_PRINTF = libftprintf.a

NAME = push_swap

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(FT_PRINTF):
	make -C ft_printf all
	mv ft_printf/$(FT_PRINTF) ./$(FT_PRINTF)

$(LIBFT):
	make -C libft bonus
	mv libft/$(LIBFT) ./$(LIBFT)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJECT_FILE)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILE) $(LIBFT) $(FT_PRINTF)

clean:
	rm -f $(OBJECT_FILE) $(LIBFT) $(FT_PRINTF)
	make -C libft fclean
	make -C ft_printf fclean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run: all
	./$(NAME)

.PHONY: all re fclean clean
