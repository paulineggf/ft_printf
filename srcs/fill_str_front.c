/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:06:59 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 13:07:22 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_str_front(int nb, t_list *lst, char c, char *s)
{
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	i = len_s;
	if (nb > len_s)
	{
		if (!(((t_opt*)(lst->content))->str = ft_calloc((nb + 1), 1)))
			return (-1);
		ft_strcpy(((t_opt*)(lst->content))->str, s);
	}
	else
		((t_opt*)(lst->content))->str = ft_strdup(s);
	while (nb > len_s)
	{
		((t_opt*)(lst->content))->str[i] = c;
		i++;
		nb--;
	}
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
