#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int ret = 1;
	fd = open("script.txt", O_RDONLY);
	char *line;
	int num = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		write(1, line, ft_strlen(line));
		if (num++ % 2 == 0)
			write(1, " ", 1);
	}
}
