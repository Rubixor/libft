/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:36:16 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/28 21:25:17 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct			s_flag
{
	int					plus;
	int					minus;
	int					hash;
	int					zero;
	int					space;
}						t_flag;

typedef struct			s_variable
{
	t_flag				flag;
	int					len;
	int					len_star;
	int					prec;
	int					prec_star;
	char				*modif;
	char				type;
	char				*arg;
	int					arg_len;
	struct s_variable	*next;
}						t_variable;

int						ft_printf(const char *format, ...);

int						ft_printf_fd(int fd, const char *format, ...);

int						pf_char(t_variable *v, va_list args, int fd);

int						pf_check_flags(char *str, t_variable *var);

int						pf_check_len(char *str, t_variable *var);

void					pf_collect_len(t_variable *v, va_list args);

int						pf_check_modif(char *str, t_variable *var);

int						pf_check_prec(char *str, t_variable *var);

void					pf_collect_prec(t_variable *v, va_list args);

int						pf_display(const char *s, t_variable *v,
		va_list args, int fd);

int						pf_int(t_variable *var, va_list args, int fd);

int						pf_int_init(t_variable *v, __int128 n, int b, char *m);

int						pf_int_nminus(t_variable *v, __int128 n, int i, int fd);

int						pf_int_minus(t_variable *v, __int128 n, int i, int fd);

int						pf_intmaxt(t_variable *v, va_list args, int fd);

int						pf_long(t_variable *v, va_list args, int fd);

int						pf_longlong(t_variable *v, va_list args, int fd);

t_variable				*pf_newvar(void);

int						pf_schar(t_variable *v, va_list args, int fd);

int						pf_short(t_variable *v, va_list args, int fd);

int						pf_sizet(t_variable *v, va_list args, int fd);

int						pf_string(t_variable *var, va_list args, int fd);

int						pf_treat(t_variable *var, va_list args, int fd);

int						pf_uchar(t_variable *v, va_list args, int fd);

int						pf_uint(t_variable *v, va_list args, int fd);

int						pf_uint32(t_variable *v, va_list args, int fd);

int						pf_uint64(t_variable *v, va_list args, int fd);

int						pf_uintmaxt(t_variable *v, va_list args, int fd);

int						pf_ulong(t_variable *v, va_list args, int fd);

int						pf_ulonglong(t_variable *v, va_list args, int fd);

int						pf_ushort(t_variable *v, va_list args, int fd);

t_variable				*pf_var_pushback(t_variable **var, t_variable *item);

int						pf_wchar_t(t_variable *v, va_list args, int fd);

int						pf_wint_t(t_variable *v, va_list args, int fd);

#endif
