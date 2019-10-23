/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:22:20 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 20:28:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_enum(char c)
{
	if (c == 'p')
		return (0);
	else if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'd')
		return (3);
	else if (c == 'i')
		return (4);
	else if (c == 'u')
		return (5);
	else if (c == 'x')
		return (6);
	else
		return (7);
}
