/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:27:44 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/01/15 15:31:26 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int				ft_printf(const char *fm, ...);
char			*ft_strndup(const char *s1, int n);

typedef	struct	s_argument
{
	int zero;
	int minus;
	int width;
	int prec;
	int count;
	int putzero;
	int nb_of_zero;
	int intneg;
	int error;

}				t_arg;
void			ft_init_s_args(t_arg *param);
int				check_zerominus(t_arg *param, const char *fm, int id);
int				check_width(va_list va, t_arg *param, const char *fm, int id);
int				check_prec(va_list va, t_arg *param, const char *fm, int id);
void			ft_handle_all(va_list va, t_arg *param, const char *fm, int i);
int				ft_check_segfault(int i, const char *fm);
int				check_flags(va_list va, t_arg *param, const char *fm, int id);
void			ft_putchar(t_arg *param, char c);
int				ft_sizeofint(long long n);
void			ft_putnbr(t_arg *param, int n);
void			ft_char_space(t_arg *param);
void			ft_hex_space(t_arg *param, int len);
void			ft_int_space(t_arg *param, int len);
void			ft_handle_char(int c, t_arg *param);
void			ft_handle_str(char *str, t_arg *param);
char			*ft_handle_zero_hex_unsigned(t_arg *param, int len, char *s);
char			*ft_putzero_hex_unsigned(char *s, int nb_z);
void			ft_putstr(t_arg *param, char *str);
void			ft_handle_int(int n, t_arg *param);
int				ft_sizeofhex(unsigned int n);
void			ft_x(unsigned int n, t_arg *param, const char *fm, int i);
void			ft_handle_p(long long n, t_arg *param);
void			ft_hanlde_unsigned(unsigned int n, t_arg *param);
void			ft_handle_pourcent(int c, t_arg *param);

#endif
