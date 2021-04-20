/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:45:13 by ameta             #+#    #+#             */
/*   Updated: 2020/11/20 16:45:16 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		tmp;

	str = (char *)s;
	i = 0;
	tmp = -1;
	while (str[i])
	{
		if (s[i] == c)
			tmp = i;
		i++;
	}
	if (c == 0)
		return (str + i);
	if (tmp != -1)
		return (str + tmp);
	return (NULL);
}
