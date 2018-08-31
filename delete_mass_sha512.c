/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mass_sha512.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:33:45 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 22:33:47 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	delete_mass_sha512(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->n)
	{
		free(info->mass_512[i]);
		++i;
	}
	free(info->mass_512);
	info->mass = NULL;
}
