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

#define ULLI unsigned long long int

typedef struct      s_512
{
    unsigned long long int    h0;
    unsigned long long int    h1;
    unsigned long long int    h2;
    unsigned long long int    h3;
    unsigned long long int    h4;
    unsigned long long int    h5;
    unsigned long long int    h6;
    unsigned long long int    h7;
}                   t_512;


typedef struct      s_h_num
{
	unsigned int    h0;
	unsigned int    h1;
	unsigned int    h2;
	unsigned int    h3;
	unsigned int    h4;
	unsigned int    h5;
	unsigned int    h6;
	unsigned int    h7;
}                   t_h;



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

    char            *algo_name;

    size_t          n;
    unsigned int    **mass;
    unsigned long long int **mass_512;



    unsigned int    a;
    unsigned int    b;
    unsigned int    c;
    unsigned int    d;

    unsigned int    t[65];
    unsigned long long int k[80];

    struct s_flags  *new_flags;
}					t_info;

void    md5_algo(t_info *info, const char *string, const char *filename);
void    sha256_algo(t_info *info, const char *string, const char *filename);
void    append_padding_bits(t_info *info, const char *string);
void    append_padding_bits_256(t_info *info, const char *string);
void    append_padding_bits_512(t_info *info, const char *string);
void	read_screen(t_info *info, int flag_p);
void    read_file(t_info *info, const char *name);
void    print_result(t_info * info, const char *str, const char *filename);
unsigned int rev_bit(unsigned int a);
int    pre_parsing_flags(int argc, const char *argv[], t_info *info);
void    fill_content(int argc, const char *argv[], t_info *info);
void    choice_alg_fun(t_info *info, const char *string, const char *filename);
void    print_res_sha256(t_info *info, const char *str,  const char *filename, t_h *h);
void    sha512_algo(t_info *info, const char *string, const char *filename);
void    print_res_sha512(t_info *info, const char *str,  const char *filename, t_512 *h);


void	lstaddend(t_flags **alst, t_flags *new);
t_flags *lstnew(const char *content, size_t content_size, char c);
void	del_list_list(t_flags **list);
void	main_loop(t_info *info, t_h *h);
void    main_loop_512(t_info *info, t_512 *h);

unsigned int    fun_f(unsigned int x, unsigned int y, unsigned int z);
unsigned int    fun_g(unsigned int x, unsigned int y, unsigned int z);
unsigned int    fun_h(unsigned int x, unsigned int y, unsigned int z);
unsigned int    fun_i(unsigned int x, unsigned int y, unsigned int z);

void    fun_r1(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);
void    fun_r2(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);
void    fun_r3(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);
void    fun_r4(unsigned int *a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int i, t_info *info);


unsigned int    rotr(unsigned int x, int n);
unsigned int    shr(unsigned int x, int n);
unsigned int    ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int    maj(unsigned int x, unsigned int y, unsigned int z);
unsigned int    sigma0(unsigned int x);
unsigned int    sigma1(unsigned int x);
unsigned int    delta0(unsigned int x);
unsigned int    delta1(unsigned int x);

void	block1_md5(t_info *info, t_h *h, int i);
void	block2_md5(t_info *info, t_h *h, int i);
void	block3_md5(t_info *info, t_h *h, int i);
void	block4_md5(t_info *info, t_h *h, int i);

void	initialization_tmp_md5(t_h *tmp, t_h *start);
void	initialization_h_md5(t_h *rhs);
void	intermediate_md5(t_h *tmp, t_h *start);

ULLI    rotr_64(ULLI  x, int n);
ULLI    shr_64(ULLI  x, int n);
ULLI    ch_64(ULLI  x, ULLI  y, ULLI  z);
ULLI    maj_64(ULLI x, ULLI y, ULLI  z);
ULLI    sigma0_64(ULLI x);
ULLI    sigma1_64(ULLI x);
ULLI    delta0_64(ULLI x);
ULLI    delta1_64(ULLI x);
ULLI	rev_bit_512(ULLI a);






#endif