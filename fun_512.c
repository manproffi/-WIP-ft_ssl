/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_512.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:10:05 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/06 20:10:07 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define ULLI unsigned long long int

// Ch(x, y, z) = (x AND y) XOR ( NOT x AND z)
// Maj(x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)

// Sigma0(x) = ROTR(x, 28) XOR ROTR(x, 34) XOR ROTR(x, 39)
// Sigma1(x) = ROTR(x, 14) XOR ROTR(x, 18) XOR ROTR(x, 41)

// Delta0(x) = ROTR(x, 1) XOR ROTR(x, 8) XOR SHR(x, 7)
// Delta1(x) = ROTR(x, 19) XOR ROTR(x, 61) XOR SHR(x, 6)

// Операции над словами (64-битными).
// ROTR - циклический сдвиг вправо на n бит:
// ROTR(x, n) = (x » n) | (x « (64-n))
// SHR - сдвиг вправо на n бит:
// SHR(x, n) = x » n

ULLI    rotr_64(ULLI x, int n)
{
    return (x >> n) | (x << (64 - n));
}

ULLI    shr_64(ULLI x, int n)
{
    return (x >> n);
}

ULLI    ch_64(ULLI x, ULLI y, ULLI z)
{
	return (x & y) ^ ((~x) & z);
}

ULLI    maj_64(ULLI x, ULLI y, ULLI z)
{
	return (x & y) ^ (x & z) ^ (y & z);
}

ULLI    sigma0_64(ULLI x)
{
	return rotr_64(x, 28) ^ rotr_64(x, 34) ^ rotr_64(x, 39);
}

ULLI   sigma1_64(ULLI x)
{
	return rotr_64(x, 14) ^ rotr_64(x, 18) ^ rotr_64(x, 41);
}

ULLI    delta0_64(ULLI x)
{
	return rotr_64(x, 1) ^ rotr_64(x, 8) ^ shr_64(x, 7);
}

ULLI    delta1_64(ULLI x)
{
	return rotr_64(x, 19) ^ rotr_64(x, 61) ^ shr_64(x, 6);
}

