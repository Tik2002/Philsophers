RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

NAME = philo
SRCSPATH = ./srcs/
INCPATH = ./includes/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread -c $(foreach H,$(INCPATH),-I$(H))
# -fsanitize=address -fsanitize=thread
all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(GREEN)Executable file is ready$(RESET)"
	@$(CC) -g $(OBJS) -o $(NAME)

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	@echo "$(YELLOW)Object file is ready$(RESET)"
	@$(CC) $(CFLAGS) $< -o $@

clean :
	@echo "$(RED)Object files have been removed $(RESET)"
	@rm -f $(OBJS)

fclean : clean
	@echo "$(RED)Executable file has been removed $(RESET)"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
