/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:40:37 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 20:45:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fct_c(va_list *ap, t_opt *opt)
{
	char	c;

	printf("TEST ccc\n");
	c = va_arg(*ap, int);
	opt->str = ft_strndup(&c, 1);
	printf("c : %c\n", c);
	return (1);
}
