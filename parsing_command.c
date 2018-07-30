/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:58:08 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/12 20:58:11 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

//int    prepare_flag_s(t_info *info, int i, int j, const char *argv[])
//{
////    info->list
////
////    printf("**** %s \n", argv[i]);
//    if (argv[i][j + 1] != '\0') {
////        printf("**** \"%s\" %zu\n", argv[i] + j + 1, ft_strlen(argv[i] + j + 1));
////        ft_lstaddend(&info->list, ft_lstnew(argv[i] + j + 1, ft_strlen(argv[i] + j + 1) + 1));
//        md5_algo(info, argv[i] + j + 1);
//        return (0);
////        printf("**11** %s\n", info->list->content);
//    }
//    else
//    {
////        ft_lstaddend(&info->list, ft_lstnew(argv[i + 1], ft_strlen(argv[i + 1]) + 1));
//        if (argv[i + 1] == NULL)
//        {
//            printf("ft_ssl : illegal option -- %c\n", argv[i][j]);
//            printf("usage: ./ft_ssl %s [-rqp] [-s string] [files...]\n", argv[1]);
//            exit(1);
//        }
//
//        md5_algo(info, argv[i + 1]);
//        info->argc_count += 1;
//        return (1);
////        printf("**22** %s\n", info->list->content);
//    }
////    work_flag_s();
////    printf("**** %s\n", info->list->content);
//
//
//}

//int		check_flag(char c)
//{
//    static char row[] = "rqp";
//    int			i;
//
//    i = -1;
//    while (++i < 3)
//        if (c == row[i])
//            return (1);
//    return (0);
//}

//int	    list_flag(t_info *info, int i, int j, const char *argv[])
//{
//	int		flag_correct;
//
//	flag_correct = info->flags;
//	info->flags = (argv[i][j] == 'r') ? (info->flags | 1) : (info->flags);
//	info->flags = (argv[i][j] == 'q') ? (info->flags | 2) : (info->flags);
//	if (argv[i][j] == 'p')
//    {
//        printf("***%c\n", argv[i][j]);
//        info->flags = info->flags | 4;
//        if (info->disable_p)
//        {
//            md5_algo(info, "");
//            return (0);
//        }
//        read_screen(info, 1);
//        if (info->new_flags != 4)
//            info->disable_p = 1;

//        if (info->disable_p == 0 && info->new_flags == 4)
//        {
//            read_screen(info, 1);
//            info->disable_p = 1;
//            return (0);
//        }
//        else if (info->disable_p == 0 && info->new_flags != 4)
//        {
//            md5_algo(info, "");
//        }
//        else if (info->disable_p == 1 && info->new_flags == 4)
//             md5_algo(info, "");
//        else
//            read_screen(info, 1);


//
//    }
//    if (argv[i][j] == 's')
//    {
//        info->flags = info->flags | 8;
//        prepare_flag_s(info, i, j, argv);
//
//        return (1);
//    }
//
//
//	if (flag_correct == info->flags)
//	{
//		if (check_flag(argv[i][j]))
//			return (0);
//		printf("ft_ssl : illegal option -- %c\n", argv[i][j]);
//		printf("usage: ./ft_ssl %s [-rqp] [-s string] [files...]\n", argv[1]);
//		exit(1);
//	}
//    return (0);
//
//
//}

void	parsing_flags(int argc, const char *argv[], t_info *info)
{
    (void)argc;
    (void)argv;
    (void)info;

//	int		j;
//
//	while (++info->argc_count < argc)
//	{
//		if (argv[info->argc_count][0] == '-')
//		{
//			j = 0;
//			while (++j < (int)ft_strlen(argv[info->argc_count]))
//            {
////                printf("--->>>%c\n", argv[info->argc_count][j]);
//                if (list_flag(info, info->argc_count, j, argv))
//                    break ;
//            }
//		}
//		else
//			break ;
//	}
}
