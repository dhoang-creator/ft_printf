/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:44:17 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/08 17:29:53 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_count(long long n, t_data *data, unsigned int base)
{
	size_t	numcount;

	numcount = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		numcount++;
	}
	if ((int)numcount < data->precision)
		numcount = data->precision;
	return (numcount);
}

void			setfinder(t_data *data, char **set)
{
	if (data->type == 'u')
		*set = "0123456789";
	else if (data->type == 'X')
		*set = "0123456789ABCDEF";
	else
		*set = "0123456789abcdef";
}


char			*itoa_base(long long n, t_data *data, unsigned int base)
{
	char	*str;
	char	*set;
	size_t	numcount;

	numcount = ft_count(n, data, base);
	str = malloc(sizeof(char) * (numcount + 1));
	if (!str)
		return (NULL);
	setfinder(data, &set);
	str[numcount] = '\0';
	while (numcount)
	{
		str[numcount - 1] = set[n % base];
		n /= base;
		numcount--;
	}
	return (str);
}
