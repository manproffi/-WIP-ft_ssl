/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_ssl_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:46:56 by sprotsen          #+#    #+#             */
/*   Updated: 2018/08/14 22:48:28 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_SSL_STRUCT_H
# define HEAD_SSL_STRUCT_H

typedef struct				s_512
{
	unsigned long long int	h0;
	unsigned long long int	h1;
	unsigned long long int	h2;
	unsigned long long int	h3;
	unsigned long long int	h4;
	unsigned long long int	h5;
	unsigned long long int	h6;
	unsigned long long int	h7;
}							t_512;

typedef struct				s_h_num
{
	unsigned int			h0;
	unsigned int			h1;
	unsigned int			h2;
	unsigned int			h3;
	unsigned int			h4;
	unsigned int			h5;
	unsigned int			h6;
	unsigned int			h7;
}							t_h;

typedef struct				s_flags
{
	char					key;
	char					*content;
	size_t					content_size;
	struct s_flags			*next;
}							t_flags;

typedef struct				s_info
{
	int						flags;
	int						keys;
	int						argc_count;
	int						validation_flag;

	char					*algo_name;

	size_t					n;
	unsigned int			**mass;
	unsigned long long int	**mass_512;
	unsigned int			a;
	unsigned int			b;
	unsigned int			c;
	unsigned int			d;

	unsigned int			t[65];
	unsigned long long int	k[80];

	struct s_flags			*new_flags;
}							t_info;

#endif
