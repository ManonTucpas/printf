/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:14:00 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(int c, t_arg *param)
{
	if (param->minus == 1)
		ft_putchar(param, c);
	ft_char_space(param);
	if (param->minus == -1)
		ft_putchar(param, c);
}
