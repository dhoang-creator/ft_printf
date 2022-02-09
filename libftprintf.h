/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <dhoang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/01 07:45:17 by dhoang        #+#    #+#                 */
/*   Updated: 2020/05/07 13:45:19 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_data
{
	char		type;
	int			left;
	int			zero;
	int			precision;
	int			minus;
	int			width;
}				t_data;

int				ft_printf(const char *input, ...);

void			data_init(t_data *data);
int				adjuster(t_data *data, size_t len);
int				convert(va_list list, t_data *data, int *printcount);
void			flagparse(const char **input, t_data *data);
int				isvalid(const char **input, t_data *data);
int				typefinder(const char **input);
int				parser(const char **input, t_data *data,
				va_list list, int *printcount);

int				conv_char(t_data *data, va_list list, int *printcount);
int				conv_string(t_data *data, va_list list, int *printcount);
int				conv_int(t_data *data, va_list list, int *printcount);
int				conv_hex(t_data *data, va_list list, int *printcount);
int				conv_percent(t_data *data, int *printcount);

void			ft_writer(const char *ptr, size_t len, int *printcount);
void			ft_printer(const char c, size_t len, int *printcount);
void			widthsetter(t_data *data, va_list list);
void			precisionsetter(const char **input, t_data *data);

int				ft_isdigit(int c);
int				ft_strlen(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(long long n, t_data *data);
char			*itoa_base(long long n, t_data *data, unsigned int base);

#endif
