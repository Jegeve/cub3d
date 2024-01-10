/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvorstma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:51:43 by jvorstma          #+#    #+#             */
/*   Updated: 2023/12/04 14:10:26 by jvorstma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3_d.h"

static int	ft_parse_error(char *error_msg)
{
	write(2, "Error\n", 6);
	write(2, error_msg, ft_strlen(error_msg));
	return (1);
}

static int	ft_check_file_name(char *file)
{
	int	i;

	if (!file)
		return (0);
	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i])
		return (0);
	if (!ft_strcmp(&file[i], ".cub"))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_parse_error(NUM_ARGU));
	if (!ft_check_file_name(argv[1]))
		return (ft_parse_error(FILE_NAME));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_parse_error(OPEN_FAIL));
	else
		close (fd);
	return (1);
}
