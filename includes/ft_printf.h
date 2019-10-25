/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:21:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 14:55:10 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_op
{
	char		*str;
	int			type;
	int			tiret;
	int			zero;
	int			point;
	int			wildcard_point;
	int			wildcard_tiret;
	int			wildcard_nbr;
	int			nbr;
}				t_opt;

int				ft_printf(const char *str, ...);
int				ft_atoi_printf(char *s, int *i);
int				fct_p(va_list *ap, t_list *lst);
int				fct_c(va_list *ap, t_list *lst);
int				fct_s(va_list *ap, t_list *lst);
int				fct_id(va_list *ap, t_list *lst);
int				fct_u(va_list *ap, t_list *lst);
int				fct_x(va_list *ap, t_list *lst);
int				match_type(char c);
void			init_ptrf(int (**f)(va_list *ap, t_list *lst));
void			check_wildcard(va_list *ap, t_list **lst);
t_list			*init_lst(char *str);

#endif
