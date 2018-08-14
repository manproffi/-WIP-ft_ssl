/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:43:50 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/04 16:10:02 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"

void	read_screen(t_info *info, int flag_p)
{
	char			buffer[101];
	char			*input_str;
	char			*tmp;
	size_t			i;
	static int		counter = 0;

	input_str = (char*)malloc(sizeof(char) * 1);
	input_str[0] = '\0';
	if (!counter++)
		while ((i = read(0, &buffer, 100)) > 0)
		{
			buffer[i] = '\0';
			tmp = input_str;
			input_str = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
	else
	{
		ft_strdel(&input_str);
		input_str = ft_strdup("");
	}
	if (flag_p)
		ft_printf("%s", input_str);
	choice_alg_fun(info, input_str, "");
	ft_strdel(&input_str);
}
