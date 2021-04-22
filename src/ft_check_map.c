/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:06:09 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:53:24 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	ft_check_sides(t_cub *cub)
{
	if ((cub->map[cub->y - 1][cub->x - 1] != '1' &&
	cub->map[cub->y - 1][cub->x - 1] != 'x') ||
	(cub->map[cub->y - 1][cub->x] != '1' &&
	cub->map[cub->y - 1][cub->x] != 'x') ||
	(cub->map[cub->y - 1][cub->x + 1] != '1' &&
	cub->map[cub->y - 1][cub->x + 1] != 'x') ||
	(cub->map[cub->y][cub->x - 1] != '1' &&
	cub->map[cub->y][cub->x - 1] != 'x') ||
	(cub->map[cub->y][cub->x + 1] != '1' &&
	cub->map[cub->y][cub->x + 1] != 'x') ||
	(cub->map[cub->y + 1][cub->x - 1] != '1' &&
	cub->map[cub->y + 1][cub->x - 1] != 'x') ||
	(cub->map[cub->y + 1][cub->x] != '1' &&
	cub->map[cub->y + 1][cub->x] != 'x') ||
	(cub->map[cub->y + 1][cub->x + 1] != '1' &&
	cub->map[cub->y + 1][cub->x + 1] != 'x'))
		ft_print_error("Map is not closed\n");
	return (1);
}

int			ft_check_map(t_cub *cub)
{
	cub->x = 0;
	cub->y = 0;
	while (cub->map[cub->y])
	{
		while (cub->map[cub->y][cub->x])
		{
			if (cub->map[cub->y][cub->x] == 'x')
			{
				if (ft_check_sides(cub) != 1)
					return (-1);
			}
			cub->x++;
		}
		cub->x = 0;
		cub->y++;
	}
	return (1);
}
