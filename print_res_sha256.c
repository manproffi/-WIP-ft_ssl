#include "head_ssl.h"

static void	print_1(t_h *h)
{
	printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", h->h0,
												 h->h1,
												 h->h2,
												 h->h3,
												 h->h4,
												 h->h5,
												 h->h6,
												 h->h7
	);
}

static void	print_2(t_info *info, t_h *h, const char *filename, const char *str)
{
	if ((info->flags & 32) == 32)
	{
		printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x %s\n", h->h0,
												h->h1,
												h->h2,
												h->h3,
												h->h4,
												h->h5,
												h->h6,
												h->h7,
												filename
		);
		info->flags = info->flags & ~32;
	}
	else
	{
		printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x %s\n", (h->h0),
			(h->h1), (h->h2), (h->h3), (h->h4), (h->h5), (h->h6), (h->h7), str);
	}
}

static void	print_3(t_info *info, t_h *h, const char *filename, const char *str)
{
	if ((info->flags & 32) == 32)
	{
		printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", str,
											    h->h0,
												h->h1,
												h->h2,
												h->h3,
												h->h4,
												h->h5,
												h->h6,
												h->h7);
		info->flags = info->flags & ~32;
	}
	else
	{
		printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", str,
		h->h0, h->h1, h->h2, h->h3, h->h4, h->h5, h->h6, h->h7);
	}
}

void	print_res_sha256(t_info *info, const char *str,  const char *filename, t_h *h)
{
 	int flag;

    flag = info->flags;
    if (ft_strcmp(str, "") == 0)
        info->flags  = info->flags | 2;
    if ((info->flags & 4) == 4)
    {
        print_1(h);
        info->flags &= ~4;
    }
    else if ((info->flags & 2) == 2)
    {
        print_1(h);
        info->flags &= ~8;
    }
    else if ((info->flags & 1) == 1)
    {
        print_2(info, h, filename, str);
    }
    else
    {
    	print_3(info, h, filename, str);
    }
    if (ft_strcmp(str, "") == 0 && (flag & 2) == 0)
        info->flags  &= ~2;
}
