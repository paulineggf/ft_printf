/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:31:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 17:47:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_list	*lst;
	int		len;
	va_list	ap;
	int		(*f[8])(va_list *, t_opt *);

	if (!*str)
		return (0);
	if (!(lst = init_lst(ft_strdup(str))))
		return (0);
	init_ptrf(f);
	va_start(ap, str);
	len = 0;
	while (lst)
	{
		if (!(((t_opt*)(lst->content))->str))
			len =
			(*f[((t_opt*)(lst->content))->type])(&ap, (t_opt*)(lst->content))
			+ len;
		else
			len = ft_strlen(((t_opt*)(lst->content))->str) + len;
		ft_putstr(((t_opt*)(lst->content))->str);
		lst = lst->next;
	}
	va_end(ap);
	return (len);
}
