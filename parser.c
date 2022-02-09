/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:47:03 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/08 17:35:12 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		convert(va_list list, t_data *data, int *printcount)
{
	if (data->width == -1)
		widthsetter(data, list);
	if (data->precision == -1)
		data->precision = va_arg(list, int);
	if (data->type == '%')
		return (conv_percent(data, printcount));
	if (data->type == 'c')
		return (conv_char(data, list, printcount));
	if (data->type == 's')
		return (conv_string(data, list, printcount));
	if (data->type == 'd' || data->type == 'i')
		return (conv_int(data, list, printcount));
	if (data->type == 'p' || data->type == 'x' ||
		data->type == 'X' || data->type == 'u')
		return (conv_hex(data, list, printcount));
	return (1);
}


void	flagparse(const char **input, t_data *data)
{
	if (**input == '-')
		data->left = 1;
	else if (**input == '0')
		data->zero = 1;
	else if (**input == '*')
		data->width = -1;
	else if (ft_isdigit(**input))
		data->width = ft_atoi(*input);
	else if (**input == '.')
		precisionsetter(input, data);
}

int		typefinder(const char **input)
{
	char *type;

	type = "cspdiuxX%n";
	if (**input)
	{
		while (*type)
		{
			if (*type == **input)
				return (1);
			type++;
		}
	}
	return (0);
}

//the while loop within the flagparser is like wtf?!?
//after a flag is identified in the **input, it iterates along the input but how does it enter the convert function aside from there being a converter to be there?

int		parser(const char **input, t_data *data, va_list list, int *printcount)
{
	while (**input && isvalid(input, data))
	{
		if (typefinder(input))
		{
			data->type = **input;
			return (convert(list, data, printcount));
		}
		flagparse(input, data);
		if (data->width != 0 || data->precision != -2)
		{
			while (**input && ft_isdigit(*(*input + 1)))
				(*input)++;
		}
		(*input)++;
	}
	return (-1);
}
