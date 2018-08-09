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
    info->mass = NULL;

    info->new_flags = NULL;
    info->keys = 0;
    info->n = 0;
    info->validation_flag = 1;

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
	else if (ft_strcmp(argv[1], "md5") == 0 || strcmp(argv[1], "sha256") == 0
        || ft_strcmp(argv[1], "sha512") == 0)
    {
        info.algo_name = ft_strdup(argv[1]);
        pre_parsing_flags(argc, argv, &info);
        fill_content(argc, argv, &info);
    }
    else
    {
        printf("ft_ssl: Error: '%s' is an invalid command.\n", argv[1]);
        printf("Message Digest commands:\nmd5\nsha256\n");
    }
    // system("leaks ft_ssl -q");
    // printf("%f\n", fmod(4.99999990, 2));
    // printf("%d\n", (int)fmod(4.99999990, 2));
    // unsigned char a = 250;
    // unsigned char b = 125;
    // unsigned char c = a + b;
    // printf("%d\n", c);
    // printf("%f\n", fmod(375,256));
    		
	return 0;
}
