/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:08:46 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/12 16:08:49 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1);
	dup = ft_calloc(size + 1, 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}
