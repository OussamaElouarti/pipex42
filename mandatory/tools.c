#include "pipex.h"

char	**ft_set_arr(char *path, char **argv, int order)
{
	int		j;
	char	**arr;
	char	*arg;
	char	*cmd;

	j = 1;
	arg = NULL;
	arr = NULL;
	if (!order)
		cmd = argv[2];
	else
		cmd = argv[3];
	if (cmd[0] != '\0')
	{
		arr = ft_split(cmd, ' ');
		free(arr[0]);
		arr[0] = path;
	}
	else
		arr = malloc(sizeof (char **) * 1024);
	return (arr);
}

int	first_cmd(int fd1[2], char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("wsh: ", 0);
		ft_putstr_fd(filename, 0);
		ft_putendl_fd(": No such file or directory", 0);
		return (0);
	}
	dup2(fd, 0);
	dup2(fd1[1], 1);
	close(fd);
	close(fd1[0]);
	return (1);
}

int	second_cmd(int fd1[2], char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("wsh: ", 0);
		ft_putstr_fd(filename, 0);
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
	int	fd;
	int	ret;

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
		ret = first_cmd(fd1, args[1]);
	else
		ret = second_cmd(fd1, args[4]);
	if (ret == 1)
	{
		execve(arr[0], arr, NULL);
		if (!order)
			ret = ft_error(arr[0], args[2]);
		else
			ret = ft_error(arr[0], args[3]);
		exit(ret);
	}
	exit(1);
}
