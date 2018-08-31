/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_512.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:10:05 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 21:30:40 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define ULLI unsigned long long int

ULLI	rotr_64(ULLI x, int n)
{
	return (x >> n) | (x << (64 - n));
}

ULLI	shr_64(ULLI x, int n)
{
	return (x >> n);
}

ULLI	ch_64(ULLI x, ULLI y, ULLI z)
{
	return (x & y) ^ ((~x) & z);
}

ULLI	maj_64(ULLI x, ULLI y, ULLI z)
{
	return (x & y) ^ (x & z) ^ (y & z);
}
