# include "minishell.h"

void    fill_env_list(t_var ** env_list, char **envp)
{
	int i;

	i = 0;
	t_var *tmp;
	tmp = (*env_list);

    while (envp[i])
	{
		(*env_list) = malloc(sizeof(t_var));
		(*env_list)->var = ft_strdup(envp[i]);
		//break;
		//printf("%d-%s\n",i,(*env_list)->var);
		i++;
		(*env_list)->next = (*env_list);
		//*env_list->var = ft_strdup(envp[i]);
	}
	(*env_list) = tmp;
}



void	add_str_to_node(t_var **head, char *str)
{
	t_var *node;

	t_var *tmp;

	tmp = (*head);
	node = malloc(sizeof(t_var));
	node->var = str;
	node->next = NULL;
	if (tmp == NULL)
	{
		*head = node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	//printf("%s",tmp->var);
	//(*head) = tmp;
}

int main(int argc, char **argv, char **envp)
{
	
	char **tab;
	char *str;
	int i;

	i = 0;
	// str = malloc(3);
	// str[0] = "-n-n";
	// str[1] = "world ";
	// str[2] = 0;
	// ft_echo(str);
	// return (0);
    t_var *env_list;

	while(envp[i])
	{
		add_str_to_node(&env_list, envp[i]); 
		i++;
	}
	//printl(env_list);
    //fill_env_list(&env_list, envp);
	// if (env_list != NULL)
	// 	printf("%s", env_list->var);
	if (argc != 1 && !argv[0]) 
        return(-1);
	while(1)
	{
		str = readline("shell>");
		add_history(str);
		tab = ft_split(str, ' ');
		//printf("%s",tab[0]);
		// if (ft_strncmp(tab[0],"export", ft_strlen(tab[0])) == 0)
		// 	ft_export(env_list);
		if (ft_strncmp(tab[0],"echo", ft_strlen(tab[0])) == 0)
		{	
			//printf("hello\n");
			ft_echo(tab);
		}
		if (ft_strncmp(tab[0],"env", ft_strlen(tab[0])) == 0)
			ft_env(env_list);
		if (ft_strncmp(tab[0], "export", ft_strlen(tab[0])) == 0)
			ft_export(tab, &env_list);
	}
}