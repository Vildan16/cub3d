/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:34:25 by ameta             #+#    #+#             */
/*   Updated: 2021/04/20 20:08:47 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_print_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

static int	ft_file_check(t_cub *cub)
{
	if (cub->id_count == 0 && cub->start_map == 0)
		return (ft_print_error("File is empty\n"));
	else if (cub->id_count != 8)
		return (ft_print_error("Missing types\n"));
	else if (cub->start_map == 0)
		return (ft_print_error("Missing map\n"));
	return (1);
}

static int	ft_check_input(int ac, char **av, t_cub *cub)
{
	if (ac != 2 || ac != 3)
		return (ft_print_error("Invalid amount of arguments\n"));
	else if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
		return (error("File must have a '.cub' extension\n"));
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7))
			return (ft_print_error("Use '--save' as a second argument\n"));
		else
			cub->save_bmp = 1;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_cub   cub;

	ft_bzero(&cub, sizeof(t_cub));
	ft_check_input(ac, av, &cub);
	cub.fd = open(av[1], O_RDWR);
	if (cub.fd == -1)
		return (ft_print_error("File didn't open\n"));
	else
		cub.fd_flag = 1;
	cub.ret = 1;
	while (cub.ret > 0)
	{
		cub.ret = get_next_line(cub.fd, &cub.line);
		if (cub.ret == -1)
			return (ft_print_error("File reading failed\n"));
		parse_scene(&cub, cub.line);
		free(cub.line);
	}
	close(cub.fd);
	ft_file_check(&cub);
	start_game(&cub);
	exit(0);
}