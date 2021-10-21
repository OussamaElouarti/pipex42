/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:43:47 by mashad            #+#    #+#             */
/*   Updated: 2021/10/20 16:28:04 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	char	db;
	char	*str;
	int		size;

	str = (char *)s;
	db = (char)c;
	size = ft_strlen(s);
	while (size >= 0)
	{
		if (*str == db)
			return (str);
		size--;
		str++;
	}
	return (NULL);
}
