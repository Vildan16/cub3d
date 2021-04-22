/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:55:37 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 12:07:15 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static char	*ft_get_path(t_cub *cub, char *tex_path, int i)
{
	if (i == 0)
		tex_path = cub->no_tex_path;
	else if (i == 1)
		tex_path = cub->so_tex_path;
	else if (i == 2)
		tex_path = cub->we_tex_path;
	else if (i == 3)
		tex_path = cub->ea_tex_path;
	else if (i == 4)
		tex_path = cub->sprite_tex_path;
	return (tex_path);
}

void		ft_set_texture(t_game *game, t_cub *cub)
{
	int		i;
	char	*tex_path;

	i = 0;
	while (i < 5)
	{
		tex_path = ft_get_path(cub, tex_path, i);
		game->tex[i].img = mlx_xpm_file_to_image(game->mlx.mlx, tex_path,
		&game->tex[i].width, &game->tex[i].height);
		if (game->tex[i].img == NULL)
			ft_print_error("Image from '.xpm' file couldn't been created\n");
		game->tex[i].addr = mlx_get_data_addr(game->tex[i].img,
		&game->tex[i].bits_per_pixel, &game->tex[i].line_length,
		&game->tex[i].endian);
		i++;
	}
}