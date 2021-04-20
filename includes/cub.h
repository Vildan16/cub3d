/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:37:26 by ameta             #+#    #+#             */
/*   Updated: 2021/04/20 20:09:58 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct		s_cub
{
	t_rgb			ceiling;
	t_rgb			*rgb_ptr;
	t_id_flag		type_id;
	t_id			id_ptr;
	t_rgb			floor;
	int				map_i;
	int				y;
	int				x;
	int				longest_str;
	int				line_count;
	char			**ptr;
	char			*no_tex_path;
	char			*so_tex_path;
	char			*we_tex_path;
	char			*ea_tex_path;
	char			*sprite_tex_path;
	char			cardinal_dir;
	char			*map_str;
	char			*tmp_line;
	char			*tmp_map;
	char			**map;
	int				fd;
	int				fd_flag;
	int				ret;
	char			*line;
	char			wall;
	char			target;
	char			replacement;
	int				save_bmp;
	int				start_map;
	int				end_map;
	int				id_count;
	int				startpos_x;
	int				startpos_y;
}					t_cub;

#endif