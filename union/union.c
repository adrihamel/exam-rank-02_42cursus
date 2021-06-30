#include <unistd.h>

int check(char *str, char c, int id)
{
	int i;
	i = 0;
	while (i < id)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
int main (int argc, char *argv[])
{
	int i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			j = 0;
			while (argv[1][j])
			{
				if (argv[1][j] == argv[2][i])
					break;
				j++;
			}
			if (argv[1][j] != '\0')
			{
				i++;
				continue;
			}
			j = 0;
			while (j < i)
			{
				if (argv[2][i] == argv[2][j])
					break;
				j++;
			}
			if (j == i)
				write(1, &argv[2][j], 1);
			i++;
		}
	}
	write(1, &"\n", 1);
	return (0);

}

