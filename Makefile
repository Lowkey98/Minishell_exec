NAME = minishell

SRC = main.c ft_echo.c ft_pwd.c ft_cd.c ft_export.c ft_env.c

CC = gcc
FLAG = -Wall -Werror -Wextra -lreadline
all :$(NAME)

$(NAME): $(SRC)
			$(CC) $(FLAG) $(SRC)  libft/libft.a -o $(NAME)
clean:
			rm -f $(NAME)

re: clean all
