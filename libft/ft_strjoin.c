/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:36:46 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/07 16:36:47 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;	
	int		a;
	int		b;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	a = 0;
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b] != '\0')
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = '\0';
	return (str);
}
