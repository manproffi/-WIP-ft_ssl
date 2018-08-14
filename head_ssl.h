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

#ifndef HEAD_SSL_H
# define HEAD_SSL_H

# include "lib_folder/libft/libft.h"
# include "lib_folder/ft_printf/printhead.h"
# include "head_ssl_struct.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>

# define ULLI unsigned long long int
# define UINT unsigned int

void	md5_algo(t_info *info, const char *string, const char *filename);
void	sha256_algo(t_info *info, const char *string, const char *filename);
void	append_padding_bits(t_info *info, const char *string);
void	append_padding_bits_256(t_info *info, const char *string);
void	append_padding_bits_512(t_info *info, const char *string);
void	read_screen(t_info *info, int flag_p);
void	read_file(t_info *info, const char *name);
void	print_result(t_info *info, const char *str, const char *filename);
UINT	rev_bit(unsigned int a);
int		pre_parsing_flags(int argc, const char *argv[], t_info *info);
void	fill_content(int argc, const char *argv[], t_info *info);
void	choice_alg_fun(t_info *info, const char *string, const char *filename);
void	print_res_sha256(t_info *info, const char *str, const char *f, t_h *h);
void	sha512_algo(t_info *info, const char *string, const char *filename);
void	p_r_sha512(t_info *info, const char *str, const char *f, t_512 *h);
ULLI	internal_loop_part(t_h *tmp, unsigned int m[], t_info *info, int i);
ULLI	internal_loop_part_512(t_512 *tmp, ULLI m[], t_info *info, int i);

void	lstaddend(t_flags **alst, t_flags *new);
t_flags *lstnew(const char *content, size_t content_size, char c);
void	del_list_list(t_flags **list);
void	main_loop(t_info *info, t_h *h);
void	main_loop_512(t_info *info, t_512 *h);
void	delete_mass_sha512(t_info *info);

UINT	fun_f(unsigned int x, unsigned int y, unsigned int z);
UINT	fun_g(unsigned int x, unsigned int y, unsigned int z);
UINT	fun_h(unsigned int x, unsigned int y, unsigned int z);
UINT	fun_i(unsigned int x, unsigned int y, unsigned int z);

UINT	rotr(unsigned int x, int n);
UINT	shr(unsigned int x, int n);
UINT	ch(unsigned int x, unsigned int y, unsigned int z);
UINT	maj(unsigned int x, unsigned int y, unsigned int z);
UINT	sigma0(unsigned int x);
UINT	sigma1(unsigned int x);
UINT	delta0(unsigned int x);
UINT	delta1(unsigned int x);

UINT	fun_r1(UINT arr[], UINT x, UINT s, UINT k);
UINT	fun_r2(UINT arr[], UINT x, UINT s, UINT k);
UINT	fun_r3(UINT arr[], UINT x, UINT s, UINT k);
UINT	fun_r4(UINT arr[], UINT x, UINT s, UINT k);

void	block1_md5(t_info *info, t_h *h, int i);
void	block2_md5(t_info *info, t_h *h, int i);
void	block3_md5(t_info *info, t_h *h, int i);
void	block4_md5(t_info *info, t_h *h, int i);

void	initialization_tmp_md5(t_h *tmp, t_h *start);
void	initialization_h_md5(t_h *rhs);
void	intermediate_md5(t_h *tmp, t_h *start);

ULLI	rotr_64(ULLI x, int n);
ULLI	shr_64(ULLI x, int n);
ULLI	ch_64(ULLI x, ULLI y, ULLI z);
ULLI	maj_64(ULLI x, ULLI y, ULLI z);
ULLI	sigma0_64(ULLI x);
ULLI	sigma1_64(ULLI x);
ULLI	delta0_64(ULLI x);
ULLI	delta1_64(ULLI x);
ULLI	rev_bit_512(ULLI a);

int		p1(UINT arr[], UINT a, UINT b, UINT c);
int		p2(UINT arr[], UINT d);

#endif
