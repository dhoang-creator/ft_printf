/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_string.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:43:50 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/07 13:44:50 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		conv_string(t_data *data, va_list list, int *printcount)
{
	size_t	len;
	size_t	newlen;
	char	*str;

	if (data->precision == 0 && !data->width)
		return (0);
	if (data->precision < 0)
		data->precision = -2;
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	newlen = adjuster(data, len);
	if (data->precision != -2 && data->precision < (int)len)
		len = data->precision;
	if (!data->left && newlen > len)
		ft_printer(' ', newlen - len, printcount);
	ft_writer(str, len, printcount);
	if (data->left && newlen > len)
		ft_printer(' ', newlen - len, printcount);
	return (0);
}
