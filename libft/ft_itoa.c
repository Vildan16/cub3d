/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:41:50 by ameta             #+#    #+#             */
/*   Updated: 2020/11/20 16:41:52 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_minint(int n, char *str)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	return (n);
}

static int	ft_nn(int n)
{
	int		nn;

	nn = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		nn++;
		n = -1 * n;
	}
	while (n != 0)
	{
		n = n / 10;
		nn++;
	}
	return (nn);
}

char		*ft_itoa(int n)
{
	int		nn;
	char	*str;

	nn = ft_nn(n);
	str = (char *)malloc(sizeof(char) * (nn + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[nn - 1] = '0';
	str[nn] = '\0';
	n = ft_check_minint(n, str);
	if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	while (n != 0)
	{
		str[nn - 1] = n % 10 + '0';
		n = n / 10;
		nn--;
	}
	return (str);
}
