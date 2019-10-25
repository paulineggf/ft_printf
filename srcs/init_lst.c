/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:40:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 17:34:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*void	init_struct(t_opt **new)
{
	(*new)->tiret = 0;
	(*new)->tiret = 0;
	(*new)->zero = 0;
	(*new)->point = 0;
	(*new)->wildcard = 0;
	(*new)->nbr = 0;
}*/

t_opt	*cpy_string(char *str, int *i)
{
	t_opt	*new;
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (str[*i] && str[*i] != '%')
	{
		(*i)++;
		k++;
	}
	if (*i == j)
		return (NULL);
	if (!(new = malloc(sizeof(t_opt))))
		return (NULL);
	ft_bzero(new, sizeof(t_opt));
	new->str = ft_strndup(&str[j], k);
	return (new);
}

t_opt	*cpy_opt(char *str, int *i)
{
	t_opt	*new;

	if (!(new = malloc(sizeof(t_opt))))
		return (NULL);
	ft_bzero(new, sizeof(t_opt));
	while (str[*i] && ft_charset(str[*i], "cspdiuxX") == -1)
	{
		if (str[*i] == '0' && str[*i - 1] == '%'
		&& ft_charset(str[(*i) + 1], "0123456789*") >= 0)
		{	
			new->zero = ft_atoi_printf(str, i);
			if (str[(*i) - 1] == '*')
				new->wildcard_zero += 1;
			while (ft_charset(str[*i], "0123456789*") >= 0)
			{
				new->zero = ft_atoi_printf(str, i);
				if (str[(*i) - 1] == '*')
					new->wildcard_zero += 1;
			}
		}
		else if (str[*i] == '-'
		&& ft_charset(str[(*i) + 1], "0123456789*") >= 0)
		{
			new->tiret = ft_atoi_printf(str, i);
			if (str[(*i) - 1] == '*')
				new->wildcard_tiret += 1;
			while (ft_charset(str[*i], "0123456789*") >= 0)
			{
				new->tiret = ft_atoi_printf(str, i);
				if (str[(*i) - 1] == '*')
					new->wildcard_tiret += 1;
			}
		}
		else if (str[*i] == '.'
		&& ft_charset(str[(*i) + 1], "0123456789*") >= 0)
		{
			new->point = ft_atoi_printf(str, i);
			if (str[(*i) - 1] == '*')
				new->wildcard_point += 1;
			while (ft_charset(str[*i], "0123456789*") >= 0)
			{
				new->point = ft_atoi_printf(str, i);
				new->wildcard_point += 1;
			}
		}
		else if (ft_charset(str[*i], "123456789*") >= 0)
		{
			new->nbr = ft_atoi_printf(str, i);
			if (str[(*i) - 1] == '*')
				new->wildcard_tiret += 1;
			while (ft_charset(str[*i], "0123456789*") >= 0)
			{
				new->nbr = ft_atoi_printf(str, i);
				if (str[(*i) - 1] == '*')
					new->wildcard_nbr += 1;
			}
		}
		else if (str[(*i)++] == '%')
		{
			new->str = ft_strdup("%");
			return (new);
		}
	}
	new->type = match_type(str[*i]);
	(*i)++;
	return (new);
}

t_list		*init_lst(char *str)
{
	t_list	*lst;
	t_opt	*opt;
	int		i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		if ((opt = cpy_string(str, &i)))
			ft_lstadd_back(&lst, ft_lstnew(opt));
		if (str[i] == '%')
		{
			i++;
			ft_lstadd_back(&lst, ft_lstnew((void*)cpy_opt(str, &i)));
		}
	}
	return (lst);
}
