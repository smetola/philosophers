NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC = main.c \
		init.c \
		monitor.c \
		threads.c \
		philo_routine.c \
		utils.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
	
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all