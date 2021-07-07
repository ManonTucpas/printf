/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:56:06 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:28 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_putminus(t_arg *param, char *szero)
{
	if (param->intneg == 1)
		szero = ft_strjoin("-", szero);
	return (szero);
}

static char		*ft_putzero(char *s, int nb_of_zero)
{
	char	*szero;
	int		i;
	char	*tmp;

	i = 0;
	szero = (char *)malloc(sizeof(char) * (i + 1));
	if (!szero)
		return (0);
	while (i != nb_of_zero)
	{
		szero[i] = '0';
		i++;
	}
	szero[i] = '\0';
	tmp = s;
	s = ft_strjoin(szero, tmp);
	free(szero);
	free(tmp);
	return (s);
}

static char		*ft_handle_zero(t_arg *param, int len, char *s)
{
	if (param->putzero != -1 || param->prec > len)
	{
		if (param->prec > len)
		{
			param->nb_of_zero = param->prec - len;
			s = ft_putzero(s, param->nb_of_zero);
		}
		else if ((param->intneg == 1 && param->prec <= 0 && param->width == -1)
			|| (param->prec < len && param->width != -1 && param->prec != -1)
				|| (param->minus == 1 && param->prec < len))
			param->nb_of_zero = 0;
		else if ((param->width > len && param->prec > len)
			|| (param->width > len && param->prec < 0))
		{
			if (param->intneg == 1)
				len++;
			param->nb_of_zero = param->width - len;
			s = ft_putzero(s, param->nb_of_zero);
		}
	}
	return (s);
}

static void		ft_put_int(t_arg *param, char *s, int len)
{
	if (param->minus == 1)
	{
		s = ft_putminus(param, s);
		ft_putstr(param, s);
	}
	ft_int_space(param, len);
	if (param->minus == -1)
	{
		s = ft_putminus(param, s);
		ft_putstr(param, s);
	}
}

void			ft_handle_int(int n, t_arg *param)
{
	int		len;
	char	*s;
	char	*tmp;

	s = ft_itoa((long long)n);
	len = (int)ft_strlen(s);
	if (param->prec == 0 && n == 0)
	{
		free(s);
		s = ft_strdup("");
		len = 0;
	}
	else if (s[0] == '-')
	{
		tmp = s;
		s = ft_substr(tmp, 1, len);
		free(tmp);
		param->intneg = 1;
		len--;
	}
	if (param->putzero == 1 || param->prec != -1)
		s = ft_handle_zero(param, len, s);
	ft_put_int(param, s, len);
	free(s);
}
