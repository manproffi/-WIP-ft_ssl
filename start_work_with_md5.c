/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_work_with_md5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:12:11 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/14 13:12:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void    start_work_with_md5(t_info *info, int argc, const char *argv[])
{
    (void)info;
    (void)argc;
    (void)argv;

    pre_parsing_flags(argc, argv, info);
//    system("leaks ft_ssl -q");
    fill_content(argc, argv, info);
//    system("leaks ft_ssl -q");

}
