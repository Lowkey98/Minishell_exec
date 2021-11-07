# include "minishell.h"

// void    fill_env_list(t_envp ** env_list, char **envp)
// {
// 	int i;

// 	i = 0;
// 	t_envp *tmp;
// 	tmp = (*env_list);

//     while (envp[i])
// 	{
// 		(*env_list) = malloc(sizeof(t_envp));
// 		(*env_list)->key = ft_strdup(envp[i]);
// 		//break;
// 		//printf("%d-%s\n",i,(*env_list)->var);
// 		i++;
// 		(*env_list)->next = (*env_list);
// 		//*env_list->var = ft_strdup(envp[i]);
// 	}
// 	(*env_list) = tmp;
// }




int main(int argc, char **argv, char **envp)
{
	char *str;
	int i;
	t_data data;

	i = 0;
    t_envp *env_list;
	while(envp[i])
	{
		add_to_env(&env_list, fill_envp(envp[i])); 
		i++;
	}
	if (argc != 1 && !argv[0]) 
        return(-1);
	while(1)
	{
		str = readline("shell>");
		add_history(str);
		data.arguments = ft_split(str, ' ');
		if (ft_strncmp(data.arguments[0],"echo", ft_strlen(data.arguments[0])) == 0)
			ft_echo(data.arguments);
		if (ft_strncmp(data.arguments[0],"env", ft_strlen(data.arguments[0])) == 0)
			ft_env(env_list);
		if (ft_strncmp(data.arguments[0], "export", ft_strlen(data.arguments[0])) == 0)
			ft_export(data.arguments, &env_list);
		if (ft_strncmp(data.arguments[0], "unset", ft_strlen(data.arguments[0])) == 0)
			ft_unset(data.arguments, &env_list);
		if (ft_strncmp(data.arguments[0], "exit", ft_strlen(data.arguments[0])) == 0)
			ft_exit_bi();
		if (ft_strncmp(data.arguments[0], "pwd", ft_strlen(data.arguments[0])) == 0)
			ft_pwd();
		if (ft_strncmp(data.arguments[0], "cd", ft_strlen(data.arguments[0])) == 0)
			ft_cd(data.arguments);
		//ft_free_split(str);
	}

}