/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:12:43 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/14 16:15:52 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ssl.h"


void   delete_mass(t_info *info)
{
    size_t     i;

    i = 0;
    while (i < info->n)
    {
        free(info->mass[i]);
        ++i;
    }
    free(info->mass);
    info->mass = NULL;
}


void    initialization_t(t_info *info)
{
    size_t      i;

    i = 0;
    while (++i < 65)
    {
        info->t[i] = 4294967296 * fabs(sin(i));
//        printf("[%zu] %u\n", i - 1, info->t[i]);
    }
}

unsigned int rev_bit(unsigned int a)
{
    unsigned int a1;

    a1 = a << 24;
    a1 += (a & 65280) << 8;
    a1 += (a & 16711680) >> 8;
    a1 += a >> 24;
    return a1;
}


void    md5_algo(t_info *info, const char *string, const char *filename)
{
//    printf("*****  start md5_algo *****\n");
//    printf("%s %s\n", string, filename);
//    (void)info;

    append_padding_bits(info, string);
//    system("leaks ft_ssl -q");
    initialization_t(info);


    size_t  i;
    unsigned int a = 0x67452301;
    unsigned int b = 0xEFCDAB89;
    unsigned int c = 0x98BADCFE;
    unsigned int d = 0x10325476;

    i = -1;
    while (++i < info->n)
    {
        unsigned int aa = a;
        unsigned int bb = b;
        unsigned int cc = c;
        unsigned int dd = d;

        fun_r1(&a,b,c,d,info->mass[i][0], 7, 1, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&d,a,b,c,info->mass[i][1],12, 2, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&c,d,a,b,info->mass[i][2],17, 3, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&b,c,d,a,info->mass[i][3],22, 4, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&a,b,c,d,info->mass[i][4], 7, 5, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&d,a,b,c,info->mass[i][5],12, 6, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&c,d,a,b,info->mass[i][6],17, 7, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&b,c,d,a,info->mass[i][7],22, 8, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&a,b,c,d,info->mass[i][8], 7, 9, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&d,a,b,c,info->mass[i][9],12,10, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&c,d,a,b,info->mass[i][10],17,11, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&b,c,d,a,info->mass[i][11],22,12, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&a,b,c,d,info->mass[i][12], 7,13, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&d,a,b,c,info->mass[i][13],12,14, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&c,d,a,b,info->mass[i][14],17,15, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r1(&b,c,d,a,info->mass[i][15],22,16, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&a,b,c,d,info->mass[i][ 1], 5,17, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&d,a,b,c,info->mass[i][ 6], 9,18, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&c,d,a,b,info->mass[i][11],14,19, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&b,c,d,a,info->mass[i][ 0],20,20, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&a,b,c,d,info->mass[i][ 5], 5,21, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&d,a,b,c,info->mass[i][10], 9,22, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&c,d,a,b,info->mass[i][15],14,23, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&b,c,d,a,info->mass[i][ 4],20,24, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&a,b,c,d,info->mass[i][ 9], 5,25, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&d,a,b,c,info->mass[i][14], 9,26, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&c,d,a,b,info->mass[i][ 3],14,27, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&b,c,d,a,info->mass[i][ 8],20,28, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&a,b,c,d,info->mass[i][13], 5,29, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&d,a,b,c,info->mass[i][ 2], 9,30, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&c,d,a,b,info->mass[i][ 7],14,31, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r2(&b,c,d,a,info->mass[i][12],20,32, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&a,b,c,d,info->mass[i][ 5], 4,33, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&d,a,b,c,info->mass[i][ 8],11,34, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&c,d,a,b,info->mass[i][11],16,35, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&b,c,d,a,info->mass[i][14],23,36, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&a,b,c,d,info->mass[i][ 1], 4,37, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&d,a,b,c,info->mass[i][ 4],11,38, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&c,d,a,b,info->mass[i][ 7],16,39, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&b,c,d,a,info->mass[i][10],23,40, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&a,b,c,d,info->mass[i][13], 4,41, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&d,a,b,c,info->mass[i][ 0],11,42, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&c,d,a,b,info->mass[i][ 3],16,43, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&b,c,d,a,info->mass[i][ 6],23,44, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&a,b,c,d,info->mass[i][ 9], 4,45, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&d,a,b,c,info->mass[i][12],11,46, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&c,d,a,b,info->mass[i][15],16,47, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r3(&b,c,d,a,info->mass[i][ 2],23,48, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&a,b,c,d,info->mass[i][ 0], 6,49, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&d,a,b,c,info->mass[i][ 7],10,50, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&c,d,a,b,info->mass[i][14],15,51, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&b,c,d,a,info->mass[i][ 5],21,52, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&a,b,c,d,info->mass[i][12], 6,53, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&d,a,b,c,info->mass[i][ 3],10,54, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&c,d,a,b,info->mass[i][10],15,55, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&b,c,d,a,info->mass[i][ 1],21,56, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&a,b,c,d,info->mass[i][ 8], 6,57, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&d,a,b,c,info->mass[i][15],10,58, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&c,d,a,b,info->mass[i][ 6],15,59, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&b,c,d,a,info->mass[i][13],21,60, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&a,b,c,d,info->mass[i][ 4], 6,61, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&d,a,b,c,info->mass[i][11],10,62, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&c,d,a,b,info->mass[i][ 2],15,63, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);
        fun_r4(&b,c,d,a,info->mass[i][ 9],21,64, info);	//printf("[i = %zu] A = %u B = %u C = %u D = %u\n", i, a, b, c, d);

        a = a + aa;
        b = b + bb;
        c = c + cc;
        d = d + dd;
    }
//    printf("%#x %#x %#x %#x\n", a, b, c, d);
//
//
//    unsigned int a1 = 0;
//
//    a1 = a << 24;
//    a1 += (a & 65280) << 8;
//    a1 += (a & 16711680) >> 8;
//    a1 += a >> 24;


    info->a = a;
    info->b = b;
    info->c = c;
    info->d = d;

//    printf("%.8x%.8x%.8x%.8x\n", rev_bit(a), rev_bit(b), rev_bit(c), rev_bit(d));
//    sleep(2);
//    system("leaks ft_ssl -q");
    print_result(info, string, filename);
    delete_mass(info);




}
