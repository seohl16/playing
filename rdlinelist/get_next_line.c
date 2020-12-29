#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		len;
	int		i;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = ft_strcpy(ret, s1);
	free(s1);
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
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
