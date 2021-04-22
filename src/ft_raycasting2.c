/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:07:08 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 13:15:39 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mlx.addr + (y * game->mlx.line_length +
		x * (game->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_put_pixels(t_game *game)
{
	game->y = 0;
	while (game->y < game->draw_start)
	{
		ft_my_mlx_pixel_put(game, game->x, game->y, game->ceiling);
		game->y++;
	}
	while (game->y < game->draw_end)
	{
		game->tex[game->d].tex_y = (int)game->tex[game->d].tex_pos &
			(game->tex[game->d].height - 1);
		game->tex[game->d].tex_pos = game->tex[game->d].tex_pos +
			game->tex[game->d].step;
		game->tex[game->d].get_color = game->tex[game->d].addr +
			(game->tex[game->d].tex_y * game->tex[game->d].line_length +
			game->tex[game->d].tex_x * (game->tex[game->d].bits_per_pixel / 8));
		game->color = *(int*)game->tex[game->d].get_color;
		ft_my_mlx_pixel_put(game, game->x, game->y, game->color);
		game->y++;
	}
	while (game->y < game->height)
	{
		ft_my_mlx_pixel_put(game, game->x, game->y, game->floor);
		game->y++;
	}
}

void	ft_set_tex_vars(t_game *game)
{
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
	game->wall_x = game->wall_x - floor(game->wall_x);
	game->d = 3;
	if (game->side == 0 && game->ray_dir_x < 0)
		game->d = 0;
	else if (game->side == 0 && game->ray_dir_x > 0)
		game->d = 1;
	else if (game->side == 1 && game->ray_dir_y < 0)
		game->d = 2;
	else if (game->side == 1 && game->ray_dir_y > 0)
		game->d = 3;
	game->tex[game->d].tex_x = (int)(game->wall_x *
	(double)game->tex[game->d].width);
	if ((game->side == 0 && game->ray_dir_x > 0) ||
		(game->side == 1 && game->ray_dir_y < 0))
		game->tex[game->d].tex_x = game->tex[game->d].width -
		game->tex[game->d].tex_x - 1;
	game->tex[game->d].step = 1.0 * game->tex[game->d].height /
	game->line_height;
	game->tex[game->d].tex_pos = (game->draw_start - game->height /
	2 + game->line_height / 2) * game->tex[game->d].step;
}

void	ft_set_wall_height(t_game *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->map_x - game->pos_x +
		(1 - game->step_x) / 2) / game->ray_dir_x;
	else
		game->perp_wall_dist = (game->map_y - game->pos_y +
		(1 - game->step_y) / 2) / game->ray_dir_y;
	game->line_height = (int)(game->height / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + game->height / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->height / 2;
	if (game->draw_end >= game->height)
		game->draw_end = game->height - 1;
}