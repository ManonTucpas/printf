/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:08:42 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_itoa_unsigned(long n)
{
	char			*s;
	int				len_nb;

	len_nb = ft_sizeofint(n);
	s = (char *)malloc(sizeof(char) * (len_nb + 1));
	if (s == NULL)
		return (NULL);
	s[len_nb--] = '\0';
	while (len_nb >= 0)
	{
		s[len_nb] = n % 10 + '0';
		n = n / 10;
		len_nb--;
	}
	return (s);
}

static char		*ft_check_n(char *s, unsigned int n)
{
	if (n == 4294967295)
		s = ft_strdup("4294967295");
	else if ((int)n == -2147483648)
		s = ft_strdup("2147483648");
	else
		s = ft_itoa_unsigned(n);
	return (s);
}

void			ft_hanlde_unsigned(unsigned int n, t_arg *param)
{
	int		len;
	char	*s;

	s = NULL;
	s = ft_check_n(s, n);
	len = (int)ft_strlen(s);
	if (param->prec == 0 && n == 0)
	{
		s = ft_strdup("");
		len = 0;
	}
	if (param->putzero == 1 || param->prec != -1)
		s = ft_handle_zero_hex_unsigned(param, len, s);
	if (param->minus == 1)
		ft_putstr(param, s);
	ft_hex_space(param, len);
	if (param->minus == -1)
		ft_putstr(param, s);
	free(s);
}
