/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:51:44 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/01/19 11:14:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* get_next_line structures */
typedef struct s_buff_list
{
	char				*text;
	struct s_buff_list	*next;
}					t_buff_list;

typedef struct s_fd_list
{
	int					fd;
	struct s_buff_list	*begin_buff;
	struct s_fd_list	*next;
}					t_fd_list;

/* libc functions */
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *d, const void *s, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *d, const char *s, size_t dstsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

/* additional functions */
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/* bonus functions */
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* printf functions */
int			ft_put_str(char *str);
int			ft_put_nbr(int nb);
int			ft_put_nbr_uns(unsigned int nb);
int			ft_put_nbr_base(int nbr, char *base);
int			ft_put_ptradd(void *ptr);
int			ft_printf(const char *str, ...);
//void ft_putnbr_dbl_fd(double d, int fd);

/* get_next_line functions */
char		*get_next_line(int fd);
t_fd_list	*find_fd_lst(t_fd_list *lst, int fd);
int			read_file(t_fd_list *current_fd_lst);
int			find_len_line(t_buff_list *buff_list);
char		*join_buffers(t_fd_list *fd_lst);
t_buff_list	*create_buff_lst(void);
t_fd_list	*create_fd_lst(t_fd_list **fds_lst, int fd);
int			is_ended(char *str);
void		clean_buff(t_fd_list *fd_lst);
void		clean_fd(t_fd_list **begin_fds_lst, t_fd_list *current_fd_lst);

#endif
