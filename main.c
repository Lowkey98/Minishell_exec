# include "minishell.h"

void    fill_env_list(t_envp ** env_list, char **envp)
{
	int i;

	i = 0;
	t_envp *tmp;
	tmp = (*env_list);

    while (envp[i])
	{
		(*env_list) = malloc(sizeof(t_envp));
		(*env_list)->key = ft_strdup(envp[i]);
		//break;
		//printf("%d-%s\n",i,(*env_list)->var);
		i++;
		(*env_list)->next = (*env_list);
		//*env_list->var = ft_strdup(envp[i]);
	}
	(*env_list) = tmp;
}


t_envp*	fill_envp(char *str)
{
	t_envp *node;

	node = malloc(sizeof(t_envp));

	if (ft_strchr(str, '='))
	{
		node->equal = 1;
		node->key = ft_substr(str, 0, ft_indexof(str, '='));
		if (*(ft_strchr(str,'=') + 1))
			node->value = ft_strdup(ft_strchr(str,'=') + 1);
		else
			node->value = 0;
	}
	else
	{
		node->equal = 0;
		node->key = ft_strdup(str);
		node->value = 0;
	}

	return node;
}
void	add_to_env(t_envp **head, char *str)
{
	t_envp *node;

	t_envp *tmp;

	tmp = (*head);
	node = fill_envp(str);
	// if empty
	if (tmp == NULL)
	{
		*head = node;
		return ;
	}
	
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

int main(int argc, char **argv, char **envp)
{
	// t_envp *test;
	// if (argc > 0)
	// {
	// 	test = fill_envp(argv[1]);
	// 	printf("key = %s\n",test->key);
	// 	printf("equal = %d\n",test->equal);
	// 	if (test->value)
	// 		printf("value = %s\n",test->value);
	// 	else
	// 		printf("value = %p\n", test ->value);
	// }
	char *str;
	int i;
	t_data data;

	i = 0;
    t_envp *env_list;
	while(envp[i])
	{
		add_to_env(&env_list, envp[i]); 
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
	}

}