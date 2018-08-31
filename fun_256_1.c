/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_256_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 21:26:43 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 21:28:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

unsigned int	sigma0(unsigned int x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

unsigned int	sigma1(unsigned int x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

unsigned int	delta0(unsigned int x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3));
}

unsigned int	delta1(unsigned int x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10));
}
