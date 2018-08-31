/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:35:44 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 21:30:14 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"
#define PR ft_printf

int		check_flag(char c)
{
	static char row[] = "rqp";
	int			i;

	i = -1;
	while (++i < 3)
		if (c == row[i])
			return (1);
	return (0);
}

void	prepare_s(t_info *info, const char *argv[], int argc)
{
	if (info->argc_count + 1 < argc)
	{
		info->argc_count += 1;
		lstaddend(&info->new_flags, lstnew(argv[info->argc_count],
					ft_strlen(argv[info->argc_count]), 's'));
	}
	else
	{
		info->flags = (info->flags | 8);
		PR("ft_ssl %s: option requires an argument --s\n", argv[1]);
		PR("usage: ./ft_ssl %s [-rqp] [-s string] [files...]\n", argv[1]);
	}
}

void	pars_string(const char *str, t_info *info, const char *argv[], int argc)
{
	size_t	i;

	i = 0;
	while (++i < ft_strlen(str))
	{
		if (check_flag(str[i]))
			lstaddend(&info->new_flags, lstnew("", 1, str[i]));
		else if (str[i] == 's')
		{
			if (str[i + 1] == '\0')
				prepare_s(info, argv, argc);
			else
			{
				lstaddend(&info->new_flags, lstnew(str + i + 1,
							ft_strlen(str + i + 1), str[i]));
				return ;
			}
		}
		else
		{
			PR("ft_ssl : illegal option -- %c\n", str[i]);
			PR("usage: ./ft_ssl %s [-rqp] [-s string] [files...]\n", argv[1]);
			exit(1);
		}
	}
}

int		pre_parsing_flags(int argc, const char *argv[], t_info *info)
{
	int	internal_flag;

	internal_flag = 1;
	while (++info->argc_count < argc)
	{
		if (argv[info->argc_count][0] == '-' && internal_flag)
			pars_string(argv[info->argc_count], info, argv, argc);
		else
		{
			lstaddend(&info->new_flags, lstnew(argv[info->argc_count],
						ft_strlen(argv[info->argc_count]), 'f'));
			internal_flag = 0;
		}
	}
	return (0);
}
