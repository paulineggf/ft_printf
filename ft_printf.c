/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:31:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 20:45:58 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_opt	*opt;
	int		len;
	va_list	ap;
	char	c;
	int		(*f[8])(va_list *, t_opt *);

	if (!*str)
		return (0);
	opt = init_lst(str);
	init_ptrf(f);
	va_start(ap, str);
	len = 0;
	while (opt)
	{
		if (!opt->str)
			len = (*f[opt->type])(&ap, opt) + len;
		else
			len = ft_strlen(opt->str) + len;
		ft_putstr(opt->str);
		opt = opt->next;
	}
	va_end(ap);
	return (len);
}
