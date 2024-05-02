CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS =	./Mandatory/rules_a.c		./Mandatory/rules_b.c		./Mandatory/rules_a_b.c			\
		./Mandatory/ft_split.c		./Mandatory/ft_atoi.c		./Mandatory/linked_list.c		\
		./Mandatory/sort_utils.c	./Mandatory/sort3_4_5.c		./Mandatory/range_algo.c		\
		./Mandatory/check_args.c  	./Mandatory/main.c 

SRCS_BONUS = ./Bonus/rules_a_bonus.c		./Bonus/rules_b_bonus.c		./Bonus/rules_a_b_bonus.c		\
			 ./Bonus/ft_split_bonus.c		./Bonus/ft_atoi_bonus.c		./Bonus/linked_list_bonus.c		\
			 ./Bonus/get_next_line.c		./Bonus/get_next_line_utils.c								\
			 ./Bonus/check_args_bonus.c  	./Bonus/main_bonus.c	

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)
bonus : $(NAME_BONUS)

$(NAME): $(OBJS) ./Mandatory/push_swap.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) ./Bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
