/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_digit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:43:17 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/08 17:15:33 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int			num_printer(t_data *data, char *str, int num, size_t orig_len)
{
	int		printcount;
	size_t	len;
	size_t	newlen;

	printcount = 0;
	if (data->precision == -2 || data->precision < (int)orig_len)
		data->precision = (int)orig_len;
	len = adjuster(data, orig_len);
	if ((int)len < data->precision + data->minus)
		newlen = len;
	else
		newlen = data->precision + data->minus;
	if (!data->left && !data->zero)
		ft_printer(' ', len - newlen, &printcount);
	if (data->minus)
		ft_printer('-', 1, &printcount);
	if (!data->left && data->zero)
		ft_printer('0', len - newlen, &printcount);
	if ((data->left && data->precision > (int)orig_len) || !data->left)
		ft_printer('0', data->precision - orig_len, &printcount);
	ft_writer((num < 0 ? str + 1 : str), orig_len, &printcount);
	if (data->left)
		ft_printer(' ', len - newlen, &printcount);
	return (printcount);
}


int			conv_int(t_data *data, va_list list, int *printcount)
{
	int		num;
	size_t	len;
	char	*str;

	num = va_arg(list, int);
	if (!data->precision && !num && !data->width)
		return (0);
	str = ft_itoa(num, data);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (num < 0)
	{
		len--;
		data->minus = 1;
	}
	if (data->precision != -2)
		data->zero = 0;
	if (num == 0 && data->precision == 0)
		len = 0;
	*printcount += num_printer(data, str, num, len);
	free(str);
	return (0);
}
