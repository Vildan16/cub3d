/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:23:49 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:57:58 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_set_camera(t_game *game)
{
	game->camera_x = 2 * game->x / (double)game->width - 1;
	if (game->set_camera == 1)
	{
		game->ray_dir_y = game->dir_y + game->plane_y * -game->camera_x;
		game->ray_dir_x = game->dir_x + game->plane_x * -game->camera_x;
	}
	else
	{
		game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
		game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	}
	game->map_y = (int)game->pos_y;
	game->map_x = (int)game->pos_x;
}

static void	ft_set_delta_dist(t_game *game)
{
	if (game->ray_dir_y == 0)
		game->delta_dist_x = 0;
	else if (game->ray_dir_x == 0)
		game->delta_dist_x = 1;
	else
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
	if (game->ray_dir_x == 0)
		game->delta_dist_y = 0;
	else if (game->ray_dir_y == 0)
		game->delta_dist_y = 1;
	else
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
}

static void	ft_set_side_dist(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x) *
			game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x) *
			game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) *
			game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y) *
			game->delta_dist_y;
	}
}

static void	ft_find_wall(t_game *game)
{
	game->hit = 0;
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x = game->side_dist_x + game->delta_dist_x;
			game->map_x = game->map_x + game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y = game->side_dist_y + game->delta_dist_y;
			game->map_y = game->map_y + game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_x][game->map_y] == '1')
			game->hit = 1;
	}
}

int			ft_render_next_frame(t_game *game)
{
	game->z_buffer = ft_calloc(game->width, sizeof(double));
	if (game->z_buffer == NULL)
		ft_print_error("Memory allocation error");
	game->x = 0;
	while (game->x < game->width)
	{
		ft_set_camera(game);
		ft_set_delta_dist(game);
		ft_set_side_dist(game);
		ft_find_wall(game);
		ft_set_wall_height(game);
		ft_set_tex_vars(game);
		ft_put_pixels(game);
		game->z_buffer[game->x] = game->perp_wall_dist;
		game->x++;
	}
	ft_set_sprite(game, game->z_buffer);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	if (game->save_flag == 0)
		ft_get_new_img(game);
	ft_player_move(game);
	return (1);
}
