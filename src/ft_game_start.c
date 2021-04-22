/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:05:39 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 11:38:31 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_get_game_map(t_game *game, t_cub *cub)
{
	game->map = ft_calloc(cub->line_count + 1, sizeof(char *));
	if (game->map == NULL)
		ft_print_error("Memory allocation error\n");
	while (game->y < cub->line_count)
	{
		game->x = 0;
		game->map[game->y] = ft_calloc(cub->longest_str + 1, sizeof(char));
		if (game->map[game->y] == NULL)
			ft_print_error("Memory allocation error\n");
		if (cub->map_str[game->i] == ',')
			game->i++;
		while (cub->map_str[game->i] != ',')
		{
			if (cub->map_str[game->i] == cub->player_dir)
				ft_set_dir_var(game, cub);
			else if (cub->map_str[game->i] == '2')
				game->num_sprite++;
			game->map[game->y][game->x] = cub->map_str[game->i];
			game->x++;
			game->i++;
		}
		game->map[game->y][game->x] = '\0';
		game->y++;
	}
}

int			ft_game_start(t_cub *cub)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	ft_get_game_map(&game, cub);
	ft_get_sprite_pos(&game);
	ft_game_init(&game, cub);
	mlx_hook(game.mlx.win, 2, 1L << 0, press, &game);
	mlx_hook(game.mlx.win, 3, 1L << 1, release, &game);
	mlx_hook(game.mlx.win, 17, 1L << 0, exit_game, &game);
	mlx_hook(game.mlx.win, 17, 1L << 2, exit_game, &game);
	if (cub->save_bmp == 1)
	{
		render_next_frame(&game);
		save_bmp(&game);
		exit(0);
	}
	mlx_loop_hook(game.mlx.mlx, render_next_frame, &game);
	mlx_loop(game.mlx.mlx);
	exit(0);
}