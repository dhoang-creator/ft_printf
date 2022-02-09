/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setter.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:48:02 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/07 13:46:16 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	widthsetter(t_data *data, va_list list)
{
	data->width = va_arg(list, int);
	if (data->width < 0)
	{
		data->width *= -1;
		data->left = 1;
	}
}

void	precisionsetter(const char **input, t_data *data)
{
	if (*(*input + 1) == '*')
	{
		data->precision = -1;
		(*input)++;
	}
	else if (ft_isdigit(*(*input + 1)))
		data->precision = ft_atoi(*input + 1);
	else
		data->precision = 0;
}
