/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:35:31 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 13:29:21 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

static void	ft_swap(t_sprite_pos *num, t_sprite_pos *num1)
{
	t_sprite_pos	tmp;

	tmp = *num;
	*num = *num1;
	*num1 = tmp;
}

static void	ft_sort(t_game *game)
{
	int i;
	int j;
	int	max_idx;

	i = 0;
	while (i < game->num_sprite - 1)
	{
		max_idx = i;
		j = i + 1;
		while (j < game->num_sprite)
		{
			if (game->sprite_pos[j].dist > game->sprite_pos[max_idx].dist)
				max_idx = j;
			j++;
		}
		ft_swap(&game->sprite_pos[max_idx], &game->sprite_pos[i]);
		i++;
	}
}

void		ft_sort_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_sprite)
	{
		game->sprite_pos[i].dist = ((game->pos_x - (game->sprite_pos[i].x)) *
		(game->pos_x - (game->sprite_pos[i].x)) + (game->pos_y -
		(game->sprite_pos[i].y)) * (game->pos_y - (game->sprite_pos[i].y)));
		i++;
	}
	ft_sort(game);
}


static void	ft_get_sprite_coordinates(t_game *game)
{
	game->sprite_pos[game->i].y = game->x + 0.5;
	game->sprite_pos[game->i].x = game->y + 0.5;
	game->i++;
}

void		ft_get_sprite_pos(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->i = 0;
	if (game->num_sprite > 0)
	{
		game->sprite_pos = ft_calloc(game->num_sprite + 1,
		sizeof(t_sprite_pos));
		if (game->sprite_pos == NULL)
			ft_print_error("Memory allocation error\n");
		while (game->map[game->y])
		{
			game->x = 0;
			while (game->map[game->y][game->x])
			{
				if (game->map[game->y][game->x] == '2')
					ft_get_sprite_coordinates(game);
				game->x++;
			}
			game->y++;
		}
	}
}