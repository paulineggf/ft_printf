/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:56:47 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/30 17:12:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_space_back(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;
	int		len_s;

	i = 2;
	j = 0;
	len_s = ft_strlen(s);
	if (!(s2 = malloc(sizeof(char) * (len_s + 2 + nb))))
		return (NULL);
	s2[0] = '0';
	s2[1] = 'x';
	while (s[j])
		s2[i++] = s[j++];
	while (i < nb)
		s2[i++] = ' ';
	s2[i] = 0;
	return (s2);
}

static char	*ft_space_front(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;
	int		len_s;

	i = 0;
	j = 0;
	len_s = ft_strlen(s);
	if (nb > (len_s - 1))
	{
		if (!(s2 = ft_calloc((3 + nb), 1)))
			return (NULL);
	}
	else
	{
		if (!(s2 = ft_calloc((len_s + 3), 1)))
			return (NULL);
	}
	while (i < (nb - (len_s + 2)))
		s2[i++] = ' ';
	s2[i++] = '0';
	s2[i++] = 'x';
	while (s[j])
		s2[i++] = s[j++];
	return (s2);
}

static char	*ft_point(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;
	int		len_s;

	i = 2;
	j = 0;
	len_s = ft_strlen(s);
	if (nb > (len_s - 1))
	{
		if (!(s2 = ft_calloc((3 + nb), 1)))
			return (NULL);
	}
	else
	{
		if (!(s2 = ft_calloc((len_s + 3), 1)))
			return (NULL);
	}
	s2[0] = '0';
	s2[1] = 'x';
	while ((i - 2) < (nb - len_s))
		s2[i++] = '0';
	while (s[j])
		s2[i++] = s[j++];
	return (s2);
}

static char	*ft_0x(char *s)
{
	char	*s2;
	int		i;
	int		j;

	i = 2;
	j = 0;
	if (!(s2 = malloc(sizeof(char) * (ft_strlen(s) + 3))))
		return (NULL);
	s2[0] = '0';
	s2[1] = 'x';
	while (s[j])
		s2[i++] = s[j++];
	s2[i] = 0;
	return (s2);
}

int			fct_p(va_list *ap, t_opt *opt)
{
	unsigned long	add;
	int				i;

	i = 0;
	//check_wildcard(ap, opt);
	add = va_arg(*ap, unsigned long);
	if (!(opt->str = convert_hex(add, "0123456789abcdef", 16)))
		return (0);
	if (opt->tiret)
		opt->str = ft_space_back(opt->str, opt->tiret);
	else if (opt->nbr)
		opt->str = ft_space_front(opt->str, opt->nbr);
	else if (opt->point)
		opt->str = ft_point(opt->str, opt->point);
	else if (!(opt->str = ft_0x(opt->str)))
		return (0);
	if (opt->str == NULL)
		return (0);
	return (ft_strlen(opt->str));
}
