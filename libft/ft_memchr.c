/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:23:13 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/05 18:23:14 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (const unsigned char *) s;
	while (n-- > 0)
	{
		if (*str == (unsigned char) c)
			return ((void *) str);
		str++;
	}
	return (0);
}
