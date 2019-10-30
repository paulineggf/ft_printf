/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:58:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/30 16:31:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*space_back(char *s, int nb)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = malloc(sizeof(char) * (ft_strlen(s) + 1 + nb))))
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	while (i < nb)
		s2[i++] = ' ';
	s2[i] = 0;
	return (s2);
}

static char	*c_front(char *s, int nb, char c)
{
	char	*s2;
	int		i;
	int		j;

	if (*s == '0' && nb == -1)
	{
		s2 = ft_strdup("");
		return (s2);
	}
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
		s2[i++] = c;
	j = 0;
	while (s[j])
		s2[i++] = s[j++];
	s2[i] = 0;
	return (s2);
}

static char		*space_zero_front(char *s, int zero, int tiret, int point)
{
	int		i;
	int		len;
	int		len_s;
	char	*s2;

	i = 0;
	if (*s == '0' && point == -1 && zero)
	{
		if (!(s2 = malloc(sizeof(char) * (zero + 1))))
			return (0);
		s2 = ft_memset(s2, ' ', zero);
		s2[zero] = 0;
		return (s2);
	}
	if (*s == '0' && point == -1 && tiret)
	{
		if (!(s2 = malloc(sizeof(char) * (tiret + 1))))
			return (0);
		s2 = ft_memset(s2, ' ', tiret);
		s2[tiret] = 0;
		return (s2);
	}
	len = 0;
	len_s = ft_strlen(s);
	if (!zero && tiret && point <= len_s)
		return (space_back(s, tiret));
	if (point >= zero && point >= len_s)
		len = point;
	else if (zero >= point && zero >= len_s)
		len = zero;
	else
		len = len_s;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (point < len_s)
		point = len_s;
	if (len != len_s)
	{
		while (i < (zero - point))
			s2[i++] = ' ';
		while (point-- > len_s)
			s2[i++] = '0';
	}
	ft_strcpy(s2 + i, s);
	return (s2);
}

int			fct_x(va_list *ap, t_opt *opt)
{
	unsigned int	nb;
	int				i;

	i = 0;
	check_wildcard(ap, opt);
	nb = va_arg(*ap, unsigned int);
	if (!(opt->str = convert_hex((unsigned long)nb, "0123456789abcdef", 16)))
		return (0);
	if (opt->zero && opt->point)
		opt->str = space_zero_front(opt->str, opt->zero, 0, opt->point);
	if (opt->tiret && opt->point)
		opt->str = space_zero_front(opt->str, 0, opt->tiret, opt->point);
	else if (opt->tiret)
		opt->str = space_back(opt->str, opt->tiret);
	else if (opt->nbr)
		opt->str = c_front(opt->str, opt->nbr, ' ');
	else if (opt->zero)
		opt->str = c_front(opt->str, opt->zero, '0');
	else if (opt->point)
		opt->str = c_front(opt->str, opt->point, '0');
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	return (ft_strlen(opt->str));
}
