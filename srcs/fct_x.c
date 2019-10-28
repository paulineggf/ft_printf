/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:58:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 19:31:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_strrev_space_back(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (!(s2 = malloc(sizeof(char) * (j + 2 + nb))))
		return (NULL);
	while (j >= 0)
		s2[i++] = s[j--];
	while (i < nb)
		s2[i++] = ' ';
	s2[i] = 0;
	return (s2);
}

static char	*ft_strrev_space_front(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (nb > j)
	{
		if (!(s2 = malloc(sizeof(char) * (1 + nb))))
			return (NULL);
	}
	else
	{
		if (!(s2 = malloc(sizeof(char) * (j + 2))))
			return (NULL);
	}
	while (i < (nb - (j + 3)))
		s2[i++] = ' ';
	while (j >= 0)
		s2[i++] = s[j--];
	s2[i] = 0;
	return (s2);
}

static char	*ft_strrev_zero(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (nb > j)
	{
		if (!(s2 = malloc(sizeof(char) * (1 + nb))))
			return (NULL);
	}
	else
	{
		if (!(s2 = malloc(sizeof(char) * (j + 2))))
			return (NULL);
	}
	while (i < (nb - j - 1))
		s2[i++] = '0';
	while (j >= 0)
		s2[i++] = s[j--];
	s2[i] = 0;
	return (s2);
}

static char	*ft_strrev(char *s)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (!(s2 = malloc(sizeof(char) * (j + 2))))
		return (NULL);
	while (j >= 0)
		s2[i++] = s[j--];
	s2[i] = 0;
	return (s2);
}

int		fct_x(va_list *ap, t_list *lst)
{
	unsigned int		d;
	char	*tab;
	char	stock[1000];
	int		i;

	i = 0;
	if (!(tab = ft_strdup("0123456789abcdef")))
		return (0);
	check_wildcard(ap, &lst);
	d = va_arg(*ap, unsigned int);
	while (d > 0)
	{
		stock[i] = tab[d % 16];
		d = d / 16;
		i++;
	}
	stock[i] = 0;
	i = 0;
	if (((t_opt*)(lst->content))->tiret)
	{
		((t_opt*)(lst->content))->str =	ft_strrev_space_back(stock, ((t_opt*)(lst->content))->tiret);
		if (((t_opt*)(lst->content))->type == 'X')
		((t_opt*)(lst->content))->str = ft_strupcase(((t_opt*)(lst->content))->str);
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (((t_opt*)(lst->content))->nbr)
	{
		((t_opt*)(lst->content))->str = ft_strrev_space_front(stock, ((t_opt*)(lst->content))->nbr);
		if (((t_opt*)(lst->content))->type == 'X')
		((t_opt*)(lst->content))->str = ft_strupcase(((t_opt*)(lst->content))->str);
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	if (((t_opt*)(lst->content))->zero)
	{
		((t_opt*)(lst->content))->str =	ft_strrev_zero(stock, ((t_opt*)(lst->content))->zero);
		if (((t_opt*)(lst->content))->type == 'X')
		((t_opt*)(lst->content))->str = ft_strupcase(((t_opt*)(lst->content))->str);
		return (ft_strlen(((t_opt*)(lst->content))->str));
	}
	((t_opt*)(lst->content))->str = ft_strrev(stock);
	if (((t_opt*)(lst->content))->type == 'X')
		((t_opt*)(lst->content))->str = ft_strupcase(((t_opt*)(lst->content))->str);
	return (ft_strlen(((t_opt*)(lst->content))->str));
}
