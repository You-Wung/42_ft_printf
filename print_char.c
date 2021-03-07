/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:41:55 by tyou              #+#    #+#             */
/*   Updated: 2021/03/07 01:14:08 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_width_char(int i, t_tlist *t)
{
	int	j;

	j = 0;
	while (j < t->width - i)
	{
		if (t->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		t->size++;
		j++;
	}
}

static void		print_string(const char *str, int size, t_tlist *t)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (t->comma)
		len = t->comma < size ? t->comma : size;
	else
		len = size;
	while (i < len)
	{
		if (t->comma_zero || (t->comma <= i && t->comma))
			write(1, " ", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int				ft_char(const char **a, va_list ap, t_tlist *t)
{
	int		tmp;

	if (**a == '%')
		tmp = '%';
	else
		tmp = va_arg(ap, int);
	if (t->minus == 1)
		write(1, &tmp, 1);
	put_width_char(1, t);
	if (t->minus == 0)
		write(1, &tmp, 1);
	t->size++;
	(*a)++;
	return (OK);
}

int				ft_string(const char **a, char *tmp, t_tlist *t)
{
	int	i;

	if (t->comma_zero)
		tmp = "";
	else if (tmp == NULL)
		tmp = "(null)";
	i = t->comma < ft_strlen(tmp) && t->comma ? t->comma : ft_strlen(tmp);
	t->size += i;
	if (t->minus == 0)
		put_width_char(i, t);
	print_string(tmp, i, t);
	if (t->minus == 1)
		put_width_char(i, t);
	(*a)++;
	return (OK);
}
