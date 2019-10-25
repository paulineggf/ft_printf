/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:28 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 17:38:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fct_s(va_list *ap, t_list *lst)
{
	char 	*s;
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
	
	s = va_arg(*ap, char *);
	if (((t_opt*)(lst->content))->point)
	{
		s = ft_strndup(s, ((t_opt*)(lst->content))->point);
	}
	if (((t_opt*)(lst->content))->tiret)
	{
		i = ft_strlen(s);

		if (((t_opt*)(lst->content))->tiret > (int)ft_strlen(s))
		{
			if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->tiret + 1), 1)))
				return (-1);
			ft_strcpy(((t_opt*)(lst->content))->str, s);
		}
		else
			((t_opt*)(lst->content))->str = ft_strdup(s);
		while (((t_opt*)(lst->content))->tiret > (int)ft_strlen(s))
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

		if (((t_opt*)(lst->content))->zero > (int)ft_strlen(s))
		{
			if (!(((t_opt*)(lst->content))->str = ft_calloc((((t_opt*)(lst->content))->zero + 1), 1)))
				return (-1);
			ft_strcpy(((t_opt*)(lst->content))->str + ((t_opt*)(lst->content))->zero - ft_strlen(s), s);
		}
		else
			((t_opt*)(lst->content))->str = ft_strdup(s);
		while (((t_opt*)(lst->content))->zero > (int)ft_strlen(s))
		{
			((t_opt*)(lst->content))->str[i] = '0';
			i++;
			((t_opt*)(lst->content))->zero--;
		}
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}

	if (!(((t_opt*)(lst->content))->str = ft_strdup(s)))
		return (-1);
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
