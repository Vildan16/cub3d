/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:05:39 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 11:06:11 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		    ft_game_start(t_cub *cub)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	get_game_map(&game, cub);
	get_sprite_pos(&game);
	init_game(&game, cub);
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