# include "minishell.h"

void print_env(t_var *head) {
    t_var *current_node = head;
   	while ( current_node != NULL) {
        if (ft_strchr(current_node->var,'='))
            printf("%s \n", current_node->var);
        current_node = current_node->next;
    }
}

void    ft_env(t_var *var)
{
    print_env(var);
}