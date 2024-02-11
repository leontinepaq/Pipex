/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:38 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/12/12 01:50:43 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff_list	*create_buff_lst(void)
{
	t_buff_list	*new_buff_lst;

	new_buff_lst = malloc(sizeof(t_buff_list));
	if (!new_buff_lst)
		return (NULL);
	new_buff_lst->next = NULL;
	new_buff_lst->text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_buff_lst->text)
		return (free(new_buff_lst), NULL);
	new_buff_lst->text[0] = '\0';
	return (new_buff_lst);
}

t_fd_list	*create_fd_lst(t_fd_list **fds_lst, int fd)
{
	t_fd_list	*new_fd_lst;
	t_fd_list	*current_fd_lst;

	new_fd_lst = malloc(sizeof(t_fd_list));
	if (!new_fd_lst)
		return (NULL);
	if (!(*fds_lst))
		*fds_lst = new_fd_lst;
	else
	{
		current_fd_lst = *fds_lst;
		while (current_fd_lst->next)
			current_fd_lst = current_fd_lst->next;
		current_fd_lst->next = new_fd_lst;
	}
	new_fd_lst->fd = fd;
	new_fd_lst->next = NULL;
	new_fd_lst->begin_buff = create_buff_lst();
	if (new_fd_lst->begin_buff == NULL)
		return (free(new_fd_lst), NULL);
	return (new_fd_lst);
}

int	is_ended(char *str)
{
	int	i;

	if (str == NULL)
		return (FALSE);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	clean_buff(t_fd_list *fd_lst)
{
	t_buff_list	*buff_lst;
	t_buff_list	*next_buff_lst;
	int			end;
	int			i;

	buff_lst = fd_lst->begin_buff;
	while (buff_lst->next)
	{
		free(buff_lst->text);
		next_buff_lst = buff_lst->next;
		buff_lst->next = NULL;
		free(buff_lst);
		buff_lst = next_buff_lst;
	}
	end = 0;
	while (buff_lst->text[end] && (!end || buff_lst->text[end - 1] != '\n'))
		end++;
	i = 0;
	while (buff_lst->text[i + end])
	{
		buff_lst->text[i] = buff_lst->text[end + i];
		i++;
	}
	buff_lst->text[i] = '\0';
	fd_lst->begin_buff = buff_lst;
}

void	clean_fd(t_fd_list **begin_fds_lst, t_fd_list *current_fd_lst)
{
	t_fd_list	*fd_lst;

	fd_lst = *begin_fds_lst;
	if (fd_lst == current_fd_lst)
		*begin_fds_lst = current_fd_lst->next;
	else
	{
		while (fd_lst->next)
		{
			if (fd_lst->next == current_fd_lst)
			{
				fd_lst->next = current_fd_lst->next;
				break ;
			}
			fd_lst = fd_lst->next;
		}
	}
	free(current_fd_lst->begin_buff->text);
	free(current_fd_lst->begin_buff);
	current_fd_lst->begin_buff = 0;
	current_fd_lst->fd = 0;
	current_fd_lst->next = 0;
	free(current_fd_lst);
}
