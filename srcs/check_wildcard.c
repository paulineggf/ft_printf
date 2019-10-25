/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:50:08 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 17:34:58 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_wildcard(va_list *ap, t_list **lst)
{
	while (((t_opt*)((*lst)->content))->wildcard_tiret > 0)
	{
		((t_opt*)((*lst)->content))->tiret = va_arg(*ap, int);
		((t_opt*)((*lst)->content))->wildcard_tiret--;
	}
	while (((t_opt*)((*lst)->content))->wildcard_point > 0)
	{
		((t_opt*)((*lst)->content))->point = va_arg(*ap, int);
		((t_opt*)((*lst)->content))->wildcard_point--;
	}
	while (((t_opt*)((*lst)->content))->wildcard_nbr > 0)
	{
		((t_opt*)((*lst)->content))->nbr = va_arg(*ap, int);
		((t_opt*)((*lst)->content))->wildcard_point--;
	}
	while (((t_opt*)((*lst)->content))->wildcard_zero > 0)
	{
		((t_opt*)((*lst)->content))->zero = va_arg(*ap, int);
		((t_opt*)((*lst)->content))->wildcard_zero--;
	}
}
