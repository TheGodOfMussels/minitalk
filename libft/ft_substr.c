/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:23:39 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/07 16:23:42 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_s;
	char	*sub_s;

	if (s == NULL)
		return (NULL);
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	size_s = ft_strlen(s);
	i = 0;
	while (i < len && i + start < size_s)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
