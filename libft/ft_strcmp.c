/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvorstma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:37:00 by jvorstma          #+#    #+#             */
/*   Updated: 2023/12/04 13:40:36 by jvorstma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	len = (int)ft_strlen(s1);
	if (len != (int)ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i < len && s1[i] != s2[i])
		return (0);
	return (1);
}
