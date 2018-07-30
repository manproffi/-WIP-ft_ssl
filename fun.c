/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:16:43 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/15 17:16:44 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

//F(X,Y,Z) = (X AND Y ) OR (NOT X AND Z)
//G(X,Y,Z) = (X AND Z ) OR (Y AND NOT Z)
//H(X,Y,Z) = X XOR Y XOR Z
//I(X,Y,Z) = Y XOR (X OR NOT Z)

unsigned int    fun_f(unsigned int x, unsigned int y, unsigned int z)
{
    return ((x & y) | ((~x) & z));
}

unsigned int    fun_g(unsigned int x, unsigned int y, unsigned int z)
{
    return ((x & z) | (y & ~z));
}

unsigned int    fun_h(unsigned int x, unsigned int y, unsigned int z)
{
    return (x ^ y ^ z);
}

unsigned int    fun_i(unsigned int x, unsigned int y, unsigned int z)
{
    return (y ^ (x | ~z));
}