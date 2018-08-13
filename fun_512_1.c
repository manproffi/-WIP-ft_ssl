/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_512_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 21:29:56 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 21:29:57 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define ULLI unsigned long long int

ULLI	sigma0_64(ULLI x)
{
	return (rotr_64(x, 28) ^ rotr_64(x, 34) ^ rotr_64(x, 39));
}

ULLI	sigma1_64(ULLI x)
{
	return (rotr_64(x, 14) ^ rotr_64(x, 18) ^ rotr_64(x, 41));
}

ULLI	delta0_64(ULLI x)
{
	return (rotr_64(x, 1) ^ rotr_64(x, 8) ^ shr_64(x, 7));
}

ULLI	delta1_64(ULLI x)
{
	return (rotr_64(x, 19) ^ rotr_64(x, 61) ^ shr_64(x, 6));
}
