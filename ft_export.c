# include "minishell.h"

void print_exp(t_var *head) {
    t_var *current_node = head;
    char **key_value;

   	while (current_node != NULL)
    {
        ft_putstr_fd("declare -x ", 1);
        if (ft_strchr(current_node->var, '='))
        {
            if (*(ft_strchr(current_node->var, '=') + 1) == '\0')
            {
                ft_putstr_fd(current_node->var, 1);
                ft_putstr_fd("\"\"", 1);
            }
            else
            {
                key_value = ft_split(current_node->var, '=');
                ft_putstr_fd(key_value[0], 1);
                ft_putstr_fd("=\"", 1);
                ft_putstr_fd(ft_strchr(current_node->var, '=') + 1, 1);
                ft_putchar_fd('"', 1);
            }
        }
        else
            ft_putstr_fd(current_node->var, 1);
        ft_putchar_fd('\n', 1);
        current_node = current_node->next;
    }
}

void ft_export(char **args, t_var **env_list)
{
    int i;

    i = 0;
    if (args[1] == NULL)
        print_exp(*env_list);
    while (args[i])
    {
        if (args[i][0] == '=')
            printf("bash: export: `%s`: not a valid identifier\n", args[i]);
        add_str_to_node(env_list, args[i]);
        i++;
    }
    //printf("%s",args[0]);
    //print_strings(envp);
}