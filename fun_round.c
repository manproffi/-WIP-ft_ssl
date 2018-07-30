/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_round.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:26:53 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/16 20:26:54 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

unsigned int rol(unsigned int a, unsigned int offset)
{
    return a << offset | a >> (32 - offset);
}


void    fun_r1(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info)
{
//    printf("a %u b %u c %u d %u x %u s %u i %u info %u", a, b, c, d, x, s, i, info->t[i]);
    *a = b + (rol(*a + fun_f(b,c,d) + x + info->t[i], s));
//    printf("aaaa *** %u\n",a);
//    sleep(23);
//    a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s)
//    a = b + ((a + F(b,c,d) + X + T[i]) <<< s)
}

void    fun_r2(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info)
{
    *a = b + (rol(*a + fun_g(b,c,d) + x + info->t[i], s));
}

void    fun_r3(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info)
{
    *a = b + (rol(*a + fun_h(b,c,d) + x + info->t[i], s));
}

void    fun_r4(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info)
{
    *a = b + (rol(*a + fun_i(b,c,d) + x + info->t[i], s));
}
