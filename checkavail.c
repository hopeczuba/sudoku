/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   availability.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:49:18 by hczuba            #+#    #+#             */
/*   Updated: 2016/07/24 20:49:58 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		row_col_check(int puzzle[][9], int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (i != row)
		{
			if (puzzle[i][col] == num)
			{
				return (0);
			}
		}
		if (i != col)
		{
			if (puzzle[row][i] == num)
				return (0);
		}
		i++;
	}
	return (1);
}

int		grid_check(int puzzle[][9], int row, int col, int num)
{
	int c;
	int r;
	int row_start;
	int col_start;

	row_start = (row / 3) * 3;
	col_start = (col / 3) * 3;
	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 3)
		{
			if ((row_start + r) != row && c != (col_start + c))
			{
				if (puzzle[row_start + r][col_start + c] == num)
					return (0);
			}
			c++;
		}
		r++;
	}
	return (1);
}

int		available(int puzzle[][9], int row, int col, int num)
{
	if (!(row_col_check(puzzle, row, col, num)))
		return (0);
	if (!(grid_check(puzzle, row, col, num)))
		return (0);
	return (1);
}