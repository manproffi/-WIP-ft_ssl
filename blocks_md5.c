/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:56:46 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:13:24 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

int		p1(UINT arr[], UINT a, UINT b, UINT c)
{
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	return (1);
}

int		p2(UINT arr[], UINT d)
{
	arr[3] = d;
	return (1);
}
