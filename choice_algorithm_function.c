/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_algorithm_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:40:09 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/13 20:32:02 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	choice_alg_fun(t_info *info, const char *string, const char *filename)
{
	if (ft_strcmp(info->algo_name, "md5") == 0)
		md5_algo(info, string, filename);
	else if (ft_strcmp(info->algo_name, "sha256") == 0)
		sha256_algo(info, string, filename);
	else if (ft_strcmp(info->algo_name, "sha512") == 0)
		sha512_algo(info, string, filename);
	else
		printf("YYYYPPPPS\n\n\n");
}
