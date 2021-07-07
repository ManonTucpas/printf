/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:25:10 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr(t_arg *param, char *str)
{
	int len_str;

	len_str = ft_strlen(str);
	write(1, str, len_str);
	param->count += len_str;
}

void		ft_putchar(t_arg *param, char c)
{
	write(1, &c, 1);
	param->count++;
}

void		ft_char_space(t_arg *param)
{
	if (param->width > 0)
		param->width--;
	while (param->width > 0)
	{
		if (param->zero == 1 && param->minus == -1)
			ft_putchar(param, '0');
		else
			ft_putchar(param, ' ');
		param->width--;
	}
}

void		ft_hex_space(t_arg *param, int len)
{
	if (param->width != -1)
	{
		if (param->nb_of_zero != 0)
			len = len + param->nb_of_zero;
		while (param->width > len)
		{
			param->width = param->width - 1;
			ft_putchar(param, ' ');
		}
	}
}

char		*ft_strndup(const char *s1, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (0);
	while (i < n && s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
