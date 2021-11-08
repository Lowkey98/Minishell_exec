#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>
#include <readline/readline.h>

typedef struct s_envp{
	char    *key;
	char    *value;
	int     equal;
	struct s_envp *next;
}   t_envp;
	typedef struct s_redirection{
		char *filename;
		int    type;
		struct s_redirection *next;
	} t_redirection;

typedef        struct s_data{
	char    **line_cmd;
	char    **arguments;
	t_redirection red;
	struct s_data *next;
}        t_data;
void	ft_cd(char **args);
void	ft_pwd();
void    ft_env(t_envp **var);
int		ft_echo(char **tab);
void	ft_export(char **args, t_envp **env_list);
void	add_str_to_node(t_envp **head, char *str);
void	add_to_env(t_envp **head, t_envp *node);
t_envp* fill_envp(char *str);
int     env_key_error(char *var);
void    ft_unset(char **args, t_envp **env_list);
void    free_envp(t_envp *env);
void	ft_exit_bi();
#endif