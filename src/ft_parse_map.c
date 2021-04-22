/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:45:06 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:43:24 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_skip_spaces(char **line)
{
	while (**line == ' ')
		(*line)++;
}

int			ft_check_remaining_chars(char *line, char *type)
{
	while (*line)
	{
		if (*line == ' ')
			ft_skip_spaces(&line);
		else
		{
			if (!ft_strncmp(type, "R", 1))
				ft_print_error("Invalid character after R\n");
			else if (!ft_strncmp(type, "F", 1))
				ft_print_error("Invalid character after F\n");
			else if (!ft_strncmp(type, "S", 1))
				ft_print_error("Invalid character after S\n");
			else if (!ft_strncmp(type, "C", 1))
				ft_print_error("Invalid character after C\n");
		}
	}
	return (1);
}

void		ft_check_doubles(t_cub *cub, char *line)
{
	if ((*line == 'C' && cub->type_id.c == 1) ||
		(*line == 'R' && cub->type_id.r == 1) ||
		(*line == 'F' && cub->type_id.f == 1) ||
		((ft_strncmp(line, "EA", 2)) == 0 && cub->ea_tex_path != NULL) ||
		((ft_strncmp(line, "WE", 2)) == 0 && cub->we_tex_path != NULL) ||
		((ft_strncmp(line, "NO", 2)) == 0 && cub->no_tex_path != NULL) ||
		((ft_strncmp(line, "S ", 2)) == 0 && cub->sprite_tex_path != NULL) ||
		((ft_strncmp(line, "SO", 2)) == 0 && cub->so_tex_path != NULL))
		ft_print_error("Duplicate types\n");
	else if (cub->id_count != 8)
		cub->id_count++;
}

static int	ft_check_line(t_cub *cub, char *line)
{
	if (cub->start_map == 0)
		ft_check_doubles(cub, line);
	else if (*line == '\0' && cub->start_map == 1 && cub->ret > 0)
	{
		cub->end_map = 1;
		return (1);
	}
	else if (*line != '\0' && cub->end_map == 1)
		ft_print_error("Characters after map\n");
	return (1);
}

int			ft_parse_map(t_cub *cub, char *line)
{
	if (*line == '\0' && cub->start_map == 0)
		return (1);
	else if (cub->id_count == 8)
	{
		if (ft_check_line(cub, line) == 1)
			return (ft_get_map(cub, line));
	}
	else
	{
		ft_skip_spaces(&line);
		if ((ft_strchr("RFCS", *line) && *(line + 1) == ' ') ||
			ft_strncmp(line, "WE ", 3) == 0 ||
			ft_strncmp(line, "SO ", 3) == 0 ||
			ft_strncmp(line, "NO ", 3) == 0 ||
			ft_strncmp(line, "EA ", 3) == 0)
			return (ft_get_info(cub, line));
		else if (!(ft_strchr("012", *line)))
			ft_print_error("Invalid type ids\n");
		else
			ft_print_error("Missing type ids\n");
	}
	return (1);
}
