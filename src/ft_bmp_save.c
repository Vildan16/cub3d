/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:36:05 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 14:52:57 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_pixel_array_get(t_game *game, int imagesize)
{
	int		i;

	i = 0;
	game->bmp.y = game->height - 1;
	game->bmp.pix_array = ft_calloc(imagesize, sizeof(int));
	if (game->bmp.pix_array == NULL)
	{
		close(game->bmp.fd);
		ft_print_error("Memory allocation error\n");
	}
	while (game->bmp.y >= 0)
	{
		game->bmp.x = 0;
		while (game->bmp.x < game->width)
		{
			game->bmp.dest = game->mlx.addr + (game->bmp.y *
			game->mlx.line_length + game->bmp.x *
			(game->mlx.bits_per_pixel / 8));
			game->bmp.pix_array[i] = *(unsigned int*)game->bmp.dest;
			i++;
			game->bmp.x++;
		}
		game->bmp.y--;
	}
}

static void	ft_int_to_dest(int num, char *dest)
{
	dest[0] = (char)(num);
	dest[1] = (char)(num >> 8);
	dest[2] = (char)(num >> 16);
	dest[3] = (char)(num >> 24);
}

static void	ft_bmp_init_header(t_game *game)
{
	char	header_buf[54];
	int		ret;

	ft_bzero(&header_buf, 54);
	header_buf[0] = 'B';
	header_buf[1] = 'M';
	ft_int_to_dest(game->bmp.file_size, &(header_buf[2]));
	ft_int_to_dest(54, &(header_buf[10]));
	ft_int_to_dest(40, &(header_buf[14]));
	ft_int_to_dest(game->width, &(header_buf[18]));
	ft_int_to_dest(game->height, &(header_buf[22]));
	ft_int_to_dest(1, &(header_buf[26]));
	ft_int_to_dest(game->mlx.bits_per_pixel, &(header_buf[28]));
	ft_int_to_dest(game->bmp.file_size - 54, &(header_buf[34]));
	ret = write(game->bmp.fd, &header_buf, 54);
	if (ret == -1)
	{
		close(game->bmp.fd);
		ft_print_error("Couldn't write header to '.bmp' file\n");
	}
}

void		ft_bmp_save(t_game *game)
{
	int	ret;

	game->bmp.file_size = game->height * game->width *
	(game->mlx.bits_per_pixel / 8) + 54;
	game->bmp.fd = open("image.bmp", O_RDWR | O_CREAT, 0644);
	if (game->bmp.fd == -1)
		ft_print_error("Couldn't create 'image.bmp' file\n");
	ft_bmp_init_header(game);
	ft_pixel_array_get(game, game->bmp.file_size - 54);
	ret = write(game->bmp.fd, game->bmp.pix_array, game->bmp.file_size - 54);
	if (ret == -1)
	{
		free(game->bmp.pix_array);
		close(game->bmp.fd);
		ft_print_error("Couldn't write pixel array to 'image.bmp' file\n");
	}
	free(game->bmp.pix_array);
	close(game->bmp.fd);
}
