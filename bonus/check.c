/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:49:32 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 16:24:36 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int line[9], int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_row(int grid[9][9], int row, int left, int right, int size)
{
	int	line[9];
	int	i;

	i = 0;
	while (i < size)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (count_visible(line, size) != left)
		return (0);
	i = 0;
	while (i < size)
	{
		line[i] = grid[row][size - 1 - i];
		i++;
	}
	if (count_visible(line, size) != right)
		return (0);
	return (1);
}

int	check_col(int grid[9][9], int col, int top, int bottom, int size)
{
	int	line[9];
	int	i;

	i = 0;
	while (i < size)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (count_visible(line, size) != top)
		return (0);
	i = 0;
	while (i < size)
	{
		line[i] = grid[size - 1 - i][col];
		i++;
	}
	if (count_visible(line, size) != bottom)
		return (0);
	return (1);
}

int	check_all_views(int grid[9][9], int views[36], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!check_col(grid, i, views[i], views[i + size], size))
			return (0);
		if (!check_row(grid, i, views[i + size * 2], views[i + size * 3], size))
			return (0);
		i++;
	}
	return (1);
}
