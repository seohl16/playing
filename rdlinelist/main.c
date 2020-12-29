#include "get_next_line.h"

char *make_string_of(char c, int num)
{
	char *string;
	int i;

	if (num < 0)
		num = 1;
	if (!(string = malloc(num)))
		return (0);
	for (i = 0; i < num; i++)
		string[i] = c; 
	string[i] = '\0';
	return string;
}

int main(void)
{
	int japanfd; 
	int koreafd; 
	int resultfd; 
	char *string; 
	char *temp;
	int ret; 

	//japanfd = open("japan.txt", O_RDONLY); 
	//koreafd = open("korea.txt", O_RDONLY);
	//resultfd = open("result.txt", O_RDWR);
	japanfd = open("japan2.txt", O_RDONLY); 
	koreafd = open("korea2.txt", O_RDONLY);
	resultfd = open("result2.txt", O_RDWR);
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(koreafd, &string); 
		temp = make_string_of(' ', 20 - ft_strlen(string));
		string = ft_strjoin(string, temp);
		ret = get_next_line(japanfd, &temp);
		temp += 5;
		string = ft_strjoin(string, temp); 
		write(resultfd, string, ft_strlen(string));
		write(resultfd, "\n", 1);
		write(1, string, ft_strlen(string)); 
		write(1, "\n", 1);

	}
	close(japanfd);
	close(koreafd);
	close(resultfd);
	return (0); 
}
