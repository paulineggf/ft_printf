/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:50 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 18:36:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_id(va_list *ap, t_list *lst)
{
	int		d;
	int		i;
	int		len;
	/*printf("struct->str : %s\n", ((t_opt*)(lst->content))->str);
	printf("struct->type : %d\n", ((t_opt*)(lst->content))->type);
	printf("struct->tiret : %d\n", ((t_opt*)(lst->content))->tiret);
	printf("struct->zero : %d\n", ((t_opt*)(lst->content))->zero);
	printf("struct->point : %d\n", ((t_opt*)(lst->content))->point);
	printf("struct->wildcard_point : %d\n", ((t_opt*)(lst->content))->wildcard_point);
	printf("struct->wildcard_tiret : %d\n", ((t_opt*)(lst->content))->wildcard_tiret);
	printf("struct->wildcard_nbr : %d\n", ((t_opt*)(lst->content))->wildcard_nbr);
	printf("struct->nbr : %d\n\n", ((t_opt*)(lst->content))->nbr);*/

	check_wildcard(ap, &lst);

	/*printf("struct->str : %s\n", ((t_opt*)(lst->content))->str);
	printf("struct->type : %d\n", ((t_opt*)(lst->content))->type);
	printf("struct->tiret : %d\n", ((t_opt*)(lst->content))->tiret);
	printf("struct->zero : %d\n", ((t_opt*)(lst->content))->zero);
	printf("struct->point : %d\n", ((t_opt*)(lst->content))->point);
	printf("struct->wildcard_point : %d\n", ((t_opt*)(lst->content))->wildcard_point);
	printf("struct->wildcard_tiret : %d\n", ((t_opt*)(lst->content))->wildcard_tiret);
	printf("struct->wildcard_nbr : %d\n", ((t_opt*)(lst->content))->wildcard_nbr);
	printf("struct->nbr : %d\n\n", ((t_opt*)(lst->content))->nbr);*/

	d = va_arg(*ap, int);
	if (((t_opt*)(lst->content))->point && !((t_opt*)(lst->content))->tiret)
	{
		i = 0;
		printf("TEST\n");
		if (((t_opt*)(lst->content))->point > (int)ft_strlen(ft_itoa(d)))
		{
			if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->point + 1), 1)))
				return (-1);
			ft_strcpy(((t_opt*)(lst->content))->str + ((t_opt*)(lst->content))->point - ft_strlen(ft_itoa(d)), ft_itoa(d));
		}
		else
			((t_opt*)(lst->content))->str = ft_strdup(ft_itoa(d));
		while (((t_opt*)(lst->content))->point > (int)ft_strlen(ft_itoa(d)))
		{
			((t_opt*)(lst->content))->str[i] = '0';
			i++;
			((t_opt*)(lst->content))->point--;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (((t_opt*)(lst->content))->tiret && !((t_opt*)(lst->content))->point)
	{
		i = 0;
		
		if (((t_opt*)(lst->content))->zero > (int)ft_strlen(ft_itoa(d)))
		{
			if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->zero + 1), 1)))
				return (-1);
			ft_strcpy(((t_opt*)(lst->content))->str + ((t_opt*)(lst->content))->zero - ft_strlen(ft_itoa(d)), ft_itoa(d));
		}
		else
			((t_opt*)(lst->content))->str = ft_strdup(ft_itoa(d));
		while (((t_opt*)(lst->content))->zero > (int)ft_strlen(ft_itoa(d)))
		{
			((t_opt*)(lst->content))->str[i] = '0';
			i++;
			((t_opt*)(lst->content))->zero--;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (((t_opt*)(lst->content))->tiret && ((t_opt*)(lst->content))->point)
	{
		i = 0;
		if (((t_opt*)(lst->content))->tiret > ((t_opt*)(lst->content))->point)
			len = ((t_opt*)(lst->content))->tiret;
		if (((t_opt*)(lst->content))->tiret < ((t_opt*)(lst->content))->point)
			len = ((t_opt*)(lst->content))->point;
		if ((int)ft_strlen(ft_itoa(d)) > len)
			len = (int)ft_strlen(ft_itoa(d));
		if (!(((t_opt*)(lst->content))->str = ft_calloc((len + 1), 1)))
			return (-1);
		while (((t_opt*)(lst->content))->point > (int)ft_strlen(ft_itoa(d)))
		{
			((t_opt*)(lst->content))->str[i] = '0';
			i++;
			((t_opt*)(lst->content))->point--;
		}
		ft_strcpy(((t_opt*)(lst->content))->str + i, ft_itoa(d));
		i = ft_strlen(ft_itoa(d)) + i;
		while (i < len)
		{
			((t_opt*)(lst->content))->str[i] = ' ';
			i++;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (!(((t_opt*)(lst->content))->str = ft_itoa(d)))
		return (-1);
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
