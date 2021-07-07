/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:37:16 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/18 11:18:26 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_all(va_list va, t_arg *param, const char *fm, int i)
{
	if (fm[i] == 'd' || fm[i] == 'i')
		ft_handle_int((va_arg(va, int)), param);
	else if (fm[i] == 'u')
		ft_hanlde_unsigned((va_arg(va, unsigned int)), param);
	else if (fm[i] == 'c')
		ft_handle_char(va_arg(va, int), param);
	else if (fm[i] == '%')
		ft_handle_pourcent('%', param);
	else if (fm[i] == 's')
		ft_handle_str(va_arg(va, char *), param);
	else if (fm[i] == 'x' || fm[i] == 'X')
		ft_x(va_arg(va, unsigned int), param, fm, i);
	else if (fm[i] == 'p')
		ft_handle_p(va_arg(va, long), param);
}

int			ft_check_segfault(int i, const char *fm)
{
	int j;

	j = i + 1;
	while (fm[j] && fm[j] != '%' && fm[j] != 'i' && fm[j] != 'd' &&
		fm[j] != 'u' && fm[j] != 'x' && fm[j] != 'X' && fm[j] != 'c' &&
			fm[j] != 's' && fm[j] != 'p')
		j++;
	if (!fm[j])
		return (-1);
	else
		return (0);
}

static int	ft_parse_percent(t_arg *param, const char *fm, int i)
{
	while (fm[i] && fm[i] != '%')
	{
		ft_putchar(param, fm[i]);
		i++;
	}
	return (i);
}

int			ft_parse(va_list va, t_arg *param, const char *fm, int i)
{
	while (fm[i])
	{
		i = ft_parse_percent(param, fm, i);
		if (fm[i] == '%')
		{
			if (ft_check_segfault(i, fm) == -1)
				return (-1);
			i++;
			ft_init_s_args(param);
			if ((fm[i] == '0' && (fm[i + 1] >= '1' && fm[i + 1] <= '9')))
			{
				i++;
				param->putzero = 1;
			}
			i = check_zerominus(param, fm, i);
			i = check_width(va, param, fm, i);
			i = check_prec(va, param, fm, i);
			if (param->width == 2147483647 || param->prec == 2147483647)
				return (-1);
			ft_handle_all(va, param, fm, i);
			i++;
		}
	}
	return (0);
}

int			ft_printf(const char *fm, ...)
{
	int		i;
	va_list va;
	t_arg	param;

	va_start(va, fm);
	param.count = 0;
	i = 0;
	if (ft_parse(va, &param, fm, i) < 0)
		return (-1);
	va_end(va);
	return (param.count);
}
