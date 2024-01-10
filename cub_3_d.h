/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvorstma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:54:12 by jvorstma          #+#    #+#             */
/*   Updated: 2023/12/04 14:11:32 by jvorstma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3_D_H
# define CUB_3_D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define NUM_ARGU "Please run this program with 1 argument\n"
# define FILE_NAME "Argument should have format *.cub\n"
# define OPEN_FAIL "Opening file failed\n"

int	main(int argc, char **argv);

# endif
