/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block4_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:57:08 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 20:57:10 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

static inline void	block4_md5_2(t_info *info, t_h *h, int i, UINT arr[])
{
	h->h0 = fun_r4(arr, info->mass[i][8], 6, info->t[57]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r4(arr, info->mass[i][15], 10, info->t[58]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r4(arr, info->mass[i][6], 15, info->t[59]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r4(arr, info->mass[i][13], 21, info->t[60]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r4(arr, info->mass[i][4], 6, info->t[61]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r4(arr, info->mass[i][11], 10, info->t[62]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r4(arr, info->mass[i][2], 15, info->t[63]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r4(arr, info->mass[i][9], 21, info->t[64]);
}

void				block4_md5(t_info *info, t_h *h, int i)
{
	unsigned int arr[4];

	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r4(arr, info->mass[i][0], 6, info->t[49]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r4(arr, info->mass[i][7], 10, info->t[50]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r4(arr, info->mass[i][14], 15, info->t[51]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r4(arr, info->mass[i][5], 21, info->t[52]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r4(arr, info->mass[i][12], 6, info->t[53]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r4(arr, info->mass[i][3], 10, info->t[54]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r4(arr, info->mass[i][10], 15, info->t[55]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r4(arr, info->mass[i][1], 21, info->t[56]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	block4_md5_2(info, h, i, arr);
}
