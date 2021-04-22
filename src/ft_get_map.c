/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:32:15 by ameta             #+#    #+#             */
/*   Updated: 2021/04/22 15:54:23 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_check_chars(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("012NSEW ", line[i]))
			ft_print_error("Invalid chars in map\n");
		if (ft_strchr("NSEW", line[i]))
		{
			if (cub->player_dir != 0)
				ft_print_error("Multiple player posisions in map\n");
			cub->player_dir = line[i];
		}
		i++;
	}
	return (1);
}

static int	ft_get_longest_string(t_cub *cub)
{
	int	j;
	int	i;
	int	max;

	j = 0;
	i = 0;
	max = 0;
	while (cub->map_str[i])
	{
		while (cub->map_str[i] != ',')
		{
			j++;
			i++;
		}
		if (j > max)
			max = j;
		j = 0;
		i++;
	}
	return (max);
}

static void	ft_join_line(t_cub *cub, char *line)
{
	cub->start_map = 1;
	if (cub->map_str == NULL)
		cub->map_str = ft_strdup("");
	if (cub->map_str == NULL)
		ft_print_error("Memory allocation error\n");
	cub->tmp_line = ft_calloc(ft_strlen(line) + 2, sizeof(char));
	if (cub->tmp_line == NULL)
		ft_print_error("Memory allocation error\n");
	ft_strlcpy(cub->tmp_line, line, ft_strlen(line) + 1);
	cub->tmp_line[ft_strlen(line)] = ',';
	cub->tmp_line[ft_strlen(line) + 1] = '\0';
	cub->tmp_map = ft_strdup(cub->map_str);
	if (cub->tmp_map == NULL)
		ft_print_error("Memory allocation error\n");
	free(cub->map_str);
	cub->map_str = ft_strjoin(cub->tmp_map, cub->tmp_line);
	if (cub->map_str == NULL)
		ft_print_error("Memory allocation error\n");
	free(cub->tmp_line);
	cub->tmp_line = NULL;
	free(cub->tmp_map);
	cub->tmp_map = NULL;
}

static int	ft_map_array(t_cub *cub)
{
	cub->map = ft_calloc(cub->line_count + 3, sizeof(char*));
	if (cub->map == NULL)
		ft_print_error("Memory allocation error\n");
	cub->longest_str = ft_get_longest_string(cub);
	while (cub->y < cub->line_count + 2)
	{
		cub->x = 0;
		cub->map[cub->y] = ft_calloc(cub->longest_str + 3, sizeof(char));
		if (cub->map == NULL)
			ft_print_error("Malloc error: cub->map\n");
		if (cub->y == 0)
			ft_fill_line(cub);
		if (cub->y > 0 && cub->y != cub->line_count + 1)
			ft_get_line(cub);
		if (cub->y == cub->line_count + 1)
			ft_fill_line(cub);
		cub->map[cub->y][cub->x] = '\0';
		cub->y++;
	}
	ft_find_startpos(cub);
	ft_flood_fill(cub, cub->x, cub->y);
	return (ft_check_map(cub));
}

int			ft_get_map(t_cub *cub, char *line)
{
	int		i;

	i = 0;
	if (ft_check_chars(cub, line) == -1)
		return (-1);
	else if (cub->start_map == 1 && *line == '\0' && cub->ret == 0)
	{
		if (cub->player_dir == 0)
			ft_print_error("Player position not found\n");
		return (ft_map_array(cub));
	}
	if (ft_strchr("NSEW012 ", line[i]))
	{
		ft_join_line(cub, line);
		cub->line_count++;
		if (cub->ret == 0)
		{
			if (cub->player_dir == 0)
				ft_print_error("Player position not found\n");
			return (ft_map_array(cub));
		}
	}
	else
		ft_print_error("Invalid characters in map\n");
	return (1);
}
