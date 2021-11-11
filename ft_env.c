# include "minishell.h"

void print_env(t_envp **head)
{
    t_envp *current_node = (*head);
   	while ( current_node != NULL)
    {
        if (current_node->equal)
        {

            ft_putstr_fd(current_node->key, 1);
            ft_putstr_fd("=", 1);
        }
        if (current_node->value)
            ft_putstr_fd(current_node->value, 1);
        ft_putstr_fd("\n", 1);
        current_node = current_node->next;
    }
}

void    ft_env(t_data *data, t_envp **env_list)
{
    (void) data;
    print_env(env_list);
}