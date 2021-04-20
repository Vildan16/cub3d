/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:45:21 by ameta             #+#    #+#             */
/*   Updated: 2020/11/20 16:45:24 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = (int)ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && end && end + 1)
		end--;
	if (end == 0)
		end = start;
	if (!(str = (char *)malloc(sizeof(*str) * (end - start + 2))))
		return (NULL);
	while (start <= end)
	{
		str[i++] = s1[start];
		start++;
	}
	str[i] = '\0';
	return (str);
}
