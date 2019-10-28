/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:50 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 15:57:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_id(va_list *ap, t_list *lst)
{
	int		d;
	char	*s;

	check_wildcard(ap, &lst);
	d = va_arg(*ap, int);
	s = ft_itoa(d);
	if (((t_opt*)(lst->content))->point && !((t_opt*)(lst->content))->tiret
	&& !((t_opt*)(lst->content))->zero)
		return (fill_str_back(((t_opt*)(lst->content))->point, lst, '0', s));
	if (((t_opt*)(lst->content))->tiret && !((t_opt*)(lst->content))->point)
		return (fill_str_front(((t_opt*)(lst->content))->tiret, lst, ' ', s));
	if (((t_opt*)(lst->content))->zero && !((t_opt*)(lst->content))->point)
		return (fill_str_back(((t_opt*)(lst->content))->zero, lst, '0', s));
	if (((t_opt*)(lst->content))->tiret && ((t_opt*)(lst->content))->point)
		return (fill_str_front_back(((t_opt*)(lst->content))->tiret,
		((t_opt*)(lst->content))->point, lst, s));
	if (((t_opt*)(lst->content))->zero && ((t_opt*)(lst->content))->point)
		return (fill_str_back_front(((t_opt*)(lst->content))->zero,
		((t_opt*)(lst->content))->point, lst, s));
	if (!(((t_opt*)(lst->content))->str = ft_strdup(s)))
		return (-1);
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
