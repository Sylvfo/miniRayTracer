/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:06:33 by sforster          #+#    #+#             */
/*   Updated: 2025/02/21 13:27:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
// manipulate string
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *hays, const char *needle, size_t l);
char			*ft_strrchr(const char *s, int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_isspace(int c);
// manipulate memory
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s);

// manipulate numbers
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
float			ft_atof(const char *str);
float			ft_strtod(const char *str, char **endptr);

// write to a file descriptor
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

//bonus
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *),
					void (*del)(void *));

char			*get_next_line(int fd);
int				ft_findline(char *str);
size_t			ft_strlen_gnl(char *str);
char			*ft_strndup(char *s, size_t c);
//void			*ft_bzero(void *s, int n);
//void			*ft_memset(void *b, int c, int len);
char			*ft_strjoin_gnl(char *s1, char *s2);

#endif