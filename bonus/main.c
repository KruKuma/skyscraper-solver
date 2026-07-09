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
void	print_grid(int grid[4][4]);
int		parse_input(char *str, int views[16]);
int		init_grid(int grid[4][4]);
int		solve(int grid[4][4], int views[16], int pos);

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	views[16];

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], views))
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
