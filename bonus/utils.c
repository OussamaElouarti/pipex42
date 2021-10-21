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

void	ft_here_doc(char **argv)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open("/tmp/herDoc", O_RDONLY | O_WRONLY | O_CREAT, 0644);
	while (get_next_line(0, &buffer) > 0)
	{
		if (!ft_strncmp(buffer, argv[2], ft_strlen(buffer)))
			break ;
		else
			ft_putendl_fd(buffer, fd);
		free(buffer);
	}
	free(buffer);
}

t_tokens	*init_tokens(int pos, char *fileName)
{
	t_tokens	*tmp;

	tmp = malloc(sizeof(t_tokens));
	tmp->std_in = 0;
	tmp->fileName = fileName;
	tmp->pos = pos;
	tmp->std_out = 1;
	return (tmp);
}

void	multiple_pipes(char **argv, char **env, int argc)
{
	t_tokens	*tokens;
	t_tokens	*before;
	int			i;

	i = 2;
	tokens = init_tokens(2, argv[1]);
	while (i < argc - 1)
	{
		tokens->cmds = argv[i];
		if (i != argc - 2)
			ft_pipe(tokens, argc - 1, i, argv[argc - 1]);
		exec_cmd(tokens, argc, env, argv);
		if (tokens->std_out != 1)
			close(tokens->std_out);
		if (tokens->std_in != 0)
			close(tokens->std_in);
		before = tokens;
		tokens = tokens->next;
		freex(before);
		i++;
	}
	while (wait(0) > 0)
	{
	}
}
