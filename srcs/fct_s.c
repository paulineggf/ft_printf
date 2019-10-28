/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:28 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 16:09:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_s(va_list *ap, t_list *lst)
{
	char	*s;

	check_wildcard(ap, &lst);
	s = va_arg(*ap, char *);
	if (((t_opt*)(lst->content))->point)
		s = ft_strndup(s, ((t_opt*)(lst->content))->point);
	if (((t_opt*)(lst->content))->tiret)
		return (fill_str_front(((t_opt*)(lst->content))->tiret, lst, ' ', s));
	if (((t_opt*)(lst->content))->zero)
		return (fill_str_back(((t_opt*)(lst->content))->zero, lst, '0', s));
	if (((t_opt*)(lst->content))->nbr)
		return (fill_str_back(((t_opt*)(lst->content))->nbr, lst, ' ', s));
	if (!(((t_opt*)(lst->content))->str = ft_strdup(s)))
		return (-1);
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
