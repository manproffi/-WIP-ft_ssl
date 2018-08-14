/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_loop_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 21:18:45 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 21:18:47 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define ULLI unsigned long long int

ULLI	internal_loop_part(t_h *tmp, unsigned int m[], t_info *info, int i)
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

ULLI	internal_loop_part_512(t_512 *tmp, ULLI m[], t_info *info, int i)
{
	ULLI temp1;

	temp1 = (tmp->h7) + sigma1_64(tmp->h4);
	temp1 += ch_64(tmp->h4, tmp->h5, tmp->h6);
	temp1 += m[i];
	temp1 += info->k[i];
	return (temp1);
}
