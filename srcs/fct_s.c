/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:28 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 14:49:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_s(va_list *ap, t_opt *opt)
{
	char	*s;

	check_wildcard(ap, opt);
	s = va_arg(*ap, char *);
	if (opt->point)
		if (!(s = ft_strndup(s, opt->point)))
			return (0);
	if (opt->tiret)
		return (fill_str_front(opt->tiret, opt, ' ', s));
	if (opt->zero)
		return (fill_str_back(opt->zero, opt, '0', s));
	if (opt->nbr)
		return (fill_str_back(opt->nbr, opt, ' ', s));
	if (!(opt->str = ft_strdup(s)))
		return (0);
	return (ft_strlen(opt->str));
}
