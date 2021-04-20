/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:37:26 by ameta             #+#    #+#             */
/*   Updated: 2021/04/20 13:43:38 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct		s_cub
{
	int				fd;
	int				fd_flag;
	ssize_t			ret;
	char			*line;
	int				save_bmp;
	int				start_map;
	int				end_map;
	int				id_count;
	t_id_flag		type_id;
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
	int				map_i;
	int				y;
	int				x;
	int				longest_str;
	int				line_count;
	t_id			id_ptr;
	t_rgb			floor;
	t_rgb			ceiling;
	t_rgb			*rgb_ptr;
	int				startpos_x;
	int				startpos_y;
	char			wall;
	char			target;
	char			replacement;
}					t_cub;





#endif