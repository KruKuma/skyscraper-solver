/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 10:37:50 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 11:06:35 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_input(char *str, int views[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (count >= 16)
			return (0);
		if (str[i] < '1' || str[i] > '4')
			return (0);
		views[count] = str[i] - '0';
		count++;
		i++;
		if (count < 16)
		{
			if (str[i] != ' ')
				return (0);
			i++;
		}
	}
	if (count != 16)
		return (0);
	return (1);
}
