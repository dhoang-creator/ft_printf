/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:42:05 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/08 16:58:57 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** adjust len based on precision and width
*/

int		adjuster(t_data *data, size_t len)
{
	size_t newlen;

	newlen = len;
	if (data->width != (int)len)
		newlen = data->width;
	if (data->precision != -2 && data->width < data->precision)
	{
		if (data->type == 's' && data->precision < (int)len)
			newlen = data->precision;
		else if (data->type != 's' && data->precision > (int)len)
			newlen = data->precision;
	}
	return (newlen);
}

/*
** check if there are any specifiers or flags
*/

int		isvalid(const char **input, t_data *data)
{
	if (!(**input))
	{
		data->type = 0;
		return (0);
	}
	return (1);
}

/*
** init data
*/


void	data_init(t_data *data)
{
	data->left = 0;
	data->zero = 0;
	data->precision = -2;
	data->minus = 0;
	data->width = 0;
}

/*
**loop through input and parse to get data
*/


int		ft_printf(const char *input, ...)
{
	va_list list;
	t_data	data;
	int		printcount;

	printcount = 0;
	va_start(list, input);
	while (*input)
	{
		if (*input != '%')
			ft_writer(input, 1, &printcount);
		else
		{
			data_init(&data);
			input++;
			if (parser(&input, &data, list, &printcount) < 0)
				return (-1);
		}
		input++;
	}
	va_end(list);
	return (printcount);
}
