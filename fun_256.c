/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_256.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:10:05 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 21:23:57 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

unsigned int	rotr(unsigned int x, int n)
{
	return (x >> n) | (x << (32 - n));
}

unsigned int	shr(unsigned int x, int n)
{
	return (x >> n);
}

unsigned int	ch(unsigned int x, unsigned int y, unsigned int z)
{
	return (x & y) ^ ((~x) & z);
}

unsigned int	maj(unsigned int x, unsigned int y, unsigned int z)
{
	return (x & y) ^ (x & z) ^ (y & z);
}
