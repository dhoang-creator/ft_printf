/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:42:52 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/08 17:14:43 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		conv_percent(t_data *data, int *printcount)
{
	char filler;

	filler = ((!data->left) & data->zero ? '0' : ' ');
	if (data->width > 1 && !data->left)
		ft_printer(filler, data->width - 1, printcount);
	ft_printer('%', 1, printcount);
	if (data->width > 1 && data->left)
		ft_printer(' ', data->width - 1, printcount);
	return (0);
}


int		conv_char(t_data *data, va_list list, int *printcount)
{
	int		c;
	char	filler;

	filler = ((!data->left) & data->zero ? '0' : ' ');
	c = va_arg(list, int);
	if (data->width > 1 && !data->left)
		ft_printer(filler, data->width - 1, printcount);
	ft_printer((char)c, 1, printcount);
	if (data->width > 1 && data->left)
		ft_printer(filler, data->width - 1, printcount);
	return (0);
}
