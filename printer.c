/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:47:24 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/07 13:45:57 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void	ft_writer(const char *ptr, size_t len, int *printcount)
{
	write(1, ptr, len);
	*printcount += len;
}

void	ft_printer(const char c, size_t len, int *printcount)
{
	size_t i;

	i = 0;
	while (len && i < len)
	{
		ft_writer(&c, 1, printcount);
		i++;
	}
}
