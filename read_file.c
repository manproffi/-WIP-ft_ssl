/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:40:40 by sprotsen          #+#    #+#             */
/*   Updated: 2018/07/20 19:40:43 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "head_ssl.h"

void    read_file_last(t_info *info, int fd, const char *filename)
{
    char	buffer[101];
    char    *input_str;
    char    *tmp;
    size_t  i;

    input_str = (char*)malloc(sizeof(char) * 1);
    input_str[0] = '\0';
    while ((i = read(fd, &buffer, 100)) > 0)
    {
        buffer[i] = '\0';
        tmp = input_str;
        input_str = ft_strjoin(tmp,buffer);
        ft_strdel(&tmp);
    }
//    printf("%s\n", input_str);
    md5_algo(info, input_str, filename);
    ft_strdel(&input_str);
}

void   read_file_next(t_info *info, const char *name)
{
    int     fd;
    char    *error;

    fd = open(name, O_RDONLY);
    if (fd < 0)
    {
        error = ft_strjoin("ft_ssl: ", name);
        perror(error);
        ft_strdel(&error);
    }
    if (info->validation_flag == 0)
        read_file_last(info, fd, name);

    close(fd);
}


char *take_filename(const char *name)
{
    struct stat p_stat;
    int		len_symlink_name;
    char	buffer[256];

    lstat(name, &p_stat);

//    printf("%d\n", S_ISBLK(p_stat.st_mode));
//    printf("%d\n", S_ISCHR(p_stat.st_mode));
//    printf("%d\n", S_ISDIR(p_stat.st_mode));
//    printf("%d\n", S_ISFIFO(p_stat.st_mode));
//    printf("%d\n", S_ISREG(p_stat.st_mode));
//    printf("%d\n", S_ISLNK(p_stat.st_mode));
//    printf("%d\n", S_ISSOCK(p_stat.st_mode));

    if (S_ISLNK(p_stat.st_mode))
    {
        len_symlink_name = readlink(name, buffer, 256);
        buffer[len_symlink_name] = '\0';
        return (take_filename(buffer));
    }
    if (S_ISDIR(p_stat.st_mode))
        return NULL;
    if (S_ISREG(p_stat.st_mode))
        return ft_strdup(name);
    return NULL;
}

void    read_file(t_info *info, const char *name)
{
    char *error;
    char *res;

    error = NULL;
    if (access(name, F_OK) != -1)
    {
        res = take_filename(name);
        if (!res)
            printf("ft_ssl: %s: Is a directory\n", name);
        else
            read_file_next(info, res);
        ft_strdel(&res);
    }
    else
    {
        error = ft_strjoin("ft_ssl: ", name);
        perror(error);
        ft_strdel(&error);
    }
}
