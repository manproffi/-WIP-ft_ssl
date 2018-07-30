/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_work_with_md5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:12:11 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/14 13:12:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void    start_work_with_md5(t_info *info, int argc, const char *argv[])
{
    (void)info;
    (void)argc;
    (void)argv;

    pre_parsing_flags(argc, argv, info);
    fill_content(argc, argv, info);

//    printf("%d\n", info->flags);

//    t_flags *tmp = info->new_flags;
//    while (tmp)
//    {
//        printf("key = %c, content = %s\n", tmp->key, tmp->content);
//        tmp = tmp->next;
//    }


//
//    else if (!info->disable_p || argc == 2)
//    {
////        info->flags = 4;
//        read_screen(info, 0);
//    }





//    parsing_flags(argc, argv, info);
//    if (argc == info->argc_count && !info->flag_active_read_screen)
//    {
//        printf("\n--->>> HERE:\n");
//        info->flags |= 4;

//        read_screen(info, 0);

//    }

//    printf("\n--->>> after parsing_flags: %d \n", info->argc_count);
//    printf("\n--->>> after parsing_flags: %d \n", argc);

//    printf("\n--->>> after parsing_flags: %d %s\n", info->argc_count , argv[info->argc_count]);

//    printf("//////\n %d %d", info->argc_count, argc);
//    while (info->argc_count < argc)
//    {
//        read_file(info, argv[info->argc_count]);
//        info->argc_count += 1;
//    }
}
