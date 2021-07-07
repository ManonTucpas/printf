/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:54:21 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_handle_str(char *str, t_arg *param)
{
	if (!str)
		str = "(null)";
	if (param->prec == 0)
		str = "";
	if (param->prec > 0)
		str = ft_strndup(str, param->prec);
	if (param->minus == 1)
		ft_putstr(param, str);
	if (param->width != -1)
	{
		while (param->width > (int)ft_strlen(str))
		{
			param->width = param->width - 1;
			ft_putchar(param, ' ');
		}
	}
	if (param->minus == -1)
		ft_putstr(param, str);
	if (param->prec >= 1)
		free(str);
}
