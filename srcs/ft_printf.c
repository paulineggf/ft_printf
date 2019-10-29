/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:31:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 11:06:21 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_list	*lst;
	int		len;
	va_list	ap;
	int		(*f[8])(va_list *, t_list *);

	if (!*str)
		return (0);
	lst = init_lst(ft_strdup(str));
	init_ptrf(f);
	va_start(ap, str);
	len = 0;
	while (lst)
	{
		if (!(((t_opt*)(lst->content))->str))
			len = (*f[((t_opt*)(lst->content))->type])(&ap, lst) + len;
		else
			len = ft_strlen(((t_opt*)(lst->content))->str) + len;
		ft_putstr(((t_opt*)(lst->content))->str);
		lst = lst->next;
	}
	va_end(ap);
	return (len);
}
