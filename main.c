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



void	ft_builtins(t_data *data, t_envp **env_list)
{
		if (ft_strcmp(data->arguments[0],"echo") == 0)
			ft_echo(data->arguments); 
		if (ft_strcmp(data->arguments[0], "env") == 0)
			ft_env(env_list);
		if (ft_strcmp(data->arguments[0], "export") == 0)
			ft_export(data->arguments, env_list);
		if (ft_strcmp(data->arguments[0], "unset") == 0)
			ft_unset(data->arguments, env_list);
		if (ft_strcmp(data->arguments[0], "exit") == 0)
			ft_exit_bi();
		if (ft_strcmp(data->arguments[0], "pwd") == 0)
			ft_pwd();
		if (ft_strcmp(data->arguments[0], "cd") == 0)
			ft_cd(data->arguments);
}

int		is_builtin(char *cmd)
{
		if (ft_strcmp(cmd,"echo") == 0)
			return (1);
		if (ft_strcmp(cmd, "env") == 0)
			return (1);
		if (ft_strcmp(cmd, "export") == 0)
			return (1);
		if (ft_strcmp(cmd, "unset") == 0)
			return (1);
		if (ft_strcmp(cmd, "exit") == 0)
			return (1);
		if (ft_strcmp(cmd, "pwd") == 0)
			return (1);
		if (ft_strcmp(cmd, "cd") == 0)
			return (1);
		return (0);
}

char	*fetch_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	return (envp[i]);
}

void	error_command(char	*str)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(" : command not found\n", 2);
	exit(127);
}

char	*fetch_pathname(char	*cmd,	char	**envp)
{
	char	**path;
	char	*pathname;
	int		i;

	i = 0;
	if (!cmd)
		error_command(NULL);
	if (access(cmd, F_OK) == 0 && cmd[0] == '/')
		return (ft_strdup(cmd));
	path = ft_split(fetch_env_path(envp), ':');
	path[0] = ft_free_first(path[0], ft_strdup(ft_strrchr(path[0], '=') + 1));
	while (path[i])
	{
		pathname = ft_strjoin_char(path[i], cmd, '/');
		if (access(pathname, F_OK) == 0)
			break ;
		i++;
		free(pathname);
		if (path[i] == 0)
			error_command(cmd);
	}
	ft_free_split(path);
	return (pathname);
}

void	ft_execute(char **args, char **envp)
{
	char *path;

	if (args[0][0] == '/' || !ft_strncmp(args[0], "./", 2))
		path = ft_strdup(args[0]);
	else
		path = fetch_pathname(args[0], envp);		 
	execve(path, args, envp);
	perror("");
	exit(127);
}

void	exec_cmd(char **args, char **envp)
{
	//int pipe_fd[2];
	int fork_id[2];

	fork_id[0] = fork();
	if (fork_id[0] == 0)
	{
		ft_execute(args, envp);
	}
	else
		wait(NULL);
}

int main(int argc, char **argv, char **envp)
{
	char *str;
	int i;
	t_data *data;
    t_envp *env_list;

	i = 0;
	data = malloc(sizeof(t_data));
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
		data->arguments = ft_split(str, ' ');
		if (data->arguments[0] == NULL)
			continue;
		if (1 && is_builtin(data->arguments[0]))
			ft_builtins(data, &env_list);
		else
			exec_cmd(data->arguments, envp);

		//ft_free_split(str);
	}
}