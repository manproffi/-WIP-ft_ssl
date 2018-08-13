/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_padding_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:48:34 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:24:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

static void		allocate_memory(t_info *info)
{
	size_t i;

	info->mass = (unsigned int**)malloc(sizeof(unsigned int*) * info->n);
	i = 0;
	while (i < info->n)
	{
		info->mass[i] = (unsigned int*)malloc(sizeof(unsigned int) * 16);
		++i;
	}
}

static void		fill_mass(t_info *info, const char *string)
{
	int					i;
	int					j;
	int					k;
	char				*tmp;
	unsigned long long	len;

	allocate_memory(info);
	i = -1;
	j = -1;
	while (++j < (int)info->n)
	{
		tmp = (char*)info->mass[j];
		ft_bzero(tmp, 16 * 4);
		k = -1;
		while (++k < 64 && ++i < (int)ft_strlen(string))
		{
			tmp[k] = string[i];
		}
		if (i == (int)ft_strlen(string))
			tmp[k] = (char)128;
	}
	len = ft_strlen(string) * 8;
	info->mass[info->n - 1][15] = (unsigned int)(len >> 32);
	info->mass[info->n - 1][14] = (unsigned int)(len & 4294967295);
}

void			append_padding_bits(t_info *info, const char *string)
{
	info->n = (ft_strlen(string) * 8) / 512;
	if ((info->n + 1) * 512 - 64 > ft_strlen(string) * 8)
		info->n += 1;
	else
		info->n += 2;
	fill_mass(info, string);
}
