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

void	print_debug(t_h *h)
{
	printf("%.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x\n",   (h->h0),
									(h->h1),
									(h->h2),
									(h->h3),
									(h->h4),
									(h->h5),
									(h->h6),
									(h->h7)
	);
}

void	prepare_message_schedule(t_info *info, unsigned int m[], int n)
{
	int 	i;

	i = -1;
	while (++i < 16)
	{
		m[i] = rev_bit(info->mass[n - 1][i]);
		// printf("i = %d %08x\n",i, m[i]);
	}
	while (i < 64)
	{
		m[i] = (m[i - 16] + delta0(m[i - 15]) + m[i - 7] + delta1(m[i - 2]));
		++i;
	}
}

void	initializ_tmp(t_h * tmp, t_h *start)
{
	tmp->h0 = (start->h0);	//	a
	tmp->h1 = (start->h1);	//	b
	tmp->h2 = (start->h2);	//	c
	tmp->h3 = (start->h3);	//	d
	tmp->h4 = (start->h4);	//	e
	tmp->h5 = (start->h5);	//	f
	tmp->h6 = (start->h6);	//	g
	tmp->h7 = (start->h7);	//	h
	
		// print_debug(start);
	// sleep(32);
}

unsigned long long internal_loop_part(t_h *tmp, int m[], t_info *info, int i)
{
	unsigned long long temp1;

	temp1 = (unsigned long long)(tmp->h7) + (sigma1(tmp->h4));
	temp1 %= 4294967296;
	temp1 += ch(tmp->h4, tmp->h5, tmp->h6);
	temp1 %= 4294967296;
	temp1 += m[i];
	temp1 %= 4294967296;
	temp1 += info->t[i];
	temp1 %= 4294967296;
	return (temp1);
}

void	internal_loop(t_h *tmp, int m[], t_info *info)
{
	int 	i;
	unsigned long long temp1;
	unsigned long long temp2;
	unsigned long long temporary;

	i = -1;
	while (++i < 64)
	{
		temp1 = internal_loop_part(tmp, m, info, i);
		temp2 = (unsigned long long)(sigma0(tmp->h0)) + (maj(tmp->h0, tmp->h1, tmp->h2));
		temp2 %= 4294967296;
		tmp->h7 = 	(tmp->h6);
		tmp->h6 = 	(tmp->h5);
		tmp->h5 = 	(tmp->h4);
		temporary = (tmp->h3) + temp1;
		tmp->h4 = 	(unsigned int)(temporary % 4294967296);
		tmp->h3 = 	(tmp->h2);
		tmp->h2 = 	(tmp->h1);
		tmp->h1 = 	(tmp->h0);
		temporary = (temp1 + temp2);
		tmp->h0 = (unsigned int)(temporary % 4294967296);
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


// void	print_res_sha256(t_h *h)
// {
// 	printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",    (h->h0),
// 									(h->h1),
// 									(h->h2),
// 									(h->h3),
// 									(h->h4),
// 									(h->h5),
// 									(h->h6),
// 									(h->h7)
// 	);
// }

void	main_loop(t_info *info, t_h *h)
{
	size_t 	i;
	unsigned int mass[64];
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
	// print_res_sha256(h);
}
