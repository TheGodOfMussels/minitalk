/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:06:19 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/05 18:06:20 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		d = dest + n;
		s = src + n;
		while (n-- > 0)
			*--d = *--s;
	}
	else
	{
		d = dest;
		s = src;
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}
