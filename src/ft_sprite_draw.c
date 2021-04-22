/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:45:47 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 16:00:03 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_sprite_pixel_put(t_game *game)
{
	int y;
	int d;

	y = game->sprite.draw_start_y;
	while (y < game->sprite.draw_end_y)
	{
		d = (y - game->sprite.screen_pos) * 256 -
		game->height * 128 + game->sprite.height * 128;
		game->tex[4].tex_y = ((d * game->tex[4].height) /
		game->sprite.height) / 256;
		game->tex[4].get_color = game->tex[4].addr +
		(game->tex[4].line_length * game->tex[4].tex_y +
		game->tex[4].tex_x * (game->tex[4].bits_per_pixel / 8));
		game->color = *(unsigned int*)game->tex[4].get_color;
		if (game->color != 0xFF000000 && game->color != 0)
			ft_my_mlx_pixel_put(game, game->sprite.draw_start_x,
			y, game->color);
		y++;
	}
}

void		ft_sprite_draw(t_game *game, double *z_buffer)
{
	while (game->sprite.draw_start_x < game->sprite.draw_end_x)
	{
		game->tex[4].tex_x = (int)(256 * (game->sprite.draw_start_x -
		(-game->sprite.width / 2 + game->sprite.center_x)) *
		game->tex[4].width / game->sprite.width) / 256;
		if (game->sprite.draw_start_x > 0 &&
			game->sprite.draw_start_x < game->width &&
			game->sprite.ahead_behind > 0 &&
			game->sprite.ahead_behind < z_buffer[game->sprite.draw_start_x])
			ft_sprite_pixel_put(game);
		game->sprite.draw_start_x++;
	}
}
