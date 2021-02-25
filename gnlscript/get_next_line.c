#include "get_next_line.h"

int			is_newline(char *save)
{
	int i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			pop_line(char **save, char **line, int idx)
{
	char	*temp;
	int		len;

	(*save)[idx] = '\0';
	*line = ft_strdup(*save);
	len = ft_strlen(*save + idx + 1);
	if (len == 0)
	{
		free(*save);
		*save = 0;
		return (1);
	}
	temp = ft_strdup(*save + idx + 1);
	free(*save);
	*save = temp;
	return (1);
}

int			return_zero(char **save, char **line)
{
	int idx;

	if (*save && ((idx = is_newline(*save)) >= 0))
		return (pop_line(save, line, idx));
	if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *save[10240];
	char		buf[BUFFER_SIZE + 1];
	int			read_output;
	int			idx;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_output = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_output] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
		idx = is_newline(save[fd]);
		if (idx >= 0)
			return (pop_line(&save[fd], line, idx));
	}
	if (read_output < 0)
		return (-1);
	return (return_zero(&save[fd], line));
}
