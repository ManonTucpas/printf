/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:17:11 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 15:17:15 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zerominus(t_arg *param, const char *fm, int id)
{
	while (fm[id] && (fm[id] == '-' || fm[id] == '0'))
	{
		if (fm[id] == '-')
		{
			param->minus = 1;
			id++;
		}
		else if (fm[id] == '0')
		{
			param->zero = 1;
			id++;
		}
	}
	return (id);
}

int		check_width(va_list va, t_arg *param, const char *fm, int id)
{
	if (fm[id] >= '0' && fm[id] <= '9')
	{
		param->width = ft_atoi(fm + id);
		while (fm[id] && (fm[id] >= '0' && fm[id] <= '9'))
			id++;
	}
	else if (fm[id] == '*')
	{
		if (fm[id - 1] == '0')
			param->putzero = 1;
		param->width = va_arg(va, int);
		if (param->width < 0)
		{
			param->putzero = 0;
			param->width *= -1;
			param->minus = 1;
		}
		id++;
	}
	return (id);
}

int		check_prec(va_list va, t_arg *param, const char *fm, int id)
{
	if (fm[id] == '.')
	{
		id++;
		if (fm[id] >= '0' && fm[id] <= '9')
		{
			param->prec = ft_atoi(fm + id);
			while (fm[id] && (fm[id] >= '0'
				&& fm[id] <= '9'))
				id++;
		}
		else if (fm[id] == '*')
		{
			param->prec = va_arg(va, int);
			id++;
		}
		else
			param->prec = 0;
	}
	if (param->prec < 0)
		param->prec = -1;
	return (id);
}
