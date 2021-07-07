/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:05:59 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/18 11:10:13 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_s_args(t_arg *param)
{
	param->zero = -1;
	param->minus = -1;
	param->width = -1;
	param->prec = -1;
	param->putzero = -1;
	param->nb_of_zero = 0;
	param->intneg = 0;
}
