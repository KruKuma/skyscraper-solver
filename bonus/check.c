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

int	count_visible(int line[4])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
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

int	check_row(int grid[4][4], int row, int left, int right)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (count_visible(line) != left)
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][3 - i];
		i++;
	}
	if (count_visible(line) != right)
		return (0);
	return (1);
}

int	check_col(int grid[4][4], int col, int top, int bottom)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (count_visible(line) != top)
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[3 - i][col];
		i++;
	}
	if (count_visible(line) != bottom)
		return (0);
	return (1);
}

int	check_all_views(int grid[4][4], int views[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col(grid, i, views[i], views[i + 4]))
			return (0);
		if (!check_row(grid, i, views[i + 8], views[i + 12]))
			return (0);
		i++;
	}
	return (1);
}
