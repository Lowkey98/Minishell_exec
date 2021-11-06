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

void ft_export(char **args, t_envp **env_list)
{
    int i;

    i = 1;
    if (args[1] == NULL)
        print_exp(*env_list);
    else
    {
        while (args[i])
        {
            add_to_env(env_list, args[i]);
            i++;
        }
    }
}