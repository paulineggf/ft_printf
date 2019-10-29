/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:50:08 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 19:15:12 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_wildcard(va_list *ap, t_opt *opt)
{
	while (opt->wildcard_tiret > 0)
	{
		opt->tiret = va_arg(*ap, int);
		opt->wildcard_tiret--;
	}
	while (opt->wildcard_point > 0)
	{
		opt->point = va_arg(*ap, int);
		opt->wildcard_point--;
	}
	while (opt->wildcard_nbr > 0)
	{
		opt->nbr = va_arg(*ap, int);
		opt->wildcard_point--;
	}
	while (opt->wildcard_zero > 0)
	{
		opt->zero = va_arg(*ap, int);
		opt->wildcard_zero--;
	}
}
