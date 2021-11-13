NAME = minishell

SRC = ft_exit_bi.c free_struct.c main.c ft_unset.c ft_echo.c ft_pwd.c ft_cd.c ft_export.c ft_env.c

CC = gcc
FLAG = -Wall -Werror -Wextra -lreadline -fsanitize=address
all :$(NAME)

$(NAME): $(SRC)
			$(CC) $(FLAG) $(SRC)  libft/libft.a -o $(NAME)
clean:
			rm -f $(NAME)

re: clean all
bonus :$(NAME_BONUS)