NAME = philo
SRCSPATH = ./srcs/
INCPATH = ./includes/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))

CC = cc
CFLAGS = -g -pthread -c $(foreach H,$(INCPATH),-I$(H))
#-Wall -Wextra -Werror
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
