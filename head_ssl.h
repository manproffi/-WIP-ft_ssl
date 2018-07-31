/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_ssl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:38:22 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/12 20:38:24 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_SSL
# define HEAD_SSL

#include "lib_folder/libft/libft.h"
//#include "lib_folder/ft_printf/printhead.h"
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <stdio.h> //delete
//
//typedef struct      s_block
//{
//    int             b0;
//    int             b1;
//    int             b2;
//    int             b3;
//    int             b4;
//    int             b5;
//    int             b6;
//    int             b7;
//    int             b8;
//    int             b9;
//    int             b10;
//    int             b11;
//    int             b12;
//    int             b13;
//    int             b14;
//    int             b15;
//}                   t_block;

typedef struct      s_flags
{
    char            key;
    char            *content;
    size_t          content_size;
    struct s_flags  *next;
}                   t_flags;

typedef struct 		s_info
{
	int				flags;
    int             keys;
	int				argc_count;
    int             validation_flag;

    size_t          n;
    unsigned int    **mass;


    unsigned int    a;
    unsigned int    b;
    unsigned int    c;
    unsigned int    d;

    unsigned int    t[65];

    struct s_flags  *new_flags;
}					t_info;

void	parsing_flags(int argc, const char *argv[], t_info *info);
void    start_work_with_md5(t_info *info, int argc, const char *argv[]);
void    start_work_with_sha256(t_info *info, int argc, const char *argv[]);
void    md5_algo(t_info *info, const char *string, const char *filename);
void    append_padding_bits(t_info *info, const char *string);
void	read_screen(t_info *info, int flag_p);
void    read_file(t_info *info, const char *name);
void    print_result(t_info * info, const char *str, const char *filename);
unsigned int rev_bit(unsigned int a);
int    pre_parsing_flags(int argc, const char *argv[], t_info *info);
void    fill_content(int argc, const char *argv[], t_info *info);


void	lstaddend(t_flags **alst, t_flags *new);
t_flags	*lstnew(void const *content, size_t content_size, char c);
void	del_list_list(t_flags **list);

unsigned int    fun_f(unsigned int x, unsigned int y, unsigned int z);
unsigned int    fun_g(unsigned int x, unsigned int y, unsigned int z);
unsigned int    fun_h(unsigned int x, unsigned int y, unsigned int z);
unsigned int    fun_i(unsigned int x, unsigned int y, unsigned int z);

void    fun_r1(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);
void    fun_r2(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);
void    fun_r3(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);
void    fun_r4(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);



#endif