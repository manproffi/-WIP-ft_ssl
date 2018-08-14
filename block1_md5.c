/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block1_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:56:48 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 21:00:30 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

static inline void	block1_md5_2(t_info *info, t_h *h, int i, UINT arr[])
{
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r1(arr, info->mass[i][9], 12, info->t[10]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r1(arr, info->mass[i][10], 17, info->t[11]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r1(arr, info->mass[i][11], 22, info->t[12]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r1(arr, info->mass[i][12], 7, info->t[13]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r1(arr, info->mass[i][13], 12, info->t[14]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r1(arr, info->mass[i][14], 17, info->t[15]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r1(arr, info->mass[i][15], 22, info->t[16]);
}

void				block1_md5(t_info *info, t_h *h, int i)
{
	unsigned int arr[4];

	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r1(arr, info->mass[i][0], 7, info->t[1]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r1(arr, info->mass[i][1], 12, info->t[2]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r1(arr, info->mass[i][2], 17, info->t[3]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r1(arr, info->mass[i][3], 22, info->t[4]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r1(arr, info->mass[i][4], 7, info->t[5]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r1(arr, info->mass[i][5], 12, info->t[6]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r1(arr, info->mass[i][6], 17, info->t[7]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r1(arr, info->mass[i][7], 22, info->t[8]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r1(arr, info->mass[i][8], 7, info->t[9]);
	block1_md5_2(info, h, i, arr);
}
