#include "pipex.h"

char	**ft_set_arr(char *path, char *argv)
{
	int		j;
	char	**arr;
	char	*arg;
	char	*cmd;

	j = 1;
	arg = NULL;
	cmd = argv;
	if (cmd[0] != '\0')
	{
		arr = ft_split(cmd, ' ');
		free(arr[0]);
		arr[0] = path;
	}
	else
	{
		arr = malloc(sizeof (char **) * 1024);
		arr[0] = ft_strdup("err");
	}
	return (arr);
}

int	first_cmd(int fd1[2])
{
	int	fd;

	fd = open("/tmp/herDoc", O_RDONLY);
	dup2(fd, 0);
	dup2(fd1[1], 1);
	close(fd);
	unlink("/tmp/herDoc");
	close(fd1[0]);
	return (1);
}

int	second_cmd(int fd1[2], char *fileName)
{
	int	fd;

	fd = open(fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("wsh: ", 0);
		ft_putstr_fd(fileName, 0);
		ft_putendl_fd(": permisson denied", 0);
		return (0);
	}
	dup2(fd, 1);
	dup2(fd1[0], 0);
	close(fd);
	close(fd1[0]);
	close(fd1[1]);
	return (1);
}

int	ft_error(char *path, char *command)
{
	int			fd;
	int			ret;

	fd = open(path, O_WRONLY);
	wsh_error_norm(fd, path, command);
	if ((path && ft_strchr(path, '/') == NULL) || (fd == -1))
		ret = 127;
	else
		ret = 126;
	close(fd);
	return (ret);
}

void	ft_exec_child(char **arr, int fd1[2], int order, char **args)
{
	int	ret;

	ret = 0;
	if (!order)
		ret = first_cmd(fd1);
	else
		ret = second_cmd(fd1, args[5]);
	if (ret == 1)
	{
		execve(arr[0], arr, NULL);
		if (!order)
			ret = ft_error(arr[0], args[3]);
		else
			ret = ft_error(arr[0], args[4]);
		exit(ret);
	}
	exit(1);
}
