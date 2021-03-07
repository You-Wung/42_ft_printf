/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:11:05 by tyou              #+#    #+#             */
/*   Updated: 2021/03/08 00:45:36 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	minus(t_tlist *t, char **tmp, int len, int sign)
{
	char *fre;

	if (t->negative && !t->zero && sign == 1)
	{
		fre = *tmp;
		*tmp = ft_strjoin("-", *tmp);
		free(fre);
		return (1);
	}
	else if (t->negative && t->zero && sign == 2)
	{
		if (len >= t->width)
		{
			fre = *tmp;
			*tmp = ft_strjoin("-", *tmp);
			free(fre);
			return (1);
		}
		else if (len < t->width)
			*tmp[0] = '-';
	}
	return (0);
}

int			set_basic(unsigned long long num, t_tlist *t, char **tmp, char *b)
{
	int len;
	int	ret;
	int	i;

	len = ft_lenth(num, t);
	ret = t->comma > len ? t->comma : len;
	if (!(*tmp = malloc(ret + 1)))
		return (ERROR);
	(*tmp)[ret] = '\0';
	i = 0;
	while (len + i < ret)
		(*tmp)[i++] = '0';
	i = 1;
	if (num == 0 && !t->comma_zero)
		(*tmp)[ret - 1] = '0';
	while (num)
	{
		if (t->base == 10)
			(*tmp)[ret - i] = 48 + (num % 10);
		else if (t->base == 16)
			(*tmp)[ret - i] = b[num % t->base];
		num /= t->base;
		i++;
	}
	return (ret);
}

int			num_width(char **tmp, t_tlist *t)
{
	char	*width;
	char	*fre;
	int		i;

	if (t->width <= (ft_strlen(*tmp)))
		return (ft_strlen(*tmp));
	if (!(width = malloc((t->width - ft_strlen(*tmp) + 1))))
		return (ERROR);
	i = 0;
	while (i < t->width - ft_strlen(*tmp))
	{
		width[i] = t->zero ? '0' : ' ';
		i++;
	}
	width[i] = '\0';
	fre = *tmp;
	if (t->minus == 0)
		*tmp = ft_strjoin(width, *tmp);
	else
		*tmp = ft_strjoin(*tmp, width);
	free(fre);
	free(width);
	return (t->width);
}

int			ft_int(const char **a, long long num, t_tlist *t)
{
	int		ret;
	int		len;
	char	*tmp;

	if (num < 0)
	{
		t->negative = 1;
		num = -num;
	}
	t->base = 10;
	len = set_basic(num, t, &tmp, 0);
	len += minus(t, &tmp, 0, 1);
	ret = num_width(&tmp, t);
	ret += minus(t, &tmp, len, 2);
	p_p(tmp);
	free(tmp);
	t->size += ret;
	(*a)++;
	return (OK);
}
