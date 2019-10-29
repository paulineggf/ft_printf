/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:40:37 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 14:48:38 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_c(va_list *ap, t_opt *opt)
{
	int		c;
	char	*s;

	check_wildcard(ap, opt);
	c = va_arg(*ap, int);
	s = (char*)&c;
	if (opt->tiret)
		return (fill_str_front(opt->tiret, opt, ' ', s));
	if (opt->zero)
		return (fill_str_back(opt->zero, opt, '0', s));
	if (opt->nbr)
		return (fill_str_back(opt->nbr, opt, ' ', s));
	if (!(opt->str = ft_calloc((1 + 1), 1)))
		return (0);
	opt->str[0] = c;
	return (ft_strlen(opt->str));
}
