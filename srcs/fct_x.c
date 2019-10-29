/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:58:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/29 14:58:49 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_strrev_space_back(char *s, int nb)
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

static char	*ft_strrev_c_front(char *s, int nb, char c)
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
		s2[i++] = c;
	j = 0;
	while (s[j])
		s2[i++] = s[j++];
	s2[i] = 0;
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
	if (opt->tiret)
		opt->str = ft_strrev_space_back(opt->str, opt->tiret);
	else if (opt->nbr)
		opt->str = ft_strrev_c_front(opt->str, opt->nbr, ' ');
	else if (opt->zero)
		opt->str = ft_strrev_c_front(opt->str, opt->zero, '0');
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	return (ft_strlen(opt->str));
}
