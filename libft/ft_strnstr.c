/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:13:48 by mguille           #+#    #+#             */
/*   Updated: 2023/02/10 21:13:51 by mguille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *comp, size_t len)
{
	size_t	i;
	size_t	n;

	if (src == NULL && len == 0)
		return (NULL);
	i = 0;
	if (comp[0] == '\0')
		return ((char *)src);
	while (src[i] != '\0')
	{
		n = 0;
		while (src[i + n] == comp[n] && (i + n) < len)
		{
			if (src[i + n] == '\0' && comp[n] == '\0')
				return ((char *)&src[i]);
			n++;
		}
		if (comp[n] == '\0')
			return ((char *)src + i);
		i++;
	}
	return (0);
}
