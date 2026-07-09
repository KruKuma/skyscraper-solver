/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 09:54:47 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 11:53:21 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error(void);
void	print_grid(int grid[9][9]);
int		parse_input(char *str, int views[36], int *size);
int		init_grid(int grid[9][9]);
int		solve(int grid[9][9], int views[36], int pos);

int	main(int argc, char *argv[])
{
	int	grid[9][9];
	int	views[36];
	int size;

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], views, &size))
	{
		print_error();
		return (1);
	}
	init_grid(grid);
	if (!solve(grid, views, 0))
	{
		print_error();
		return (1);
	}
	print_grid(grid);
	return (0);
}
