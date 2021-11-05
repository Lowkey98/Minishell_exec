# include "minishell.h"

void	ft_cd(char *path)
{
	char buf[100];
	if (chdir(path) == -1)
	{
		printf("bash: cd: %s", path);
		perror("");
	}
	printf("%s\n",getcwd(buf, sizeof(buf)));
	
}