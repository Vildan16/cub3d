/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:17:30 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 13:45:23 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_sprite_modify_pos(t_game *game, int i)
{
	game->sprite.x = (game->sprite_pos[i].x) - game->pos_x;
	game->sprite.y = (game->sprite_pos[i].y) - game->pos_y;
	game->sprite.inv = 1.0 / (game->plane_x *
	game->dir_y - game->dir_x * game->plane_y);
	if (game->player_dir == 'S' || game->player_dir == 'W')
		game->sprite.right_left = (game->sprite.inv *
		(game->dir_y * game->sprite.x - game->dir_x *
		game->sprite.y) * -1);
	else
		game->sprite.right_left = game->sprite.inv *
		(game->dir_y * game->sprite.x - game->dir_x *
		game->sprite.y);
	game->sprite.ahead_behind = game->sprite.inv *
	(-game->plane_y * game->sprite.x + game->plane_x *
	game->sprite.y);
	game->sprite.center_x = (int)(game->width / 2) *
	(1 + game->sprite.right_left / game->sprite.ahead_behind);
	game->sprite.screen_pos = (int)(0 / game->sprite.ahead_behind);
}

static void	ft_sprite_set_height(t_game *game)
{
	game->sprite.height = abs((int)(game->height /
	(game->sprite.ahead_behind))) / 1;
	game->sprite.draw_start_y = game->height / 2 -
	game->sprite.height / 2 + game->sprite.screen_pos;
	if (game->sprite.draw_start_y < 0)
		game->sprite.draw_start_y = 0;
	game->sprite.draw_end_y = game->height / 2 +
	game->sprite.height / 2 + game->sprite.screen_pos;
	if (game->sprite.draw_end_y >= game->height)
		game->sprite.draw_end_y = game->height - 1;
}

static void	ft_sprite_set_width(t_game *game)
{
	game->sprite.width = (int)(game->sprite.height *
	((double)game->tex[4].width / (double)game->tex[4].height)) / 1;
	game->sprite.draw_start_x = -game->sprite.width / 2 + game->sprite.center_x;
	if (game->sprite.draw_start_x < 0)
		game->sprite.draw_start_x = 0;
	game->sprite.draw_end_x = game->sprite.width / 2 + game->sprite.center_x;
	if (game->sprite.draw_end_x >= game->width)
		game->sprite.draw_end_x = game->width - 1;
}

void		ft_set_sprite(t_game *game, double *z_buffer)
{
	int	i;

	i = 0;
	ft_sort_sprites(game);
	while (i < game->num_sprite)
	{
		ft_sprite_modify_pos(game, i);
		ft_sprite_set_height(game);
		ft_sprite_set_width(game);
		ft_sprite_draw(game, z_buffer);
		i++;
	}
	free(game->z_buffer);
}
