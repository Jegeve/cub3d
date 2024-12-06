/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_colour.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvorstma <jvorstma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 18:08:29 by jvorstma      #+#    #+#                 */
/*   Updated: 2024/05/29 14:38:42 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

static int	ft_parse_int(char *num)
{
	int	i;
	int	c;

	if (ft_strlen(num) > 3)
		return (-1);
	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (-1);
		i++;
	}
	c = ft_atoi(num);
	if (c < 0 || c > 255)
		return (-1);
	return (c);
}

t_error	ft_check_colour(char *str, uint8_t *colours, int *done)
{
	int		i;
	int		c;
	char	**s_str;

	s_str = ft_split(str, ',');
	if (ft_ptr_array_length((void **)s_str) != 3)
	{
		ft_free_ptr_array((void **)s_str);
		return (set_error(E_INCORRECT_COLOUR));
	}
	i = 0;
	while (s_str[i])
	{
		c = ft_parse_int(s_str[i]);
		if (c == -1)
		{
			ft_free_ptr_array((void **)s_str);
			return (set_error(E_INCORRECT_COLOUR));
		}
		colours[i] = c;
		i++;
	}
	ft_free_ptr_array((void **)s_str);
	*done = 1;
	return (OK);
}
