/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:37:26 by ameta             #+#    #+#             */
/*   Updated: 2021/04/21 21:08:46 by ameta            ###   ########.fr       */
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
	char			player_dir;
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

void			ft_print_error(char *message);
int				ft_parse_map(t_cub *cub, char *line);
void			ft_check_doubles(t_cub *cub, char *line);
int				ft_get_map(t_cub *cub, char *line);
int	ft_check_chars(t_cub *cub, char *line);
void	ft_fill_line(t_cub *cub);
void	get_line(t_cub *cub);
int		ft_find_startpos(t_cub *cub);
int		ft_flood_fill(t_cub *cub, int x, int y);
int ft_check_map(t_cub *cub);

#endif