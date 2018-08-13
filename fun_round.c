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
#define UINT unsigned int

UINT	rol(UINT a, UINT offset)
{
    return (a << offset | a >> (32 - offset));
}

void	fun_r1(UINT *a, UINT b, UINT c, UINT d, UINT x, UINT s, UINT i, t_info *info)
{
    *a = b + (rol(*a + fun_f(b,c,d) + x + info->t[i], s));
}

void	fun_r2(UINT *a, UINT b, UINT c, UINT d, UINT x, UINT s, UINT i, t_info *info)
{
    *a = b + (rol(*a + fun_g(b,c,d) + x + info->t[i], s));
}

void	fun_r3(UINT *a, UINT b, UINT c, UINT d, UINT x, UINT s, UINT i, t_info *info)
{
    *a = b + (rol(*a + fun_h(b,c,d) + x + info->t[i], s));
}

void	fun_r4(UINT *a, UINT b, UINT c, UINT d, UINT x, UINT s, UINT i, t_info *info)
{
    *a = b + (rol(*a + fun_i(b,c,d) + x + info->t[i], s));
}

// start work here