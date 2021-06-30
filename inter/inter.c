#include <unistd.h>

int check (char *str, char c, int idx)
{
	int i;

	i = 0;
	while (i<idx)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0)
			{
				j = 0;
				while (argv[2][j])
				{
					if (argv[1][i] == argv[2][j])
					{
						write(1, &argv[1][i], 1);
						break;
					}
					j++;
				}
			}
			i++;
		}

	}
	write(1, &"\n", 1);
	return (0);

}
