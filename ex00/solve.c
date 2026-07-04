/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:51:05 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 14:49:06 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_all_views(int grid[4][4], int views[16]);

int	is_valid_number(int grid[4][4], int row, int col, int nb)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == nb)
			return (0);
		if (grid[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[4][4], int views[16], int pos)
{
	int row;
	int col;
	int nb;

	if (pos == 16)
		return (check_all_views(grid, views));
	row = pos / 4;
	col = pos % 4;
	nb = 1;
	while (nb <= 4)
	{
		if (is_valid_number(grid, row, col, nb))
		{
			grid[row][col] = nb;
			if (solve(grid, views, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		nb++;
	}
	return(1);
}
