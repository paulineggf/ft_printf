/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:50 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 14:48:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_id(va_list *ap, t_opt *opt)
{
	int		d;
	char	*s;

	check_wildcard(ap, opt);
	d = va_arg(*ap, int);
	if (!(s = ft_itoa(d)))
		return (0);
	if (opt->point && !opt->tiret && !opt->zero)
		return (fill_str_back(opt->point, opt, '0', s));
	if (opt->tiret && !opt->point)
		return (fill_str_front(opt->tiret, opt, ' ', s));
	if (opt->nbr)
		return (fill_str_back(opt->nbr, opt, ' ', s));
	if (opt->zero && !opt->point)
		return (fill_str_back(opt->zero, opt, '0', s));
	if (opt->tiret && opt->point)
		return (fill_str_front_back(opt->tiret, opt->point, opt, s));
	if (opt->zero && opt->point)
		return (fill_str_back_front(opt->zero, opt->point, opt, s));
	if (!(opt->str = ft_strdup(s)))
		return (0);
	return (ft_strlen(opt->str));
}
