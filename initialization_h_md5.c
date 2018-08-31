/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_h_md5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:19:31 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:19:33 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	initialization_tmp_md5(t_h *tmp, t_h *start)
{
	tmp->h0 = (start->h0);
	tmp->h1 = (start->h1);
	tmp->h2 = (start->h2);
	tmp->h3 = (start->h3);
}

void	initialization_h_md5(t_h *rhs)
{
	rhs->h0 = 0x67452301;
	rhs->h1 = 0xEFCDAB89;
	rhs->h2 = 0x98BADCFE;
	rhs->h3 = 0x10325476;
}

void	intermediate_md5(t_h *tmp, t_h *start)
{
	start->h0 += tmp->h0;
	start->h1 += tmp->h1;
	start->h2 += tmp->h2;
	start->h3 += tmp->h3;
}
