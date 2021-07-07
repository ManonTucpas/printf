/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:19:37 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sizeofint(long long n)
{
	int				count;
	unsigned int	u_nb;

	u_nb = n;
	count = 0;
	if (n <= 0)
	{
		count++;
		u_nb = -n;
	}
	while (u_nb != 0)
	{
		u_nb = u_nb / 10;
		count++;
	}
	return (count);
}

void	ft_int_space(t_arg *param, int len)
{
	if (param->width != -1)
	{
		if (param->intneg == 1)
			len++;
		if (param->nb_of_zero != 0)
			len = len + param->nb_of_zero;
		while (param->width > len)
		{
			param->width = param->width - 1;
			ft_putchar(param, ' ');
		}
	}
}

char	*ft_handle_zero_hex_unsigned(t_arg *param, int len, char *s)
{
	int nb_z;

	nb_z = param->nb_of_zero;
	if (param->putzero == 1 || param->prec > len)
	{
		if (param->prec > len)
		{
			nb_z = param->prec - len;
			s = ft_putzero_hex_unsigned(s, nb_z);
		}
		else if (param->prec < len && param->width != -1 && param->prec != -1)
			nb_z = 0;
		else if ((param->width > len && param->prec > len)
			|| (param->width > len && param->prec == -1))
		{
			nb_z = param->width - len;
			s = ft_putzero_hex_unsigned(s, nb_z);
		}
	}
	param->nb_of_zero = nb_z;
	return (s);
}

char	*ft_putzero_hex_unsigned(char *s, int nb_z)
{
	char	*szero;
	char	*t;
	int		i;

	t = NULL;
	i = 0;
	szero = (char *)malloc(sizeof(char) * (i + 1));
	if (!szero)
		return (0);
	while (i != nb_z)
	{
		szero[i] = '0';
		i++;
	}
	t = ft_strjoin(szero, s);
	free(szero);
	free(s);
	return (t);
}

int		ft_sizeofhex(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}
