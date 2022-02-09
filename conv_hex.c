/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_hex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:43:32 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/08 17:34:13 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		hex_printer(t_data *data, char *str, size_t len)
{
	int		printcount;
	size_t	newlen;
	size_t	signedlen;

	printcount = 0;
	if (data->precision == -2 || data->precision < (int)len)
		data->precision = (int)len;
	newlen = adjuster(data, len);
	signedlen = ((int)newlen < data->precision) ? newlen : data->precision;
	if (!data->left && !data->zero)
		ft_printer(' ', newlen - signedlen, &printcount);
	if (data->type == 'p')
		ft_writer("0x", 2, &printcount);
	if (!data->left && data->zero)
		ft_printer('0', newlen - signedlen, &printcount);
	if (((data->left && data->precision > (int)len)) || !data->left)
		ft_printer('0', data->precision - len, &printcount);
	if (data->type == 'p')
		ft_writer(str, len - 2, &printcount);
	else
		ft_writer(str, len, &printcount);
	if (data->left)
		ft_printer(' ', newlen - signedlen, &printcount);
	return (printcount);
}


int		conv_hex(t_data *data, va_list list, int *printcount)
{
	unsigned long long		num;
	char					*str;
	int						len;
	unsigned int			base;

	if (data->type == 'p')
		num = va_arg(list, unsigned long long);
	else
		num = va_arg(list, unsigned int);
	if (!data->precision && !num && !data->width && data->type != 'p')
		return (0);
	base = (data->type == 'u' ? 10 : 16);
	str = itoa_base(num, data, base);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (data->precision != -2)
		data->zero = 0;
	if (num == 0 && data->precision == 0)
		len = 0;
	len = (data->type == 'p') ? len + 2 : len;
	*printcount += hex_printer(data, str, len);
	free(str);
	return (0);
}
