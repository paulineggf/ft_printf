/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:40:37 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 16:09:05 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_c(va_list *ap, t_list *lst)
{
	int		c;
	int		i;
	

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
	
	c = va_arg(*ap, int);
	if (((t_opt*)(lst->content))->tiret)
	{
		i = 1;
		if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->tiret + 1), 1)))
			return (-1);
		((t_opt*)(lst->content))->str[0] = c;
		while (((t_opt*)(lst->content))->tiret > 1)
		{
			((t_opt*)(lst->content))->str[i] = ' ';
			i++;
			((t_opt*)(lst->content))->tiret--;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (((t_opt*)(lst->content))->zero)
	{
		i = 0;
		if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->zero + 1), 1)))
			return (-1);
		((t_opt*)(lst->content))->str[(((t_opt*)(lst->content))->zero) - 1] = c;
		while (((t_opt*)(lst->content))->zero > 1)
		{
			((t_opt*)(lst->content))->str[i] = '0';
			i++;
			((t_opt*)(lst->content))->zero--;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (((t_opt*)(lst->content))->nbr)
	{
		i = 0;
		if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->nbr + 1), 1)))
			return (-1);
		((t_opt*)(lst->content))->str[(((t_opt*)(lst->content))->nbr) - 1] = c;
		while (((t_opt*)(lst->content))->nbr > 1)
		{
			((t_opt*)(lst->content))->str[i] = ' ';
			i++;
			((t_opt*)(lst->content))->nbr--;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (!(((t_opt*)(lst->content))->str = ft_calloc((1 + 1), 1)))
			return (-1);
	((t_opt*)(lst->content))->str[0] = c;
	((t_opt*)(lst->content))->str[1] = '\0';
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
