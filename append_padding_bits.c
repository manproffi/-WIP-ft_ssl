/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_padding_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:48:34 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/15 13:21:38 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"



void    allocate_memory(t_info *info)
{
    size_t i;
//    size_t j;

    info->mass = (unsigned int**)malloc(sizeof(unsigned int*) * info->n);
    i = 0;
    while (i < info->n)
    {
        info->mass[i] = (unsigned int*)malloc(sizeof(unsigned int) * 16);
//        info->mass[i] = ft_memalloc(sizeof(unsigned int) * 16);
//        j = 0;
//        while (j < 16)
//            info->mass[i][j++] = 0;
        ++i;
    }
}

void    fill_mass(t_info *info, const char *string)
{
    int     i;
    int     j;
    int     k;
    char    *tmp;
    unsigned long long len;

//    printf("%p", info->mass);
//    if (info->mass != NULL)
//        delete_mass(info);
//    if (info->mass == NULL)
        allocate_memory(info);
   // info->mass = (unsigned int**)malloc(sizeof(unsigned int*) * info->n);
//    system("leaks ft_ssl -q");
    i = -1;
    j = -1;

    while (++j < (int)info->n)
    {
//        info->mass[j] = (unsigned int*)malloc(sizeof(unsigned int) * 16);
        tmp = (char*)info->mass[j];
        ft_bzero(tmp, 16 * 4);
        k = -1;
        while (++k < 64 && ++i < (int)ft_strlen(string))
        {
            tmp[k] = string[i];
        }
        if (i == (int)ft_strlen(string))
            tmp[k] = (char)128;
    }
    len = ft_strlen(string) * 8;
    info->mass[info->n - 1][15] = (len >> 32);
    info->mass[info->n - 1][14] = len & 4294967295;


}

void    append_padding_bits(t_info *info, const char *string)
{

    info->n = (ft_strlen(string) * 8) / 512;

    if ((info->n + 1) * 512 - 64 > ft_strlen(string) * 8)
        info->n += 1;
    else
        info->n += 2;

    fill_mass(info, string);
//    system("leaks ft_ssl -q");
}


