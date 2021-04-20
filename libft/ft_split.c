/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:46:06 by ameta             #+#    #+#             */
/*   Updated: 2020/11/22 14:46:09 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **res, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	ft_wordn(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != c && s[i])
	{
		i++;
		n++;
	}
	return (n);
}

static int	ft_nwords(char const *s, char c)
{
	int		nn;
	int		i;

	i = 0;
	nn = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (nn == 0 && s[i] != c)
			nn++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nn++;
		i++;
	}
	return (nn);
}

static char	**ft_fill(char const *s, char c, int nn, char **res)
{
	int	i;
	int n;

	i = 0;
	while (i < nn)
	{
		while (*s == c)
			s++;
		n = ft_wordn(s, c);
		if (!(res[i] = (char *)malloc(sizeof(char *) * (n + 1))))
			return (ft_free(res, i));
		ft_strlcpy(res[i], s, n + 1);
		s = s + n + 1;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		nn;

	if (!s)
		return (NULL);
	nn = ft_nwords(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (nn + 1))))
		return (NULL);
	res = ft_fill(s, c, nn, res);
	return (res);
}
