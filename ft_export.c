# include "minishell.h"

void print_exp(t_envp *head) {
    t_envp *current_node;
    
    current_node = head;

   	while (current_node != NULL)
    {
        ft_putstr_fd("declare -x ", 1);
        ft_putstr_fd(current_node->key, 1);
        if (current_node->equal)
        {
            ft_putstr_fd("=\"", 1);
            if (current_node->value)
                ft_putstr_fd(current_node->value, 1);
            ft_putstr_fd("\"", 1);
        }
        ft_putstr_fd("\n", 1);
        current_node = current_node->next;
        // if ()
        // {
        //     if (*(ft_strchr(current_node->var, '=') + 1) == '\0')
        //     {
        //         ft_putstr_fd(current_node->var, 1);
        //         ft_putstr_fd("\"\"", 1);
        //     }
        //     else
        //     {
        //         key_value = ft_split(current_node->var, '=');
        //         ft_putstr_fd(key_value[0], 1);
        //         ft_putstr_fd("=\"", 1);
        //         ft_putstr_fd(ft_strchr(current_node->var, '=') + 1, 1);
        //         ft_putchar_fd('"', 1);
        //     }
        // }
        // else
        //     ft_putstr_fd(current_node->var, 1);
        // ft_putchar_fd('\n', 1);
    }
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
	node->next=NULL;
	return node;
}

int     env_key_error(char *var)
{
    int i;

    i = 1;
    if (!ft_isalpha(var[0]) && var[0] != '_')
        return (1);
    while (var[i])
    {
        if (!ft_isalnum(var[i]) && var[i] != '_')
            return (1);
        i++;
    }
    return(0);
}

void	add_to_env(t_envp **head, t_envp *node)
{
	t_envp *tmp;

	tmp = (*head);
	//printf("%s\n", node->key);
	if (tmp == NULL)
	{
		*head = node;
		return;
	}
	//printf("test\n");
	while (tmp != NULL)
	{
			//printf("%s\n", tmp->key);
		//printf("%d\n",ft_strncmp(tmp->key, node->key,ft_strlen(node->key)));
		if (!strcmp(node->key, tmp->key))
		{
			//printf("hello\n");
			if (node->equal)
			{
				tmp->equal = 1;
				tmp->value = ft_free_first(tmp->value, ft_strdup_null(node->value));
			}
			free(node->value);
			free(node->key);
			free(node);
			return ;
		}
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	tmp->next = node;
}

void ft_export(char **args, t_envp **env_list)
{
    int i;
	t_envp *node;


    i = 1;
    if (args[1] == NULL)
        print_exp(*env_list);
    else
    {
        while (args[i])
        {
            node = fill_envp(args[i]);
            if (env_key_error(node->key))
                printf("bash: export: `%s`: not a valid identifier\n", args[i]);
            add_to_env(env_list, node);
            i++;
        }
    }
}