#include "pipex.h"

char	*check_bin(char *cmd, char *command)
{
	int		fd;
	char	*path;
	char	*com;
	char	*tmp;

	path = NULL;
	tmp = ft_strjoin(cmd, "/");
	com = ft_strjoin(tmp, command);
	fd = open(com, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		free(com);
		return (NULL);
	}
	path = com;
	close(fd);
	free(tmp);
	return (path);
}

void	ft_path(char *argv, char **path, char **env)
{
	int		i;
	char	**cmd;
	char	*tmp;
	char	**command;

	i = 0;
	tmp = NULL;
	command = ft_split(argv, ' ');
	while (env && env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	cmd = ft_split(env[i], ':');
	if (command[0] && command[0][0] == '/' && !(*path))
		*path = ft_strdup(command[0]);
	else if (cmd)
	{
		*path = check_bin(cmd[0] + 5, command[0]);
		i = 0;
		while (command[0] && cmd[i] && *path == NULL)
			*path = check_bin(cmd[i++], command[0]);
	}
	else if (*path == NULL && !cmd)
		*path = ft_strdup("error");
	free(tmp);
	ft_free(command);
	ft_free(cmd);
}

void	ft_execve(char **args, char **env, int order, int fd[2])
{
	char	*path;
	char	**arr;
	pid_t	pid;

	arr = NULL;
	path = NULL;
	if (order == 0)
		ft_path(args[2], &path, env);
	else if (order == 1)
		ft_path(args[3], &path, env);
	arr = ft_set_arr(path, args, order);
	pid = fork();
	if (pid == 0)
		ft_exec_child(arr, fd, order, args);
	ft_free(arr);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	pip[2];
	int	statval;
	int	ret;

	i = 0;
	ret = 0;
	statval = 0;
	if (argc == 5)
	{
		pipe(pip);
		ft_execve(argv, env, 0, pip);
		close(pip[1]);
		ft_execve(argv, env, 1, pip);
		close(pip[0]);
		while (wait(&statval) > 0)
			if (WIFEXITED(statval))
				ret = WEXITSTATUS(statval);
	}
	else
		write(1, "args eroor!\n", 11);
	return (ret);
}
