/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:35:35 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizeofadd(long int n)
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

static char	*ft_put_p_in_str(long int n)
{
	char	*s;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = ft_sizeofadd(n);
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
	if (s == 0 || s == NULL)
		s = ft_strdup("0x0");
	return (s);
}

void		ft_handle_p(long long n, t_arg *param)
{
	char	*s;
	char	*t;
	int		len;

	if (n == 0 && param->prec == 0)
		s = strdup("");
	else if (n == 0)
		s = ft_strdup("0");
	if (n != 0)
		s = ft_put_p_in_str(n);
	t = ft_strjoin("0x", s);
	free(s);
	len = (int)ft_strlen(t);
	t = ft_handle_zero_hex_unsigned(param, len, t);
	if (param->minus == 1)
		ft_putstr(param, t);
	ft_hex_space(param, len);
	if (param->minus == -1)
		ft_putstr(param, t);
	free(t);
}
