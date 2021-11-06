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

void ft_export(char **args, t_envp **env_list)
{
    int i;

    i = 0;
    if (args[1] == NULL)
        print_exp(*env_list);
    // while (args[i])
    // {
    //     if (args[i][0] == '=')
    //         printf("bash: export: `%s`: not a valid identifier\n", args[i]);
    //     add_str_to_node(env_list, args[i]);
    //     i++;
    // }
}