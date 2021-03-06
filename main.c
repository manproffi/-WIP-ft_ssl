/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:36:37 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 21:16:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	initialization_info(t_info *info)
{
	info->flags = 0;
	info->argc_count = 1;
	info->mass = NULL;
	info->new_flags = NULL;
	info->keys = 0;
	info->n = 0;
	info->validation_flag = 1;
}

int		main(int argc, char const *argv[])
{
	t_info	info;

	initialization_info(&info);
	if (argc == 1)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if (ft_strcmp(argv[1], "md5") == 0 || strcmp(argv[1], "sha256") == 0
			|| ft_strcmp(argv[1], "sha512") == 0)
	{
		info.algo_name = ft_strdup(argv[1]);
		pre_parsing_flags(argc, argv, &info);
		fill_content(argc, argv, &info);
	}
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", argv[1]);
		ft_printf("Message Digest commands:\nmd5\nsha256\nsha512\n");
	}
	return (0);
}
