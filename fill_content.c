/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:32:44 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/29 17:32:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"


void    fill_key(t_info *info)
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
            printf("pzdc::fill_content\n\n\n");
        tmp = tmp->next;
    }
}

void    print(t_info *info)
{
    t_flags *tmp;
    int     flag;

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

void    print_without_stdin(t_info *info)
{
    t_flags  *tmp;

    tmp = info->new_flags;
    while (tmp)
    {
//        printf("***%c %s\n", tmp->key, tmp->content);
        if (tmp->key == 'p')
            read_screen(info, 1);
        else if (tmp->key == 's')
            md5_algo(info, tmp->content, "");
        else if (tmp->key == 'f')
        {
            info->flags = (info->flags | 32);
            info->validation_flag = 0;
            read_file(info, tmp->content);
//          md5_algo(info, tmp->content);
        }

        tmp = tmp->next;
    }
}

void    fill_content(int argc, const char *argv[], t_info *info)
{
    fill_key(info);

    (void)argc;
    (void)argv;


    if ((info->flags & 8) == 8 || (info->flags & 16) == 16)
    {
        // START WORK HERE
//        printf("start work HERE");
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
