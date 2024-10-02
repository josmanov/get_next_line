/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:28 by josmanov          #+#    #+#             */
/*   Updated: 2024/10/02 12:57:13 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	if (!list || !*list)
		return ;
	last_node = ft_lstlast(*list);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return ;
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
	{
		free(buffer);
		return ;
	}
	i = len_to_newline(last_node);
	j = 0;
	while ((last_node->str_buf[i]))
		buffer[j++] = last_node->str_buf[i++];
	buffer[j] = '\0';
	clean_node->str_buf = buffer;
	ft_dealloc(list, clean_node);
}

// Ends buffered line 
void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		free(buf);
		return ;
	}
	new_node->str_buf = buf;
	if (new_node->str_buf == NULL)
	{
		free(new_node);
		return ;
	}
	new_node->next = NULL;
	last_node = ft_lstlast(*list);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

// Creates a new list
void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!is_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append(list, buffer);
	}
}

// Fetches a new line from a linked list
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	int				str_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	if (str_len <= 0)
		return (NULL);
	next_line = malloc(str_len + 1);
	if (next_line == NULL)
		return (NULL);
	str_cpy(list, next_line);
	clean_list(&list);
	return (next_line);
}
