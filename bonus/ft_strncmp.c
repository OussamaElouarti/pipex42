/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:03:24 by mashad            #+#    #+#             */
/*   Updated: 2021/10/20 16:28:57 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 == *s2 && *s1 != '\0' && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i != n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
