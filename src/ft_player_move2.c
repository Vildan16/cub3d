/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:31:59 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 14:32:55 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_rotate_right(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-ROT_SPD) -
	game->dir_y * sin(-ROT_SPD);
	game->dir_y = game->old_dir_x * sin(-ROT_SPD) +
	game->dir_y * cos(-ROT_SPD);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(-ROT_SPD) -
	game->plane_y * sin(-ROT_SPD);
	game->plane_y = game->old_plane_x * sin(-ROT_SPD) +
	game->plane_y * cos(-ROT_SPD);
}

void	ft_rotate_left(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(ROT_SPD) -
	game->dir_y * sin(ROT_SPD);
	game->dir_y = game->old_dir_x * sin(ROT_SPD) +
	game->dir_y * cos(ROT_SPD);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(ROT_SPD) -
	game->plane_y * sin(ROT_SPD);
	game->plane_y = game->old_plane_x * sin(ROT_SPD) +
	game->plane_y * cos(ROT_SPD);
}
