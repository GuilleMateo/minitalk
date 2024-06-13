/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:23:16 by mguille           #+#    #+#             */
/*   Updated: 2023/02/28 00:23:24 by mguille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	test;

	test = size * count;
	if (test / size != count)
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	ret = malloc(size * count);
	if (!ret)
		return (NULL);
	ft_memset(ret, '\0', size * count);
	return (ret);
}
