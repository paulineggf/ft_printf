/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_back_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:06:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 18:26:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_str_back_front(int zero, int point, t_list *lst, char *s)
{
	int		i;
	int		len;
	int		len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (zero >= point)
		len = zero;
	if (zero <= point)
		len = point;
	if (len_s > len)
		len = len_s;
	if (!(((t_opt*)(lst->content))->str = ft_calloc((len + 1), 1)))
		return (-1);
	if (len != len_s)
	{
		while (i < (zero - point))
			((t_opt*)(lst->content))->str[i++] = ' ';
		while (point-- > len_s)
			((t_opt*)(lst->content))->str[i++] = '0';
	}
	ft_strcpy(((t_opt*)(lst->content))->str + i, s);
	return (len);
}
