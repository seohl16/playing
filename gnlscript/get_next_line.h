#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 25
#endif


int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);

#endif
