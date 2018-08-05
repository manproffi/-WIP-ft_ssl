/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:53:14 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/05 14:53:16 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void    start_work(t_info *info, int argc, const char *argv[])
{
    pre_parsing_flags(argc, argv, info);
    fill_content(argc, argv, info);
}