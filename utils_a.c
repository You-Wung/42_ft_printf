/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:07:36 by tyou              #+#    #+#             */
/*   Updated: 2021/03/08 00:47:22 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wid(char **a, t_tlist *t)
{
	if (width(**a))
	{
		t->width = ft_atoi(*a);
		while (number(**a))
			(*a)++;
	}
}

static void	comma(char **a, va_list ap, t_tlist *t)
{
	(*a)++;
	if (**a == '*')
	{
		t->comma = va_arg(ap, int);
		if (t->comma < 0)
			t->comma = 0;
		else if (t->comma == 0)
			t->comma_zero = 1;
		(*a)++;
	}
	else if ((number(**a)))
	{
		t->comma = ft_atoi(*a);
		if (t->comma < 0)
		{
			t->width = -t->comma;
			t->comma = 0;
		}
		else if (t->comma == 0)
			t->comma_zero = 1;
	}
	else
		t->comma_zero = 1;
	while (number(**a))
		(*a)++;
}

static void	minus(char **a, va_list ap, t_tlist *t)
{
	(*a)++;
	t->minus = 1;
	while (**a == '0')
		(*a)++;
	if (**a == '*' || (width(**a)))
		ft_wid(a, t);
}

static void	star(char **a, va_list ap, t_tlist *t)
{
	(*a)++;
	t->width = va_arg(ap, int);
	if (t->width < 0)
	{
		t->width *= -1;
		t->minus = 1;
		if (t->zero || *(*a - 1) == '%')
			t->zero = 0;
	}
}

void		flag_wid(char **a, va_list ap, t_tlist *t)
{
	ft_wid(a, t);
	while (flag(**a))
	{
		if (**a == '-')
			minus(a, ap, t);
		if (**a == '.')
			comma(a, ap, t);
		if (**a == '*')
			star(a, ap, t);
		if (**a == '0' && !t->width && !t->comma)
		{
			(*a)++;
			t->zero = 1;
			t->width = ft_atoi(*a);
			while (number(**a))
				(*a)++;
		}
	}
	if ((t->comma < t->width && t->comma && **a != '%')
						|| (t->comma_zero && **a != '%'))
		t->zero = 0;
}
