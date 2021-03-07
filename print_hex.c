/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:51:53 by tyou              #+#    #+#             */
/*   Updated: 2021/03/08 00:41:22 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		p_p(const char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		write(1, &tmp[i], 1);
		i++;
	}
}

int			ft_lenth(unsigned long long i, t_tlist *t)
{
	int	a;

	a = 0;
	if (i == 0 && !t->comma_zero)
		return (1);
	while (i)
	{
		a++;
		i /= t->base;
	}
	return (a);
}

static char	*ft_baseset(t_tlist *t)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * t->base + 1)))
		return (NULL);
	while (i < t->base)
	{
		if (i < 10)
			str[i] = i + '0';
		else if (t->upper == 0)
			str[i] = i + 'a' - 10;
		else if (t->upper == 1)
			str[i] = i + 'A' - 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_pmark(char **tmp)
{
	char	*fre;

	fre = *tmp;
	*tmp = ft_strjoin("0x", *tmp);
	free(fre);
	return (2);
}

int			ft_x_p(const char **a, unsigned long long num, t_tlist *t)
{
	int		ret;
	int		len;
	char	*tmp;
	char	*base;

	if (**a == 'X')
		t->upper = 1;
	t->base = 16;
	base = ft_baseset(t);
	len = set_basic(num, t, &tmp, base);
	if (**a == 'p')
		len += ft_pmark(&tmp);
	ret = num_width(&tmp, t);
	p_p(tmp);
	free(tmp);
	free(base);
	t->size += ret;
	(*a)++;
	return (OK);
}
