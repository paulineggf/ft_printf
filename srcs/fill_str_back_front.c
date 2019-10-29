/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_back_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:06:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 18:42:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_str_back_front(int zero, int point, t_opt *opt, char *s)
{
	int		i;
	int		len;
	int		len_s;

	i = 0;
	if (*s == '0' && point == -1)
	{
		if (!(opt->str = malloc(sizeof(char) * (zero + 1))))
			return (0);
		opt->str = ft_memset(opt->str, ' ', zero);
		opt->str[zero] = 0;
		return (zero);
	}
	len_s = ft_strlen(s);
	if (zero >= point)
		len = zero;
	if (zero <= point)
		len = point;
	if (len_s > len)
		len = len_s;
	if (!(opt->str = ft_calloc((len + 1), 1)))
		return (0);
	if (len_s > point)
		point = len_s;
	if (len != len_s)
	{
		while (i < (zero - point))
			opt->str[i++] = ' ';
		while (point-- > len_s)
			opt->str[i++] = '0';
	}
	ft_strcpy(opt->str + i, s);
	return (len);
}
