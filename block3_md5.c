/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block3_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:57:01 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 20:57:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

static inline void	block3_md5_2(t_info *info, t_h *h, int i, UINT arr[])
{
	h->h3 = fun_r3(arr, info->mass[i][0], 11, info->t[42]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r3(arr, info->mass[i][3], 16, info->t[43]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r3(arr, info->mass[i][6], 23, info->t[44]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r3(arr, info->mass[i][9], 4, info->t[45]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r3(arr, info->mass[i][12], 11, info->t[46]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r3(arr, info->mass[i][15], 16, info->t[47]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r3(arr, info->mass[i][2], 23, info->t[48]);
}

void				block3_md5(t_info *info, t_h *h, int i)
{
	unsigned int arr[4];

	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r3(arr, info->mass[i][5], 4, info->t[33]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r3(arr, info->mass[i][8], 11, info->t[34]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r3(arr, info->mass[i][11], 16, info->t[35]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r3(arr, info->mass[i][14], 23, info->t[36]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r3(arr, info->mass[i][1], 4, info->t[37]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r3(arr, info->mass[i][4], 11, info->t[38]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r3(arr, info->mass[i][7], 16, info->t[39]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r3(arr, info->mass[i][10], 23, info->t[40]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r3(arr, info->mass[i][13], 4, info->t[41]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	block3_md5_2(info, h, i, arr);
}
