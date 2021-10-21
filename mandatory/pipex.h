#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

char	*check_bin(char *cmd, char *command);
void	ft_path(char *argv, char **path, char **env);
void	ft_execve(char **args, char **env, int order, int fd[2]);
void	wsh_error_norm(int fd, char *path, char *command);
char	**ft_set_arr(char *path, char **argv, int order);
int		first_cmd(int fd1[2], char *filename);
int		second_cmd(int fd1[2], char *filename);
int		ft_error(char *path, char *command);
void	ft_exec_child(char **arr, int fd1[2], int order, char **args);
void	ft_free(char **data);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
#endif