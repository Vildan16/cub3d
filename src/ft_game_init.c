/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:23:51 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:53:54 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_set_screen_size(t_game *game, t_cub *cub)
{
	int w;
	int	h;

	mlx_get_screen_size(game->mlx.mlx, &w, &h);
	if (cub->id_ptr.width > w)
		game->width = w;
	else
		game->width = cub->id_ptr.width;
	if (cub->id_ptr.height > h)
		game->height = h;
	else
		game->height = cub->id_ptr.height;
}

static int	ft_rgb_to_hex(int r, int g, int b)
{
	int sum;

	r = r * pow(16, 4);
	g = g * pow(16, 2);
	sum = r + g + b;
	return (sum);
}

void		ft_set_bmp_size(t_game *game, t_cub *cub)
{
	{
		if (cub->id_ptr.width > 16384)
			game->width = 16384;
		else
			game->width = cub->id_ptr.width;
		if (cub->id_ptr.height > 16384)
			game->height = 16384;
		else
			game->height = cub->id_ptr.height;
	}
}

void		ft_set_dir_var(t_game *game, t_cub *cub)
{
	if (cub->player_dir == 'W')
		game->dir_y = -1;
	else if (cub->player_dir == 'N')
		game->dir_x = -1;
	else if (cub->player_dir == 'E')
		game->dir_y = 1;
	else if (cub->player_dir == 'S')
		game->dir_x = 1;
	cub->map_str[game->i] = '0';
	if (cub->player_dir == 'S' || cub->player_dir == 'N')
		game->plane_y = 0.66;
	else if (cub->player_dir == 'W' || cub->player_dir == 'E')
		game->plane_x = 0.66;
	if (cub->player_dir == 'W' || cub->player_dir == 'S')
		game->set_camera = 1;
}

void		ft_game_init(t_game *game, t_cub *cub)
{
	game->save_flag = cub->save_bmp;
	if (game->save_flag == 0)
		ft_set_screen_size(game, cub);
	else
		ft_set_bmp_size(game, cub);
	game->pos_x = cub->startpos_y + 0.5;
	game->pos_y = cub->startpos_x + 0.5;
	game->floor = ft_rgb_to_hex(cub->floor.r, cub->floor.g, cub->floor.b);
	game->ceiling = ft_rgb_to_hex(cub->ceiling.r,
	cub->ceiling.g, cub->ceiling.b);
	game->player_dir = cub->player_dir;
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx,
	game->width, game->height, "Cub3D");
	game->mlx.img = mlx_new_image(game->mlx.mlx, game->width, game->height);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img,
	&game->mlx.bits_per_pixel, &game->mlx.line_length,
	&game->mlx.endian);
	ft_set_texture(game, cub);
}
