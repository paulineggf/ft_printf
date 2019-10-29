/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:17:48 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 14:06:59 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_hex(unsigned long nb, char *base, unsigned long len_base)
{
	char			*stock;
	long			i;
	unsigned long	res;
	unsigned long	div;

	i = 0;
	div = 1;
	res = 0;
	if (!(stock = malloc(sizeof(char) * 33)))
		return (NULL);
	while ((nb / div) >= len_base)
		div = div * len_base;
	while (div > 0)
	{
		res = (nb / div) % len_base;
		stock[i++] = base[res];
		div = div / len_base;
	}
	stock[i] = 0;
	return (stock);
}
