/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:44:47 by ameta             #+#    #+#             */
/*   Updated: 2020/11/24 15:37:47 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (!src || !dst)
		return (0);
	while (src[i])
	{
		if (dstsize > i + 1)
			dst[i] = src[i];
		i++;
	}
	if (dstsize > i + 1)
		dst[i] = '\0';
	else
		dst[dstsize - 1] = '\0';
	return (i);
}
