/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:51:33 by mguille           #+#    #+#             */
/*   Updated: 2022/12/06 20:51:36 by mguille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	nbr;
	unsigned int	x;

	nbr = 0;
	x = 0;
	while (src[nbr] != '\0')
		nbr++;
	if (size != 0)
	{
		while (src[x] != '\0' && x < (size - 1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (nbr);
}
