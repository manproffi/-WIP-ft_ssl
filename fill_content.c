/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:32:44 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:55:42 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	fill_key(t_info *info)
{
	t_flags *tmp;

	tmp = info->new_flags;
	while (tmp)
	{
		if (tmp->key == 'r')
			info->flags = (info->flags | 1);
		else if (tmp->key == 'q')
			info->flags = (info->flags | 2);
		else if (tmp->key == 'p')
			info->flags = (info->flags | 4);
		else if (tmp->key == 's')
			info->flags = (info->flags | 8);
		else if (tmp->key == 'f')
			info->flags = (info->flags | 16);
		else
			printf("Error::fill_content\n");
		tmp = tmp->next;
	}
}

void	print(t_info *info)
{
	t_flags	*tmp;
	int		flag;

	flag = info->flags;
	tmp = info->new_flags;
	while (tmp)
	{
		if (tmp->key == 'p')
		{
			read_screen(info, 1);
			info->flags = (info->flags | 2);
		}
		tmp = tmp->next;
	}
	if ((info->flags & 1) == 1 || (flag & 2) == 2)
	{
		read_screen(info, 0);
	}
}

void	part_s_flags(t_info *info, int *s_tmp, int *flag_s, t_flags *tmp)
{
	info->flags = (info->flags | 64);
	*s_tmp = info->flags;
	info->flags = *flag_s;
	choice_alg_fun(info, tmp->content, "");
	info->flags = *s_tmp;
}

void	print_without_stdin(t_info *info)
{
	t_flags	*tmp;
	int		s_tmp;
	int		flag_s;

	flag_s = 0;
	tmp = info->new_flags;
	while (tmp)
	{
		flag_s = tmp->key == 'r' ? (flag_s | 1) : flag_s;
		flag_s = tmp->key == 'q' ? (flag_s | 2) : flag_s;
		if (tmp->key == 'p')
			read_screen(info, 1);
		else if (tmp->key == 's')
		{
			part_s_flags(info, &s_tmp, &flag_s, tmp);
		}
		else if (tmp->key == 'f')
		{
			info->flags = (info->flags | 32);
			info->validation_flag = 0;
			read_file(info, tmp->content);
		}
		tmp = tmp->next;
	}
}

void	fill_content(int argc, const char *argv[], t_info *info)
{
	(void)argv;
	(void)argc;
	fill_key(info);
	if ((info->flags & 8) == 8 || (info->flags & 16) == 16)
	{
		print_without_stdin(info);
	}
	else
	{
		if (info->flags < 4)
		{
			info->flags = (info->flags | 2);
			read_screen(info, 0);
		}
		else
			print(info);
	}
}
