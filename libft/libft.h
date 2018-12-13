/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:18:22 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/22 15:49:04 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUFF_SIZE 32
# define MAX_FD 1024 + 1
# define RET_VALUE(ret) ret > 0 ? 1 : ret

int				get_next_line(int const fd, char **line);

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel (void **ap);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t len);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char	*dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t size);
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

char			**ft_2d_arrcpy(char **tab);
int				ft_2d_strlen(char **tab);
void			ft_free_2d(char	**cmd);
int				ft_strucpy(char **dest, char *src, char c);
void    		free_2d_arr(char **cmd);
#endif
