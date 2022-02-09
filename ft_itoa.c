/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:44:33 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/07 14:21:38 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

static	int		ft_count(int n)
{
	int j;

	j = 0;
	if (n <= 0)
		j = 1;
	while (n)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char			*ft_fill(char *str, long long num, size_t *numcount)
{
	str[*numcount] = '\0';
	while (*numcount > 0)
	{
		str[*numcount - 1] = (num % 10) + '0';
		num /= 10;
		(*numcount)--;
	}
	return (str);
}


char			*ft_itoa(long long n, t_data *data)
{
	char		*str;
	int			neg;
	size_t		numcount;
	long long	num;

	neg = 0;
	numcount = ft_count(n);
	if ((int)numcount < data->precision)
		numcount = data->precision;
	str = malloc(sizeof(char) * (numcount + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		if (n != LONG_MIN)
			n *= -1;
		neg = 1;
	}
	num = n;
	str = ft_fill(str, num, &numcount);
	if (neg)
		str[numcount] = '-';
	return (str);
}
