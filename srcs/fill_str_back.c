/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:00:49 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 18:53:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_str_back(int nb, t_opt *opt, char c, char *s)
{
	int		len_s;
	int		i;

	if (*s == '0' && opt->point == -1)
	{
		if (!(opt->str = malloc(sizeof(char) )))
			return (0);
		opt->str[0]= 0;
		return (0);
	}
	len_s = ft_strlen(s);
	i = 0;
	if (nb > len_s)
	{
		if (!(opt->str = ft_calloc((nb + 1), 1)))
			return (0);
		ft_strcpy(opt->str + nb - len_s, s);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	while (nb > len_s)
	{
		opt->str[i] = c;
		i++;
		nb--;
	}
	return (ft_strlen(opt->str));
}
