/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_256.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:10:05 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/06 20:10:07 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

//Ch(x, y, z) = (x AND y) XOR ( NOT x AND z)
//Maj(x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)
//
//Sigma0(x) = ROTR(x, 2) XOR ROTR(x, 13) XOR ROTR(x, 22)
//Sigma1(x) = ROTR(x, 6) XOR ROTR(x, 11) XOR ROTR(x, 25)
//
//Delta0(x) = ROTR(x, 7) XOR ROTR(x, 18) XOR SHR(x, 3)
//Delta1(x) = ROTR(x, 17) XOR ROTR(x, 19) XOR SHR(x, 10)
//
//Операции над словами (32-битными).
//ROTR - циклический сдвиг вправо на n бит:
//ROTR(x, n) = (x » n) | (x « (32-n))
//SHR - сдвиг вправо на n бит:
//SHR(x, n) = x » n

unsigned int    rotr(unsigned int x, int n)
{
    return (x >> n) | (x << (32 - n));
}

unsigned int    shr(unsigned int x, int n)
{
    return (x >> n);
}

unsigned int    ch(unsigned int x, unsigned int y, unsigned int z)
{
	return (x & y) ^ ((~x) & z);
}

unsigned int    maj(unsigned int x, unsigned int y, unsigned int z)
{
	return (x & y) ^ (x & z) ^ (y & z);
}

unsigned int    sigma0(unsigned int x)
{
	return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

unsigned int    sigma1(unsigned int x)
{
	return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

unsigned int    delta0(unsigned int x)
{
	return rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3);
}

unsigned int    delta1(unsigned int x)
{
	return rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10);
}

