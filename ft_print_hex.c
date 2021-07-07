/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:22:57 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 15:51:41 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_put_hex_in_str(unsigned int n, char *base)
{
	char	*s;
	int		count;

	count = ft_sizeofhex(n);
	s = (char *)malloc(sizeof(char) * (count + 1));
	if (s == NULL)
		return (NULL);
	s[count] = '\0';
	if (count == '1')
		s[count - 1] = base[n];
	while (count != 0)
	{
		s[count - 1] = base[n % 16];
		n = n / 16;
		count--;
	}
	return (s);
}

static char	*ft_define_base(const char *fm, int i)
{
	char *base;

	if (fm[i] == 'x')
		base = "0123456789abcdef";
	if (fm[i] == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

void		ft_x(unsigned int n, t_arg *param, const char *fm, int i)
{
	char	*base;
	char	*s;
	int		len;

	s = NULL;
	if (n == 0 && param->prec == 0)
	{
		s = ft_strdup("");
		len = 0;
	}
	else
	{
		base = ft_define_base(fm, i);
		s = ft_put_hex_in_str(n, base);
		len = (int)ft_strlen(s);
		if (param->putzero == 1 || param->prec != -1)
			s = ft_handle_zero_hex_unsigned(param, len, s);
	}
	if (param->minus == 1)
		ft_putstr(param, s);
	ft_hex_space(param, len);
	if (param->minus == -1)
		ft_putstr(param, s);
	free(s);
}
