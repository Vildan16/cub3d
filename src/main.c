/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:34:25 by ameta             #+#    #+#             */
/*   Updated: 2021/04/20 19:30:11 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

static int	input_check(int ac, char **av, t_cub *cub)
{
	if (ac != 2 || ac != 3)
		return (error("Error: invalid amount of arguments\n"));
	else if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4))
		return (error("Error: scene file should have a .cub extension\n"));
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			return (error("Error: try --save as second argument\n"));
		else
			scene->save_bmp = 1;
	}
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	t_cub   cub;

	ft_bzero(&cub, sizeof(t_cub));
	input_check(ac, av, &cub);
	scene.fd = open(argv[1], O_RDWR);
	if (scene.fd == ERROR)
		return (error("Error: .cub file could not be openend\n"));
	else
		scene.fd_flag = 1;
	scene.ret = 1;
	while (scene.ret > 0)
	{
		scene.ret = get_next_line(scene.fd, &scene.line);
		if (scene.ret == ERROR)
			return (error("Error: .cub file could not been read\n"));
		parse_scene(&scene, scene.line);
		free(scene.line);
	}
	close(scene.fd);
	scene_check(&scene);
	start_game(&scene);
	exit(0);
}