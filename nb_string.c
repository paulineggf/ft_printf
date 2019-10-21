/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:49:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/21 21:24:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_string(const char *str, char **type)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			i++;
		if (i != 0)
			count++;
		if (!str[i] && i != 0)
			break ;
		i++;
		//printf("str[i] : %c\n", str[i]);
		while (str[i] && ft_charset(str[i], "cspdiuxX") == -1 && str[i] != '%')
			i++;
		//printf("str[i] : %c\n", str[i]);
		if (!(*type = stock_type(str[i], *type)))
			return (0);
		count++;
		if (str[i] && !str[i + 1])
			break ;
		i++;
	}
	return (count);
}
