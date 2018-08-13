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

void	block1_md5(t_info *info, t_h *h, int i)
{
	fun_r1(&h->h0, h->h1, h->h2, h->h3, info->mass[i][0], 7, 1, info);
	fun_r1(&h->h3, h->h0, h->h1, h->h2, info->mass[i][1], 12, 2, info);
	fun_r1(&h->h2, h->h3, h->h0, h->h1, info->mass[i][2], 17, 3, info);
	fun_r1(&h->h1, h->h2, h->h3, h->h0, info->mass[i][3], 22, 4, info);
	fun_r1(&h->h0, h->h1, h->h2, h->h3, info->mass[i][4], 7, 5, info);
	fun_r1(&h->h3, h->h0, h->h1, h->h2, info->mass[i][5], 12, 6, info);
	fun_r1(&h->h2, h->h3, h->h0, h->h1, info->mass[i][6], 17, 7, info);
	fun_r1(&h->h1, h->h2, h->h3, h->h0, info->mass[i][7], 22, 8, info);
	fun_r1(&h->h0, h->h1, h->h2, h->h3, info->mass[i][8], 7, 9, info);
	fun_r1(&h->h3, h->h0, h->h1, h->h2, info->mass[i][9], 12, 10, info);
	fun_r1(&h->h2, h->h3, h->h0, h->h1, info->mass[i][10], 17, 11, info);
	fun_r1(&h->h1, h->h2, h->h3, h->h0, info->mass[i][11], 22, 12, info);
	fun_r1(&h->h0, h->h1, h->h2, h->h3, info->mass[i][12], 7, 13, info);
	fun_r1(&h->h3, h->h0, h->h1, h->h2, info->mass[i][13], 12, 14, info);
	fun_r1(&h->h2, h->h3, h->h0, h->h1, info->mass[i][14], 17, 15, info);
	fun_r1(&h->h1, h->h2, h->h3, h->h0, info->mass[i][15], 22, 16, info);
}

void	block2_md5(t_info *info, t_h *h, int i)
{
	fun_r2(&h->h0, h->h1, h->h2, h->h3, info->mass[i][1], 5, 17, info);
	fun_r2(&h->h3, h->h0, h->h1, h->h2, info->mass[i][6], 9, 18, info);
	fun_r2(&h->h2, h->h3, h->h0, h->h1, info->mass[i][11], 14, 19, info);
	fun_r2(&h->h1, h->h2, h->h3, h->h0, info->mass[i][0], 20, 20, info);
	fun_r2(&h->h0, h->h1, h->h2, h->h3, info->mass[i][5], 5, 21, info);
	fun_r2(&h->h3, h->h0, h->h1, h->h2, info->mass[i][10], 9, 22, info);
	fun_r2(&h->h2, h->h3, h->h0, h->h1, info->mass[i][15], 14, 23, info);
	fun_r2(&h->h1, h->h2, h->h3, h->h0, info->mass[i][4], 20, 24, info);
	fun_r2(&h->h0, h->h1, h->h2, h->h3, info->mass[i][9], 5, 25, info);
	fun_r2(&h->h3, h->h0, h->h1, h->h2, info->mass[i][14], 9, 26, info);
	fun_r2(&h->h2, h->h3, h->h0, h->h1, info->mass[i][3], 14, 27, info);
	fun_r2(&h->h1, h->h2, h->h3, h->h0, info->mass[i][8], 20, 28, info);
	fun_r2(&h->h0, h->h1, h->h2, h->h3, info->mass[i][13], 5, 29, info);
	fun_r2(&h->h3, h->h0, h->h1, h->h2, info->mass[i][2], 9, 30, info);
	fun_r2(&h->h2, h->h3, h->h0, h->h1, info->mass[i][7], 14, 31, info);
	fun_r2(&h->h1, h->h2, h->h3, h->h0, info->mass[i][12], 20, 32, info);
}

void	block3_md5(t_info *info, t_h *h, int i)
{
	fun_r3(&h->h0, h->h1, h->h2, h->h3, info->mass[i][5], 4, 33, info);
	fun_r3(&h->h3, h->h0, h->h1, h->h2, info->mass[i][8], 11, 34, info);
	fun_r3(&h->h2, h->h3, h->h0, h->h1, info->mass[i][11], 16, 35, info);
	fun_r3(&h->h1, h->h2, h->h3, h->h0, info->mass[i][14], 23, 36, info);
	fun_r3(&h->h0, h->h1, h->h2, h->h3, info->mass[i][1], 4, 37, info);
	fun_r3(&h->h3, h->h0, h->h1, h->h2, info->mass[i][4], 11, 38, info);
	fun_r3(&h->h2, h->h3, h->h0, h->h1, info->mass[i][7], 16, 39, info);
	fun_r3(&h->h1, h->h2, h->h3, h->h0, info->mass[i][10], 23, 40, info);
	fun_r3(&h->h0, h->h1, h->h2, h->h3, info->mass[i][13], 4, 41, info);
	fun_r3(&h->h3, h->h0, h->h1, h->h2, info->mass[i][0], 11, 42, info);
	fun_r3(&h->h2, h->h3, h->h0, h->h1, info->mass[i][3], 16, 43, info);
	fun_r3(&h->h1, h->h2, h->h3, h->h0, info->mass[i][6], 23, 44, info);
	fun_r3(&h->h0, h->h1, h->h2, h->h3, info->mass[i][9], 4, 45, info);
	fun_r3(&h->h3, h->h0, h->h1, h->h2, info->mass[i][12], 11, 46, info);
	fun_r3(&h->h2, h->h3, h->h0, h->h1, info->mass[i][15], 16, 47, info);
	fun_r3(&h->h1, h->h2, h->h3, h->h0, info->mass[i][2], 23, 48, info);
}

void	block4_md5(t_info *info, t_h *h, int i)
{
	fun_r4(&h->h0, h->h1, h->h2, h->h3, info->mass[i][0], 6, 49, info);
	fun_r4(&h->h3, h->h0, h->h1, h->h2, info->mass[i][7], 10, 50, info);
	fun_r4(&h->h2, h->h3, h->h0, h->h1, info->mass[i][14], 15, 51, info);
	fun_r4(&h->h1, h->h2, h->h3, h->h0, info->mass[i][5], 21, 52, info);
	fun_r4(&h->h0, h->h1, h->h2, h->h3, info->mass[i][12], 6, 53, info);
	fun_r4(&h->h3, h->h0, h->h1, h->h2, info->mass[i][3], 10, 54, info);
	fun_r4(&h->h2, h->h3, h->h0, h->h1, info->mass[i][10], 15, 55, info);
	fun_r4(&h->h1, h->h2, h->h3, h->h0, info->mass[i][1], 21, 56, info);
	fun_r4(&h->h0, h->h1, h->h2, h->h3, info->mass[i][8], 6, 57, info);
	fun_r4(&h->h3, h->h0, h->h1, h->h2, info->mass[i][15], 10, 58, info);
	fun_r4(&h->h2, h->h3, h->h0, h->h1, info->mass[i][6], 15, 59, info);
	fun_r4(&h->h1, h->h2, h->h3, h->h0, info->mass[i][13], 21, 60, info);
	fun_r4(&h->h0, h->h1, h->h2, h->h3, info->mass[i][4], 6, 61, info);
	fun_r4(&h->h3, h->h0, h->h1, h->h2, info->mass[i][11], 10, 62, info);
	fun_r4(&h->h2, h->h3, h->h0, h->h1, info->mass[i][2], 15, 63, info);
	fun_r4(&h->h1, h->h2, h->h3, h->h0, info->mass[i][9], 21, 64, info);
}
