/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:35 by josmanov          #+#    #+#             */
/*   Updated: 2024/09/26 09:54:41 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}						t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
int		is_newline(t_list *list);
void	append(t_list **list, char *buf);
void	clean_list(t_list **list);
int		len_to_newline(t_list *list);
void	str_cpy(t_list *list, char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_dealloc(t_list **list, t_list *clean_node);

#endif
