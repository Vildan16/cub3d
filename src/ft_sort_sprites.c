/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:35:31 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 11:37:51 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

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