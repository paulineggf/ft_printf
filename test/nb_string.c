/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:50:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 12:55:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_opt **new)
{
	new->type = 0;
	new->tiret = 0;
	new->zero = 0;
	new->point = 0;
	new->wildcard = 0;
	new->ord_nbr = 0;
	new->nbr = 0;
	new->next = NULL;
}

t_opt	*cpy_string(const char *str, int *i)
{
	t_opt	*new;

	while (str[*i] && str[*i] != '%')
		(*i)++;
	if (*i == 0)
		return (NULL);
	if (!(new = malloc(sizeof(t_opt))))
		return (NULL);
	new->str = ft_strndup(str, *i);
	init_struct(&new);
	return (new);
}

t_opt	*cpy_opt(const char *str, int *i)
{
	t_opt 	*new;
	int		ord;

	if (!(new = malloc(sizeof(t_opt))))
		return (NULL);
	init_struct(&new);
	new->str = NULL;
	ord = 1;
	(*i)++;
	while (str[*i] && ft_charset(str[*i], "cspdiuxX") == -1)
	{
		if (str[*i] == '0' && !new->zero && !new->tiret)
			new->zero = ord;
		else if (str[*i] == '-' && !new->zero)
			new->tiret = ord;
		else if (str[*i] == '.')
			new->point = ord;
		else if (str[*i] == '%')
			if (ord == 1)
				new->str = ft_strdup("%%");
		else if (str[*i] == '*')
			new->wildcard == ord;
		else if (ft_charset(str[*i], "123456789") >= 0 && !new->ord_nbr)
		{
			new->ord_nbr = ord;
			new->nbr = ft_natoi(str[*i], i);
		}
		ord++;
	}
	return ();
}

t_opt	*nb_string(const char *str)
{
	t_opt	*opt;
	int		i;

	i = 0;
	opt = NULL;
	while (str[i])
	{
		ft_lstadd_back(&opt, cpy_string(&str[i], &i));
		if (str[i] == '%')
			ft_lstadd_back(&opt, cpy_opt(&str[i], &i));
		return (opt);
	}
	return (opt);
}
