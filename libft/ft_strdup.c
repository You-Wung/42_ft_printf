/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:18:37 by tyou              #+#    #+#             */
/*   Updated: 2021/02/26 20:20:26 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*rt;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[size])
		size++;
	if (!(rt = (char*)malloc(size + 1)))
		return (0);
	while (i < size)
	{
		rt[i] = s1[i];
		i++;
	}
	rt[i] = '\0';
	return (rt);
}
