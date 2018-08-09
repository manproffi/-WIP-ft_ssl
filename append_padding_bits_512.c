
#include "head_ssl.h"

#define ULLI unsigned long long int

ULLI rev_bit_512(ULLI a)
{
    ULLI a1;

    a1 = a << 56;
    a1 += (a & 0xFF00) << 40;
    a1 += (a & 0xFF0000) << 24;
    a1 += (a & 0xFF000000) << 8;
    a1 += (a & 0xFF00000000) >> 8;
    a1 += (a & 0xFF0000000000) >> 24;
    a1 += (a & 0xFF000000000000) >> 40;
    a1 += a >> 56;
    return a1;
}

static void    allocate_memory(t_info *info)
{
    size_t i;

    info->mass_512 = (ULLI**)malloc(sizeof(ULLI*) * info->n);
    i = 0;
    while (i < info->n)
    {
        info->mass_512[i] = (ULLI*)malloc(sizeof(ULLI) * 16);
        ++i;
    }
}

static void    next_step_fill_mass(t_info *info, const char *string)
{
    int     i;
    int     j;
    int     k;
    char    *tmp;
    unsigned long long int len;

    allocate_memory(info);
    i = -1;
    j = -1;

    while (++j < (int)info->n)
    {
        tmp = (char*)info->mass_512[j];
        ft_bzero(tmp, 16 * 8);
        k = -1;
        while (++k < 128 && ++i < (int)ft_strlen(string))
        {
            tmp[k] = string[i];
        }
        if (i == (int)ft_strlen(string))
            tmp[k] = (char)128;
    }
    len = (ULLI)ft_strlen(string) * 8;
    info->mass_512[info->n - 1][14] = 0; //rev_bit((ULLI)(len >> 64));
    info->mass_512[info->n - 1][15] = rev_bit_512(len);
}


void    append_padding_bits_512(t_info *info, const char *string)
{
	info->n = (ft_strlen(string) * 8) / 1024;
	if ((info->n + 1) * 1024 - 128 > ft_strlen(string) * 8)
		info->n += 1;
	else
		info->n += 2;
	next_step_fill_mass(info, string);
}