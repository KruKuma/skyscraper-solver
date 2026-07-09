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

int	parse_input(char *str, int views[36], int *size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (count >= 36)
			return (0);
		if (str[i] < '1' || str[i] > '9')
			return (0);
		views[count] = str[i] - '0';
		count++;
		i++;
		if (str[i] == '\0')
			break ;
		if (str[i] != ' ')
			return (0);
		i++;
		if (str[i] == '\0')
			return (0);
	}
	if (count % 4 != 0)
		return (0);
	*size = count / 4;
	if (*size < 4 || *size > 9)
		return (0);
	i = 0;
	while (i < count)
	{
		if (views[i] > *size)
			return (0);
		i++;
	}
	return (1);
}
