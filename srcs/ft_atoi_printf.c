/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:03:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 18:58:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int			ft_atoi_printf(char *s, int *i)
{
	long	res;
	int		j;

	res = 0;
	j = *i;
	if (ft_charset(s[*i], "-.") >= 0)
		(*i)++;
	if (s[*i - 1] == '.' && !ft_isdigit(s[*i]))
		return (-1);
	if (s[*i] == '*')
	{
		(*i)++;
		return (-1);
	}
	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
	while (s[*i] == '+')
		(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		res = res * 10 + (s[*i] - 48);
		(*i)++;
	}
	if (s[j] == '.' && res == 0)
		return (-1);
	return (res);
}
