#include <unistd.h>

int		available(int puzzle[][9], int row, int col, int num);

void	display(int puzzle[][9])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = (puzzle[i][j] + '0');
			write(1, " ", 1);
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n\0", 1);
		i++;
	}
}

int		safe_entry(int puzzle[][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (puzzle[i][j] != 0)
			{
				if (!(available(puzzle, i, j, puzzle[i][j])))
				{
					write(1, "Error\n\0", 6);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		input_data(int puzzle[][9], char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i + 1][j] == 46)
				puzzle[i][j] = 0;
			else if ((argv[i + 1][j] > 57 || argv[i + 1][j] < 48))
			{
				write(1, "Error\n\0", 6);
				return (0);
			}
			else
				puzzle[i][j] = (argv[i + 1][j] - 48);
			j++;
		}
		i++;
	}
	return (1);
}