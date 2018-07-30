/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:36:37 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/12 20:36:42 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	initialization_info(t_info *info)
{
	info->flags = 0;
	info->argc_count = 1;

    info->new_flags = NULL;
    info->keys = 0;
    info->n = 0;

    info->a = 0x67452301;
    info->b = 0xEFCDAB89;
    info->c = 0x98BADCFE;
    info->d = 0x10325476;
}


int main(int argc, char const *argv[])
{
	t_info	info;

	initialization_info(&info);
	if (argc == 1)
		printf("usage: ft_ssl command [command opts] [command args]\n");
	else if (ft_strcmp(argv[1], "md5") == 0)
        start_work_with_md5(&info, argc, argv);
    else if (strcmp(argv[1], "sha256") == 0)
        start_work_with_sha256(&info, argc, argv);
    else
    {
        printf("ft_ssl: Error: '%s' is an invalid command.\n", argv[1]);
        printf("Message Digest commands:\nmd5\nsha256\n");
    }
	return 0;
}
