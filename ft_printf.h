/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:21:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 20:30:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*typedef enum	e_type
{
	p,
	c,
	s,
	d,
	i,
	u,
	x,
	X,
}				t_type;*/

typedef struct	s_op
{
	char		*str;
	int			type;
	int			tiret;
	int			zero;
	int			point;
	int			wildcard;
	int			nbr;
	struct s_op *next;
}				t_opt;

int				ft_printf(const char *str, ...);
int				ft_charset(char c, char const *set);
int				ft_strnlen(const char *s, char c);
int				ft_natoi(const char *s, int *i);
int				ft_atoi(const char *s, int *i);
char			*stock_type(char c, char *type);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
void			ft_lstadd_front(t_opt **alst, t_opt *new);
void			ft_lstadd_back(t_opt **alst, t_opt *new);
void			init_ptrf(int (**f)(va_list *, t_opt *));
void			ft_putstr(char const *s);
t_opt			*ft_lstlast(t_opt *lst);
t_opt			*nb_string(const char *str);
t_opt			*init_lst(const char *str);
int				fct_p(va_list *ap, t_opt *opt);
int				fct_c(va_list *ap, t_opt *opt);
int				fct_s(va_list *ap, t_opt *opt);
int				fct_id(va_list *ap, t_opt *opt);
int				fct_u(va_list *ap, t_opt *opt);
int				fct_x(va_list *ap, t_opt *opt);
int				find_enum(char c);

#endif
