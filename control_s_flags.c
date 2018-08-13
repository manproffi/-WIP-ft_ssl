/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_s_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:10:33 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:54:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	lstaddend(t_flags **alst, t_flags *new)
{
	t_flags	*list;

	if (*alst == NULL)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

t_flags	*lstnew(const char *content, size_t content_size, char c)
{
	t_flags		*list;

	list = (t_flags*)malloc(sizeof(t_flags));
	if (!list)
		return (NULL);
	if (content)
	{
		list->key = c;
		list->content = ft_strdup(content);
		if (!list->content)
			return (NULL);
		list->content_size = content_size;
		ft_memcpy(list->content, content, content_size);
	}
	else
	{
		list->key = 0;
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}

void	del_list_list(t_flags **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_strdel(&(*list)->content);
		free(*list);
	}
}
