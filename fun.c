/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:16:43 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 21:21:37 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

unsigned int	fun_f(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) | ((~x) & z));
}

unsigned int	fun_g(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & z) | (y & ~z));
}

unsigned int	fun_h(unsigned int x, unsigned int y, unsigned int z)
{
	return (x ^ y ^ z);
}

unsigned int	fun_i(unsigned int x, unsigned int y, unsigned int z)
{
	return (y ^ (x | ~z));
}
