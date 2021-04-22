/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:37:26 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 11:12:50 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				count;
}					t_rgb;

typedef struct		s_id_flag
{
	int				r;
	int				f;
	int				c;
}					t_id_flag;

typedef struct		s_id
{
	int				width;
	int				height;
	int				r;
	int				f;
	int				c;
}					t_id;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				endian;
	int				bits_per_pixel;
	int				line_length;
}					t_mlx;

typedef struct		s_bmp
{
	int				fd;
	int				x;
	int				y;
	int				file_size;
	int				*pix_array;
	char			*dest;
}					t_bmp;

typedef struct		s_texture
{
	int				tex_x;
	int				tex_y;
	double			step;
	int				width;
	int				height;
	double			tex_pos;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*get_color;
	void			*img;
	char			*addr;
}					t_texture;

typedef struct		s_key
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				arrow_left;
	int				arrow_right;
}					t_key;

typedef struct		s_sprite_pos
{
	double			x;
	double			y;
	double			dist;
}					t_sprite_pos;

typedef struct		s_sprite
{
	double			ahead_behind;
	double			right_left;
	int				center_x;
	double			inv;
	int				screen_pos;
	int				height;
	int				width;
	double			x;
	double			y;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
}					t_sprite;

typedef struct		s_game
{
	t_mlx			mlx;
	t_bmp			bmp;
	t_texture		tex[5];
	t_key			key;
	t_sprite_pos	*sprite_pos;
	t_sprite		sprite;
	int				i;
	char			**map;
	int				width;
	int				height;
	int				floor;
	int				ceiling;
	int				save_flag;
	char			player_dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	double			old_dir_x;
	double			old_plane_x;
	double			wall_x;
	int				d;
	int				num_sprite;
	int				set_camera;
	double			*z_buffer;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				x;
	int				y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	
}					t_game;

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
	char			*we_tex_path;
	char			*no_tex_path;
	char			*ea_tex_path;
	char			*so_tex_path;
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
void	ft_skip_spaces(char **line);
int			ft_get_info(t_cub *cub, char *line);
int			ft_check_remaining_chars(char *line, char *type);

#endif