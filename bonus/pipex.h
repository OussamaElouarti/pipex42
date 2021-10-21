#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

typedef struct s_tokens
{
	char			*cmds;
	int				std_out;
	int				std_in;
	char			*fileName;
	int				pos;
	struct s_tokens	*next;
}				t_tokens;

char		*check_bin(char *cmd, char *command);
void		ft_path(char *argv, char **path, char **env);
void		ft_execve(char **args, char **env, int order, int fd[2]);
void		wsh_error_norm(int fd, char *path, char *command);
char		**ft_set_arr(char *path, char *argv);
int			first_cmd(int fd1[2]);
int			second_cmd(int fd1[2], char *fileName);
int			ft_error(char *path, char *command);
void		ft_exec_child(char **arr, int fd1[2], int order, char **args);
void		ft_free(char **data);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *str, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
void		ft_here_doc(char **argv);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		multiple_pipes(char **argv, char **env, int argc);
void		ft_pipe(t_tokens *tokens, int i, int argc, char *fileName);
void		exec_cmd(t_tokens *tokens, int argc, char **env, char **args);
t_tokens	*init_tokens(int pos, char *fileName);
void		freex(t_tokens *tokens);
#endif