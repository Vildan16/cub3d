/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:27:27 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:54:36 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_get_nmb(char **line)
{
	int ret;

	ret = 0;
	while (ft_isdigit(**line))
	{
		ret = (ret * 10) + (**line - '0');
		(*line)++;
	}
	if (ret < 0)
		ret = 2147483647;
	return (ret);
}

void	ft_fill_line(t_cub *cub)
{
	while (cub->x < cub->longest_str + 2)
	{
		cub->map[cub->y][cub->x] = '#';
		cub->x++;
	}
}

int		ft_flood_fill(t_cub *cub, int x, int y)
{
	cub->target = '0';
	cub->replacement = 'x';
	cub->wall = '1';
	if (cub->map[y][x] == cub->wall ||
		cub->map[y][x] == cub->replacement)
		return (0);
	if (cub->map[y][x] != cub->target &&
		cub->map[y][x] != cub->player_dir &&
		cub->map[y][x] != '2')
		return (0);
	cub->map[y][x] = cub->replacement;
	ft_flood_fill(cub, x, y + 1);
	ft_flood_fill(cub, x, y - 1);
	ft_flood_fill(cub, x + 1, y);
	ft_flood_fill(cub, x - 1, y);
	return (0);
}

int		ft_find_startpos(t_cub *cub)
{
	cub->y = 0;
	while (cub->map[cub->y])
	{
		while (cub->map[cub->y][cub->x])
		{
			if (cub->map[cub->y][cub->x] == cub->player_dir)
			{
				cub->startpos_y = cub->y - 1;
				cub->startpos_x = cub->x - 1;
				return (1);
			}
			cub->x++;
		}
		cub->y++;
		cub->x = 0;
	}
	return (1);
}

void	ft_get_line(t_cub *cub)
{
	if (cub->map_str[cub->map_i] == ',')
		cub->map_i++;
	while (cub->map_str[cub->map_i] != ',')
	{
		if (cub->x == 0)
		{
			cub->map[cub->y][cub->x] = '#';
			cub->x++;
		}
		cub->map[cub->y][cub->x] = cub->map_str[cub->map_i];
		cub->map_i++;
		cub->x++;
	}
	while (cub->x < cub->longest_str + 2)
	{
		cub->map[cub->y][cub->x] = '#';
		cub->x++;
	}
}
