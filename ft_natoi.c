/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:15:51 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/22 15:27:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		sign;
	long	res;

	*i = 0;
	sign = 1;
	res = 0;
	while (s[i] && ft_isdigit(s[*i]))
	{
		res = res * 10 + (s[*i] - 48);
		(*i)++;
	}
	return (res * sign);
}
