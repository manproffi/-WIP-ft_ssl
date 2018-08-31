/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block2_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:56:56 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 20:56:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

static inline void	block2_md5_2(t_info *info, t_h *h, int i, UINT arr[])
{
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r2(arr, info->mass[i][9], 5, info->t[25]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r2(arr, info->mass[i][14], 9, info->t[26]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r2(arr, info->mass[i][3], 14, info->t[27]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r2(arr, info->mass[i][8], 20, info->t[28]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r2(arr, info->mass[i][13], 5, info->t[29]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r2(arr, info->mass[i][2], 9, info->t[30]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r2(arr, info->mass[i][7], 14, info->t[31]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r2(arr, info->mass[i][12], 20, info->t[32]);
}

void				block2_md5(t_info *info, t_h *h, int i)
{
	unsigned int arr[4];

	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r2(arr, info->mass[i][1], 5, info->t[17]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r2(arr, info->mass[i][6], 9, info->t[18]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r2(arr, info->mass[i][11], 14, info->t[19]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r2(arr, info->mass[i][0], 20, info->t[20]);
	p1(arr, h->h0, h->h1, h->h2) && p2(arr, h->h3);
	h->h0 = fun_r2(arr, info->mass[i][5], 5, info->t[21]);
	p1(arr, h->h3, h->h0, h->h1) && p2(arr, h->h2);
	h->h3 = fun_r2(arr, info->mass[i][10], 9, info->t[22]);
	p1(arr, h->h2, h->h3, h->h0) && p2(arr, h->h1);
	h->h2 = fun_r2(arr, info->mass[i][15], 14, info->t[23]);
	p1(arr, h->h1, h->h2, h->h3) && p2(arr, h->h0);
	h->h1 = fun_r2(arr, info->mass[i][4], 20, info->t[24]);
	block2_md5_2(info, h, i, arr);
}
