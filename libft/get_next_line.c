/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:34 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/12/12 01:50:50 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd_list	*find_fd_lst(t_fd_list *lst, int fd)
{
	while (lst && lst->fd != fd && lst->next)
		lst = lst->next;
	if (!lst || lst->fd != fd)
		return (NULL);
	return (lst);
}

int	read_file(t_fd_list *current_fd_lst)
{
	t_buff_list	*current_buff;
	int			bytes_read;

	if (!current_fd_lst)
		return (-1);
	current_buff = current_fd_lst->begin_buff;
	while (current_buff->next)
		current_buff = current_buff->next;
	if (is_ended(current_buff->text) == TRUE)
		return (1);
	if (current_buff->text[0] != '\0')
	{
		current_buff->next = create_buff_lst();
		current_buff = current_buff->next;
		if (!current_buff)
			return (0);
	}
	bytes_read = read(current_fd_lst->fd, current_buff->text, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (0);
	current_buff->text[bytes_read] = '\0';
	if (read_file(current_fd_lst) == -1)
		return (-1);
	return (1);
}

int	find_len_line(t_buff_list *buff_list)
{
	int	len;
	int	i;

	len = 0;
	if (!buff_list || !buff_list->text)
		return (0);
	while (buff_list->next)
	{
		i = 0;
		while (buff_list->text[i])
			i++;
		len += i;
		buff_list = buff_list->next;
	}
	i = 0;
	while (buff_list->text[i] && (i == 0 || buff_list->text[i - 1] != '\n'))
		i++;
	len += i;
	return (len);
}

char	*join_buffers(t_fd_list *fd_lst)
{
	char		*line;
	t_buff_list	*buff_lst;
	int			i;
	int			j;

	buff_lst = fd_lst->begin_buff;
	line = malloc((find_len_line(buff_lst) + 1) * sizeof(char));
	line[0] = '\0';
	i = 0;
	while (buff_lst && buff_lst->text)
	{
		j = 0;
		while (buff_lst->text[j] && (j == 0 || buff_lst->text[j - 1] != '\n'))
		{
			line[i] = buff_lst->text[j];
			i++;
			j++;
		}
		buff_lst = buff_lst->next;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fds_lst;
	t_fd_list			*current_fd_lst;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	current_fd_lst = find_fd_lst(fds_lst, fd);
	if (!current_fd_lst)
	{
		current_fd_lst = create_fd_lst(&fds_lst, fd);
		if (!current_fd_lst)
			return (NULL);
	}
	if (read_file(current_fd_lst) > 0 || current_fd_lst->begin_buff->text[0])
	{
		line = join_buffers(current_fd_lst);
		return (clean_buff(current_fd_lst), line);
	}
	clean_fd(&fds_lst, current_fd_lst);
	return (NULL);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;
	char	*line;
	
	fd = open("test.txt",O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("\nRETOUR %d : |%s|\n",i , line);
		printf("-------------------------------------\n\n");
		i++;
		free(line);
	}
	close(fd);
	return (0);
}*/
