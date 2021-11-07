# include "minishell.h"

void	ft_cd(char **args)
{
	//char buf[100];
	if (args[1] == NULL)
		chdir("/Users/ayafdel");
	else
	{
		if (chdir(args[1]) == -1)
		{
			ft_putstr_fd("bash: cd: ", 1);
			ft_putstr_fd(args[1], 1);
			//ft_putstr_fd(" ", 1);
			perror(" ");
		}
		//printf("%s\n",getcwd(buf, sizeof(buf)));
	}
}