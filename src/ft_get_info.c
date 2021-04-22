/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:20:35 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:57:05 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	ft_set_res(char *line, t_cub *cub)
{
	cub->type_id.r = 1;
	line++;
	ft_skip_spaces(&line);
	if (!ft_isdigit(*line))
		ft_print_error("Invalid screen resolution\n");
	cub->id_ptr.width = ft_get_nmb(&line);
	if (cub->id_ptr.width == 0)
		ft_print_error("Invalid screen resolution\n");
	if (*line != ' ')
		ft_print_error("Invalid screen resolution\n");
	ft_skip_spaces(&line);
	if (!ft_isdigit(*line))
		ft_print_error("Invalid screen resolution\n");
	cub->id_ptr.height = ft_get_nmb(&line);
	if (cub->id_ptr.height == 0)
		ft_print_error("Invalid screen resolution\n");
	return (ft_check_remaining_chars(line, "R"));
}

static int	ft_set_digit_rgb(t_cub *cub, char **line, int *ptr)
{
	cub->rgb_ptr->count++;
	ft_skip_spaces(line);
	if (ft_isdigit(**line) == 0)
		return (-1);
	while (ft_isdigit(**line))
	{
		*ptr = (*ptr * 10) + (**line - '0');
		(*line)++;
	}
	if (*ptr < 0 || *ptr > 255)
		return (-1);
	ft_skip_spaces(line);
	if (cub->rgb_ptr->count == 3)
		return (1);
	if (**line == ',')
		(*line)++;
	else
		return (-1);
	return (1);
}

static int	ft_get_rgb_colour(t_cub *cub, char *line, char *type)
{
	line++;
	ft_skip_spaces(&line);
	if (ft_isdigit(*line))
	{
		if (ft_set_digit_rgb(cub, &line, &cub->rgb_ptr->r) == 1)
		{
			if (ft_set_digit_rgb(cub, &line, &cub->rgb_ptr->g) == 1)
			{
				if (ft_set_digit_rgb(cub, &line, &cub->rgb_ptr->b) == 1)
					return (ft_check_remaining_chars(line, type));
			}
		}
	}
	if (type[0] == 'F')
		ft_print_error("Invalid floor colour\n");
	else if (type[0] == 'C')
		ft_print_error("Invalid ceiling colour\n");
	return (1);
}

static int	ft_set_tex_path(t_cub *cub, char *line)
{
	int		i;

	i = 0;
	if (!ft_strncmp(line, "WE", 2))
		cub->ptr = &cub->we_tex_path;
	else if (!ft_strncmp(line, "NO", 2))
		cub->ptr = &cub->no_tex_path;
	else if (!ft_strncmp(line, "EA", 2))
		cub->ptr = &cub->ea_tex_path;
	else if (!ft_strncmp(line, "SO", 2))
		cub->ptr = &cub->so_tex_path;
	else if (!ft_strncmp(line, "S", 1))
		cub->ptr = &cub->sprite_tex_path;
	while (ft_isalpha(*line))
		line++;
	ft_skip_spaces(&line);
	while (line[i] != '\0' && ft_isprint(line[i]))
		i++;
	*cub->ptr = ft_substr(line, 0, i);
	if (*cub->ptr == NULL)
		ft_print_error("Memory allocation error\n");
	else if (ft_strncmp(*cub->ptr + (ft_strlen(*cub->ptr) - 4), ".xpm", 4))
		ft_print_error("Texture path must have '.xpm' extension\n");
	return (ft_check_remaining_chars(line + i, "P"));
}

int			ft_get_info(t_cub *cub, char *line)
{
	ft_check_doubles(cub, line);
	if (*line == 'R')
		return (ft_set_res(line, cub));
	else if (*line == 'F')
	{
		cub->type_id.f = 1;
		cub->rgb_ptr = &cub->floor;
		return (ft_get_rgb_colour(cub, line, "F"));
	}
	else if (*line == 'C' && cub->id_ptr.c == 0)
	{
		cub->type_id.c = 1;
		cub->rgb_ptr = &cub->ceiling;
		return (ft_get_rgb_colour(cub, line, "C"));
	}
	else if (ft_strncmp(line, "WE", 2) == 0 ||
	ft_strncmp(line, "NO", 2) == 0 ||
	ft_strncmp(line, "EA", 2) == 0 ||
	ft_strncmp(line, "SO", 2) == 0 ||
	ft_strncmp(line, "S", 1) == 0)
		return (ft_set_tex_path(cub, line));
	ft_print_error("Invalid type ids\n");
	return (0);
}
