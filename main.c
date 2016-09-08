/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:54:44 by hczuba            #+#    #+#             */
/*   Updated: 2016/07/24 20:54:48 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		row_col_check(int puzzle[][9], int row, int col, int num);
int		grid_check(int puzzle[][9], int row, int col, int num);
int		available(int puzzle[][9], int row, int col, int num);
void	display(int puzzle[][9]);
int		safe_entry(int puzzle[][9]);
int		input_data(int puzzle[][9], char **argv);

int		find_empty_location(int puzzle[][9], int *row, int *col)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (puzzle[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		solve_sudoku(int puzzle[][9])
{
	int row;
	int col;
	int guess;

	row = 0;
	col = 0;
	if (find_empty_location(puzzle, &row, &col) == 0)
	{
		return (1);
	}
	guess = 1;
	while (guess <= 9)
	{
		if (available(puzzle, row, col, guess))
		{
			puzzle[row][col] = guess;
			if (solve_sudoku(puzzle) == 1)
				return (1);
			puzzle[row][col] = 0;
		}
		guess++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int puzzle[9][9];

	if (argc != 10)
	{
		write(1, "Error\n\0", 6);
		return (0);
	}
	input_data(puzzle, argv);
	if (safe_entry(puzzle))
	{
		solve_sudoku(puzzle);
		display(puzzle);
	}
	else
		write(1, "Error\n\0", 6);
	return (0);
}
