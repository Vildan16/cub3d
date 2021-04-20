/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:44:39 by ameta             #+#    #+#             */
/*   Updated: 2020/11/20 16:44:41 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (dst[i] && dstsize > i)
		i++;
	if (dstsize < i + 1)
		return (dstsize + ft_strlen(src));
	while (src[n])
	{
		if (dstsize > i + n + 1)
			dst[i + n] = src[n];
		n++;
	}
	if (dstsize > i + n + 1)
		dst[i + n] = '\0';
	else
		dst[dstsize - 1] = '\0';
	return (i + n);
}
