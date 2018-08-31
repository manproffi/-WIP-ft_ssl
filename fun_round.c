/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_round.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:26:53 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 20:25:05 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

UINT	rol(UINT a, UINT offset)
{
	return (a << offset | a >> (32 - offset));
}

UINT	fun_r1(UINT arr[], UINT x, UINT s, UINT k)
{
	return (arr[1] + (rol(arr[0] + fun_f(arr[1], arr[2], arr[3]) + x + k, s)));
}

UINT	fun_r2(UINT arr[], UINT x, UINT s, UINT k)
{
	return (arr[1] + (rol(arr[0] + fun_g(arr[1], arr[2], arr[3]) + x + k, s)));
}

UINT	fun_r3(UINT arr[], UINT x, UINT s, UINT k)
{
	return (arr[1] + (rol(arr[0] + fun_h(arr[1], arr[2], arr[3]) + x + k, s)));
}

UINT	fun_r4(UINT arr[], UINT x, UINT s, UINT k)
{
	return (arr[1] + (rol(arr[0] + fun_i(arr[1], arr[2], arr[3]) + x + k, s)));
}
