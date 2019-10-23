/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:03:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 15:17:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *s, int *i)
{
	long	res;

	res = 0;
	(*i)++;
	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
	while (s[*i] == '+')
		(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		res = res * 10 + (s[*i] - 48);
		(*i)++;
	}
	return (res);
}
