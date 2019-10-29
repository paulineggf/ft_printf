/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:40:37 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 12:10:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_c(va_list *ap, t_list *lst)
{
	int		c;
	char	*s;

	check_wildcard(ap, &lst);
	c = va_arg(*ap, int);
	s = (char*)&c;
	if (((t_opt*)(lst->content))->tiret)
		return (fill_str_front(((t_opt*)(lst->content))->tiret, lst, ' ', s));
	if (((t_opt*)(lst->content))->zero)
		return (fill_str_back(((t_opt*)(lst->content))->zero, lst, '0', s));
	if (((t_opt*)(lst->content))->nbr)
		return (fill_str_back(((t_opt*)(lst->content))->nbr, lst, ' ', s));
	if (!(((t_opt*)(lst->content))->str = ft_calloc((1 + 1), 1)))
		return (0);
	((t_opt*)(lst->content))->str[0] = c;
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
