/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:38:13 by tyou              #+#    #+#             */
/*   Updated: 2021/03/08 00:52:44 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ERROR -1
# define OK 0
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct	s_slist
{
	int			size;
	int			width;
	int			width_minus;
	int			minus;
	int			zero;
	int			comma;
	int			comma_zero;
	int			base;
	int			upper;
	int			negative;
}				t_tlist;
int				number(int x);
int				width(int x);
int				flag(int x);
int				ft_printf(const char *input, ...);
void			p_p(const char *tmp);
void			ft_write(const int i, t_tlist *t);
int				num_width(char **tmp, t_tlist *t);
int				ft_lenth(unsigned long long i, t_tlist *t);
int				ft_string(const char **a, char *tmp, t_tlist *t);
int				ft_char(const char **a, va_list ap, t_tlist *t);
int				ft_int(const char **a, long long num, t_tlist *t);
int				ft_x_p(const char **a, unsigned long long num, t_tlist *t);
void			flag_wid(char **a, va_list ap, t_tlist *t);
int				set_basic(unsigned long long num,
									t_tlist *t, char **tmp, char *b);
#endif
