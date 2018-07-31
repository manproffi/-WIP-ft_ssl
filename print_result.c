/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:00:02 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/24 20:00:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"


void    print_result(t_info * info, const char *str, const char *filename)
{
    int flag;

    flag = info->flags;
    if (ft_strcmp(str, "") == 0)
        info->flags  = info->flags | 2;
    if ((info->flags & 4) == 4)
    {
        printf("%.8x%.8x%.8x%.8x\n", rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d));
        info->flags &= ~4;
    }
    else if ((info->flags & 2) == 2)
    {
        printf("%.8x%.8x%.8x%.8x\n", rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d));
        info->flags &= ~8;
    }
    else if ((info->flags & 1) == 1)
    {
        if ((info->flags & 32) == 32)
        {
            printf("%.8x%.8x%.8x%.8x %s\n", rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d), filename);
            info->flags = info->flags & ~32;
        }
        else
            printf("%.8x%.8x%.8x%.8x \"%s\"\n", rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d), str);
    }
    else
    {
        if ((info->flags & 32) == 32)
        {
            printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", filename, rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d));
            info->flags = info->flags | ~32;
        }
        else
            printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", str, rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d));
    }
    if (ft_strcmp(str, "") == 0 && (flag & 2) == 0)
        info->flags  &= ~2;;













//    printf("%.8x%.8x%.8x%.8x\n", rev_bit(info->a), rev_bit(info->b), rev_bit(info->c), rev_bit(info->d));
}
