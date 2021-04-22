/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:12:06 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:58:33 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_move_backward(t_game *game)
{
	if (game->map[(int)(game->pos_x - game->dir_x * MOVE_SPD)]
	[(int)(game->pos_y)] == '0')
		game->pos_x -= game->dir_x * MOVE_SPD;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y -
	game->dir_y * MOVE_SPD)] == '0')
		game->pos_y -= game->dir_y * MOVE_SPD;
	if (floor(game->pos_x - (int)game->pos_x) < 0.00000001 ||
		fabs(game->pos_y - (int)game->pos_y) < 0.00000001)
	{
		if (game->dir_x < 0)
			game->pos_x -= .0001;
		else if (game->dir_x > 0)
			game->pos_x += .0001;
		else if (game->dir_y < 0)
			game->pos_y -= .0001;
		else if (game->dir_y > 0)
			game->pos_y += .0001;
	}
}

static void	ft_move_left(t_game *game)
{
	if (game->map[(int)(game->pos_x - game->dir_y * MOVE_SPD)]
	[(int)game->pos_y] == '0')
		game->pos_x = game->pos_x - game->dir_y * MOVE_SPD;
	if (game->map[(int)game->pos_x][(int)(game->pos_y -
	(-game->dir_x) * MOVE_SPD)] == '0')
		game->pos_y = game->pos_y - (-game->dir_x) * MOVE_SPD;
	if (floor(game->pos_y - (int)game->pos_y) < 0.00000001 ||
		fabs(game->pos_y - (int)game->pos_y) < 0.00000001)
	{
		if (game->dir_x < 0)
			game->pos_y += .0001;
		else if (game->dir_x > 0)
			game->pos_y -= .0001;
		else if (game->dir_y > 0)
			game->pos_x += .0001;
		else if (game->dir_y < 0)
			game->pos_x -= .0001;
	}
}

static void	ft_move_right(t_game *game)
{
	if (game->map[(int)(game->pos_x + game->dir_y * MOVE_SPD)]
	[(int)game->pos_y] == '0')
		game->pos_x = game->pos_x + game->dir_y * MOVE_SPD;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y +
	(-game->dir_x) * MOVE_SPD)] == '0')
		game->pos_y = game->pos_y + (-game->dir_x) * MOVE_SPD;
	if (floor(game->pos_y - (int)game->pos_y) < 0.00000001 ||
		fabs(game->pos_y - (int)game->pos_y) < 0.00000001)
	{
		if (game->dir_x < 0)
			game->pos_y -= .0001;
		else if (game->dir_x > 0)
			game->pos_y += .0001;
		else if (game->dir_y > 0)
			game->pos_x -= .0001;
		else if (game->dir_y < 0)
			game->pos_x += .0001;
	}
}

static void	ft_move_forward(t_game *game)
{
	if (game->map[(int)(game->pos_x + game->dir_x * MOVE_SPD)]
	[(int)(game->pos_y)] == '0')
		game->pos_x += game->dir_x * MOVE_SPD;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y +
	game->dir_y * MOVE_SPD)] == '0')
		game->pos_y += game->dir_y * MOVE_SPD;
	if (floor(game->pos_x - (int)game->pos_x) < 0.00000001 ||
		fabs(game->pos_y - (int)game->pos_y) < 0.00000001)
	{
		if (game->dir_x < 0)
			game->pos_x += .0001;
		else if (game->dir_x > 0)
			game->pos_x -= .0001;
		else if (game->dir_y < 0)
			game->pos_y += .0001;
		else if (game->dir_y > 0)
			game->pos_y -= .0001;
	}
}

void		ft_player_move(t_game *game)
{
	if (game->key.w)
		ft_move_forward(game);
	if (game->key.a)
		ft_move_left(game);
	if (game->key.s)
		ft_move_backward(game);
	if (game->key.d)
		ft_move_right(game);
	if (game->key.arrow_left)
		ft_rotate_left(game);
	if (game->key.arrow_right)
		ft_rotate_right(game);
}
