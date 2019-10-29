/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptrf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:16:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 14:44:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_ptrf(int (**f)(va_list *ap, t_opt *opt))
{
	f[0] = fct_p;
	f[1] = fct_c;
	f[2] = fct_s;
	f[3] = fct_id;
	f[4] = fct_id;
	f[5] = fct_u;
	f[6] = fct_x;
	f[7] = fct_x;
}
