#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char *ft_aux(char *s,  int c)
{
	int i;
	char *str;
	
	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(i+2)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free (s);
	return (str);
}	

int get_next_line(char **line)
{
	char buffer;
	int flag;

	if (!line || (!(*line = malloc(1))))
		return (-1);
	*line[0] = '\0';
	while ((flag = read(0, &buffer, 1) > 0))
	{
		if (buffer == '\n')
			break;
		*line = ft_aux(*line, buffer);
	}
	return (flag);
}
/*
int main(void)
{
	char *line;

	while (get_next_line(&line))
		printf("%s\n", line);
	return (0);
}
*/
