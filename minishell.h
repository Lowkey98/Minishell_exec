#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>
#include <readline/readline.h>

typedef struct s_var{
    char *var;
    struct s_var *next;
}   t_var;
void    ft_env(t_var *var);
int		ft_echo(char **tab);
void ft_export(char **args, t_var **env_list);
void	add_str_to_node(t_var **head, char *str);
#endif