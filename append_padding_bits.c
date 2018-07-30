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

//char* append_to_string(t_info *info, const char *string)
//{
////    int     i;
//    char    *str;
//
//    str = (char*)malloc(sizeof(char) * (info->n * 512 - 64 + 1));
//    ft_bzero(str, info->n * 512 - 64 + 1);
//    ft_strcpy(str, string);
//    printf("%s\n", str);
//    return str;
//}


void    fill_mass(t_info *info, const char *string)
{
    size_t     i;
    size_t     j;
    int     k;
    char    *tmp;
    unsigned long long len;

    info->mass = (unsigned int**)malloc(sizeof(unsigned int*) * info->n);
    i = -1;
    j = -1;
    while (++j < info->n)
    {
        info->mass[j] = (unsigned int*)malloc(sizeof(unsigned int) * 16);
        tmp = (char*)info->mass[j];
        ft_bzero(tmp, 16 * 4);
        k = -1;
        while (++k < 64 && ++i < ft_strlen(string))
        {
            tmp[k] = string[i];
//            printf("%c ", string[i]);
        }
        if (i == ft_strlen(string))
            tmp[k] = (char)128;
    }
//    printf("\n-->>>%zu\n", ft_strlen(string));
    len = ft_strlen(string) * 8;
    info->mass[info->n - 1][15] = (len >> 32);
    info->mass[info->n - 1][14] = len & 4294967295;

}

void    print_mass(t_info * info)
{
    size_t     i = -1;

    while (++i < info->n)
    {
        printf("****Block %zu\n", i);
        size_t j = -1;
        while (++j < 16)
        {
            printf("%u\n", info->mass[i][j]);
        }
    }
}

void    append_padding_bits(t_info *info, const char *string)
{
//    int        i;
   // char *str;

    info->n = (ft_strlen(string) * 8) / 512;

    if ((info->n + 1) * 512 - 64 > ft_strlen(string) * 8)
        info->n += 1;
    else
        info->n += 2;

//    (void)info;
//    printf("%zu %zu\n", info->n, ft_strlen(string));
//    str = append_to_string(info, string);
//    printf("%s\n", str);
    fill_mass(info, string);
//    printf("\n");
//    print_mass(info);

//    UINT_LEAST64_MAX
//    printf("///%lu\n", sizeof(UINT_LEAST64_MAX));
//    printf("***%lu\n", sizeof(size_t));


}


