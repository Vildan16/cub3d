/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:42:46 by ameta             #+#    #+#             */
/*   Updated: 2020/11/20 16:42:47 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*tmp;

	if (!dest && !src)
		return (NULL);
	i = 0;
	tmp = (unsigned char *)src;
	ptr = (unsigned char *)dest;
	while (i < n)
	{
		ptr[i] = tmp[i];
		i++;
	}
	return (dest);
}
