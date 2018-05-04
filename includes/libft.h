/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:49:51 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/05/04 17:31:54 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_sscanf.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <string.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(int i);
double				ft_atod(const char *s);
int					ft_atoi(const char *s);
long				ft_atol(const char *s);
int					ft_atonum(const char *s, unsigned int *nb);
void				ft_bzero(void *s, size_t n);
size_t				ft_count_words(const char *s, char c);
char				*ft_i128toa(__int128 nb, unsigned int base, char *map);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
int					ft_pgcd(int n1, int n2);
int					ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putint128(__int128 n);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_putstr(const char *s);
void				ft_putstrlen(const char *s, int len);
size_t				ft_putstr_fd(const char *s, int fd);
char				*ft_readfile(const char *filepath, size_t *usize);
size_t				ft_size_bin(long long n);
void				ft_swap(void *a, void *b);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wcslen(const wchar_t *c);

/*
** Lists
*/

void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstinsert(t_list **last, t_list *item);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnewlink(void *content, size_t content_size);
void				ft_lstpushsort(t_list **lst, t_list *item,
						int (*cmp)(t_list *, t_list *));
t_list				*ft_lst_pushback(t_list **lst, t_list *item);
void				ft_lstsuppress(void *content, size_t size);

/*
** Memory
*/

void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);

/*
** Strings
*/

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strchrpos(const char *s, int c);
void				ft_strcleanc(char **str, char c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
char				*ft_strdup_len(const char *str, char c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strisdigit(const char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strplen(const char *str, const char *max);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strsub_len(char const *s, char c);
char				*ft_strtrim(char const *s);

#endif
