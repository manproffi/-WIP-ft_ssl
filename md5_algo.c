/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:12:43 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:17:00 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define UINT unsigned int

void	delete_mass(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->n)
	{
		free(info->mass[i]);
		++i;
	}
	free(info->mass);
	info->mass = NULL;
}

void	initialization_t(t_info *info)
{
	size_t	i;

	i = 0;
	while (++i < 65)
	{
		info->t[i] = 4294967296 * fabs(sin(i));
	}
}

UINT	rev_bit(unsigned int a)
{
	unsigned int a1;

	a1 = a << 24;
	a1 += (a & 65280) << 8;
	a1 += (a & 16711680) >> 8;
	a1 += a >> 24;
	return (a1);
}

void	md5_algo(t_info *info, const char *string, const char *filename)
{
	int		i;
	t_h		h;
	t_h		tmp;

	initialization_h_md5(&h);
	append_padding_bits(info, string);
	initialization_t(info);
	i = -1;
	while (++i < (int)info->n)
	{
		initialization_tmp_md5(&tmp, &h);
		block1_md5(info, &h, i);
		block2_md5(info, &h, i);
		block3_md5(info, &h, i);
		block4_md5(info, &h, i);
		intermediate_md5(&tmp, &h);
	}
	info->a = h.h0;
	info->b = h.h1;
	info->c = h.h2;
	info->d = h.h3;
	print_result(info, string, filename);
	delete_mass(info);
}
