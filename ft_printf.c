/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:04:56 by tyou              #+#    #+#             */
/*   Updated: 2021/03/08 00:38:02 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write(const int i, t_tlist *t)
{
	write(1, &i, 1);
	t->size++;
}

static int	at_end(int sign, t_tlist *t, va_list ap)
{
	int i;

	i = t->size;
	free(t);
	va_end(ap);
	if (sign == ERROR)
		return (ERROR);
	else
		return (i);
}

static void	keep_size(t_tlist *t)
{
	int tmp;

	tmp = t->size;
	if (t->size > 0)
		ft_memset(t, 0, sizeof(t_tlist));
	t->size = tmp;
}

static int	logic(const char **a, va_list ap, t_tlist *t)
{
	int ret;

	ret = 0;
	if (flag(**a) || (width(**a)))
		flag_wid((char **)a, ap, t);
	if ((char)**a == 'c' || (char)**a == '%')
		ret = ft_char(a, ap, t);
	else if ((char)**a == 'd' || (char)**a == 'i')
		ret = ft_int(a, va_arg(ap, int), t);
	else if ((char)**a == 'u')
		ret = ft_int(a, va_arg(ap, unsigned int), t);
	else if ((char)**a == 's')
		ret = ft_string(a, va_arg(ap, char *), t);
	else if ((char)**a == 'x' || (char)**a == 'X')
		ret = ft_x_p(a, va_arg(ap, unsigned int), t);
	else if ((char)**a == 'p')
		ret = ft_x_p(a, va_arg(ap, unsigned long long), t);
	if (ret == ERROR)
		return (ERROR);
	return (OK);
}

int			ft_printf(const char *input, ...)
{
	int		ret;
	va_list	ap;
	t_tlist	*t;

	if (!(t = malloc(sizeof(t_tlist))))
		return (ERROR);
	ft_memset(t, 0, sizeof(t_tlist));
	va_start(ap, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (logic(&input, ap, t) == ERROR)
				return (at_end(ERROR, t, ap));
			keep_size(t);
			continue ;
		}
		else
		{
			ft_write(*input, t);
			input++;
		}
	}
	return (at_end(OK, t, ap));
}
