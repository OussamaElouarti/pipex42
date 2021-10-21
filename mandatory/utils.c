#include "pipex.h"

void	wsh_error_norm(int fd, char *path, char *command)
{
	int	i;

	i = 0;
	ft_putstr_fd("wsh: ", 2);
	if (path && !(ft_strncmp(path, "error", 6)))
	{
		ft_putstr_fd(command, 2);
		ft_putendl_fd(": No such file or directory", 2);
		i = 1;
	}
	else if (fd == -1)
		path = command;
	if (i == 0)
		ft_putstr_fd(path, 2);
	if ((ft_strchr(path, '/')) == NULL && i == 0)
		ft_putendl_fd(": command not found", 2);
	else if (fd == -1 && i == 0)
		ft_putendl_fd(": No such file or directory", 2);
	else if (fd == -1 && i == 0)
		ft_putendl_fd(": is a directory", 2);
	else if (fd != -1 && i == 0)
		ft_putendl_fd(": Permission denied", 2);
}

void	ft_free(char **data)
{
	int	counter;

	counter = 0;
	if (data != NULL)
	{
		while (data[counter] && data[counter][0] != '\0')
		{
			free(data[counter++]);
			data[counter - 1] = NULL;
		}
		free(data);
		data = NULL;
	}
	return ;
}
