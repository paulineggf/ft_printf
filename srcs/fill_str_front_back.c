/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_front_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:35:19 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 18:34:48 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_str_front_back(int tiret, int point, t_opt *opt, char *s)
{
	int		i;
	int		len;
	int		len_s;

	i = 0;
	if (*s == '0' && point == -1)
	{
		if (!(opt->str = malloc(sizeof(char) * (tiret + 1))))
			return (0);
		opt->str = ft_memset(opt->str, ' ', tiret);
		opt->str[tiret] = 0;
		return (tiret);
	}
	len_s = ft_strlen(s);
	if (tiret >= point)
		len = tiret;
	if (tiret <= point)
		len = point;
	if (len_s > len)
		len = len_s;
	if (!(opt->str = ft_calloc((len + 1), 1)))
		return (0);
	while (point > len_s)
	{
		opt->str[i] = '0';
		i++;
		point--;
	}
	ft_strcpy(opt->str + i, s);
	i = len_s + i;
	while (i < len)
		opt->str[i++] = ' ';
	return (ft_strlen(opt->str));
}
