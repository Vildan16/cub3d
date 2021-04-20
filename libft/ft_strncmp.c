/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:45:08 by ameta             #+#    #+#             */
/*   Updated: 2020/11/20 16:45:09 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;
	char			*end;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	end = (char *)str1 + n;
	res = 0;
	while (res == 0 && (char *)str1 != end && (*str1 || *str2))
	{
		res = *str1 - *str2;
		str1++;
		str2++;
	}
	return (res);
}
