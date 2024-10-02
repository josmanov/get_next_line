/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:28 by josmanov          #+#    #+#             */
/*   Updated: 2024/09/26 09:57:23 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_dealloc(t_list **list, t_list *clean_node)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	if (clean_node && clean_node->str_buf && clean_node->str_buf[0] != '\0')
	{
		*list = clean_node;
		(*list)->next = NULL;
	}
	else
	{
		free(clean_node->str_buf);
		free(clean_node);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	str_cpy(t_list *list, char *str)
{
	int		i;
	int		j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			str[j++] = list->str_buf[i++];
			if (list->str_buf[i - 1] == '\n')
			{
				str[j] = '\0';
				return ;
			}
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_list *list)
{
	int		i;
	int		len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

int	is_newline(t_list *list)
{
	int		i;

	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}
