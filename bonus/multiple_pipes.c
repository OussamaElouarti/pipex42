#include "pipex.h"

int	first(t_tokens *token)
{
	int	fd;

	fd = open(token->fileName, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("wsh: ", 2);
		ft_putstr_fd(token->fileName, 2);
		ft_putendl_fd(": No such file or directory ", 2);
		return (0);
	}
	dup2(fd, 0);
	dup2(token->std_out, 1);
	close(fd);
	close(token->std_out);
	close(token->next->std_in);
	return (1);
}

int	second(t_tokens *token)
{
	int	fd;

	fd = open(token->fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("wsh: ", 2);
		ft_putstr_fd(token->fileName, 2);
		ft_putendl_fd(": permisson denied", 2);
		return (0);
	}
	dup2(fd, 1);
	dup2(token->std_in, 0);
	close(fd);
	close(token->std_in);
	return (1);
}

void	child_exec(t_tokens *tokens, char **arr, int argc, char **args)
{
	int	ret;

	ret = 0;
	if (tokens->pos == 2)
		ret = first(tokens);
	if (tokens->std_in != 0 && tokens->pos != argc - 2 && tokens->pos != 2)
		dup2(tokens->std_in, 0);
	if (tokens->std_out != 1 && tokens->pos != argc - 2 && tokens->pos != 2)
	{
		close(tokens->next->std_in);
		dup2(tokens->std_out, 1);
		ret = 1;
	}
	else if (tokens->pos == argc - 2)
		ret = second(tokens);
	if (ret == 1)
	{
		execve(arr[0], arr, NULL);
		ft_error(arr[0], args[tokens->pos]);
		exit (ret);
	}
	exit(1);
}

void	freex(t_tokens *tokens)
{
	if (tokens)
	{
		free(tokens);
		tokens = NULL;
	}
}

void	exec_cmd(t_tokens *tokens, int argc, char **env, char **args)
{
	pid_t	pid;
	char	*path;
	char	**arr;

	arr = NULL;
	path = NULL;
	ft_path(tokens->cmds, &path, env);
	arr = ft_set_arr(path, tokens->cmds);
	pid = fork();
	if (pid == 0)
		child_exec(tokens, arr, argc, args);
	ft_free(arr);
	return ;
}
