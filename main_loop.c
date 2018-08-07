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
//1. Prepare the message schedule W:
//		For t = 0 to 15
//Wt = M(i)t
//		For t = 16 to 63
//Wt = SSIG1(W(t-2)) + W(t-7) + SSIG0(t-15) + W(t-16)


//Wt-16 + Delta0(Wt-15 ) + Wi-7 + Delta1(Wt-2 ), для t = 16..63

void	prepare_message_schedule(t_info *info, int m[], int n)
{
	int 	i;

	i = -1;
	while (++i < 16)
	{
		m[i] = info->mass[n - 1][i];
//		printf("%d %u\n",, m[i]);
	}
	while (i < 64)
	{
		m[i] = m[i - 16] + delta0(m[i - 15]) + m[i - 7] + delta1(m[i - 2]);
		++i;
	}
}
void	initializ_tmp(t_h * tmp, t_h *start)
{
	tmp->h0 = start->h0;
	tmp->h1 = start->h1;
	tmp->h2 = start->h2;
	tmp->h3 = start->h3;
	tmp->h4 = start->h4;
	tmp->h5 = start->h5;
	tmp->h6 = start->h6;
	tmp->h7 = start->h7;
}

void	internal_loop(t_h *tmp, int m[], t_info *info)
{
	int 	i;
	unsigned int temp1;
	unsigned int temp2;

	i = -1;
	while (++i < 64)
	{
		temp1 = tmp->h7 + sigma1(tmp->h4) + ch(tmp->h4, tmp->h5, tmp->h6) + m[i] + info->t[i];
		temp2 = sigma0(tmp->h0) + maj(tmp->h0, tmp->h1, tmp->h2);
		tmp->h7 = tmp->h6;
		tmp->h6 = tmp->h5;
		tmp->h5 = tmp->h4;
		tmp->h4 = tmp->h3 + temp1;
		tmp->h3 = tmp->h2;
		tmp->h2 = tmp->h1;
		tmp->h1 = tmp->h0;
		tmp->h0 = temp1 + temp2;
	}
}

void	intermediate(t_h * tmp, t_h *start)
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


void	print_res_sha256(t_h *h)
{
	printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",    rev_bit(h->h0),
									rev_bit(h->h1),
									rev_bit(h->h2),
									rev_bit(h->h3),
									rev_bit(h->h4),
									rev_bit(h->h5),
									rev_bit(h->h6),
									rev_bit(h->h7)
	);
}

void	main_loop(t_info *info, t_h *h)
{
	size_t 	i;
	int mass[64];
	t_h 	tmp;

	i = 0;
	while (++i <= info->n)
	{
		prepare_message_schedule(info, mass, i);
		initializ_tmp(&tmp, h);
		internal_loop(&tmp, mass, info);
		intermediate(&tmp, h);


//		int j = -1;
//		while (++j < 64)
//			printf("%d %u\n",j, mass[j]);
	}
	print_res_sha256(h);

}
