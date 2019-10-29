/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_front_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:35:19 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 12:09:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_str_front_back(int tiret, int point, t_list *lst, char *s)
{
	int		i;
	int		len;
	int		len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (tiret >= point)
		len = tiret;
	if (tiret <= point)
		len = point;
	if (len_s > len)
		len = len_s;
	if (!(((t_opt*)(lst->content))->str = ft_calloc((len + 1), 1)))
		return (0);
	while (point > len_s)
	{
		((t_opt*)(lst->content))->str[i] = '0';
		i++;
		point--;
	}
	ft_strcpy(((t_opt*)(lst->content))->str + i, s);
	i = len_s + i;
	while (i < len)
		((t_opt*)(lst->content))->str[i++] = ' ';
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
