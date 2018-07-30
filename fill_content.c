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

    tmp = info->new_flags;
    while (tmp)
    {
        if (tmp->key == 'p')
            md5_algo(info, "");
        tmp = tmp->next;
    }
}

void    new_print(t_info *info, t_flags *tmp)
{
    int     block;

    info->flags = 0;
    block = 0;
    while (tmp)
    {
        info->flags = (tmp->key == 'r') ? (info->flags | 1) : (info->flags);
        info->flags = (tmp->key == 'q') ? (info->flags | 2) : (info->flags);
        if (tmp->key == 'p')
        {
            if (block == 0)
            {
                read_screen(info, 1);
                block = 1;
            }
            else
                md5_algo(info, tmp->content);
        }
        else if (tmp->key == 's')
            md5_algo(info, tmp->content);
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
        new_print(info, info->new_flags);
    }
    else
    {
        if (info->flags == 4)
            read_screen(info, 1);
        else if ((info->flags & 4) == 4) {
            read_screen(info, 1); //active read stdin
            print(info);
        }
        else
        {
            info->flags = 2;
            read_screen(info, 0);
        }
    }
}
