/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:24:00 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_pourcent(int c, t_arg *param)
{
	if (param->putzero == 1)
	{
		while ((param->width - 1) > 0)
		{
			ft_putchar(param, '0');
			param->width--;
		}
	}
	if (param->minus == 1)
		ft_putchar(param, c);
	ft_char_space(param);
	if (param->minus == -1)
		ft_putchar(param, c);
}
