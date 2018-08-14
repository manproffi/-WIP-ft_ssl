/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:40:57 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/07 20:40:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define ULL unsigned long long

void	prepare_message_schedule(t_info *info, unsigned int m[], int n)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		m[i] = rev_bit(info->mass[n - 1][i]);
	}
	while (i < 64)
	{
		m[i] = (m[i - 16] + delta0(m[i - 15]) + m[i - 7] + delta1(m[i - 2]));
		++i;
	}
}

void	initializ_tmp(t_h *tmp, t_h *start)
{
	tmp->h0 = (start->h0);
	tmp->h1 = (start->h1);
	tmp->h2 = (start->h2);
	tmp->h3 = (start->h3);
	tmp->h4 = (start->h4);
	tmp->h5 = (start->h5);
	tmp->h6 = (start->h6);
	tmp->h7 = (start->h7);
}

void	internal_loop(t_h *tmp, unsigned int m[], t_info *info)
{
	int					i;
	unsigned long long	temp1;
	unsigned long long	temp2;
	unsigned long long	temporary;

	i = -1;
	while (++i < 64)
	{
		temp1 = internal_loop_part(tmp, m, info, i);
		temp2 = (ULL)(sigma0(tmp->h0)) + (maj(tmp->h0, tmp->h1, tmp->h2));
		temp2 %= 4294967296;
		tmp->h7 = (tmp->h6);
		tmp->h6 = (tmp->h5);
		tmp->h5 = (tmp->h4);
		temporary = (tmp->h3) + temp1;
		tmp->h4 = (unsigned int)(temporary % 4294967296);
		tmp->h3 = (tmp->h2);
		tmp->h2 = (tmp->h1);
		tmp->h1 = (tmp->h0);
		temporary = (temp1 + temp2);
		tmp->h0 = (unsigned int)(temporary % 4294967296);
	}
}

void	intermediate(t_h *tmp, t_h *start)
{
	start->h0 += tmp->h0;
	start->h1 += tmp->h1;
	start->h2 += tmp->h2;
	start->h3 += tmp->h3;
	start->h4 += tmp->h4;
	start->h5 += tmp->h5;
	start->h6 += tmp->h6;
	start->h7 += tmp->h7;
}

void	main_loop(t_info *info, t_h *h)
{
	size_t			i;
	unsigned int	mass[64];
	t_h				tmp;

	i = 0;
	while (++i <= info->n)
	{
		prepare_message_schedule(info, mass, i);
		initializ_tmp(&tmp, h);
		internal_loop(&tmp, mass, info);
		intermediate(&tmp, h);
	}
}
