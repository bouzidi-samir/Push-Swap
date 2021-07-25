/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:58:21 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/18 16:27:35 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_difference(char *str, char *s)
{
    int i;
    int o;

    i = 0;
    o = 0;
        
    
        while (s[i] || str[i])
        {
            if (str[i] != s[i])
                return (1);
            i++;
        }
    
        return (0);
}

int check_double(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    while (i <= argc - 1)    
    {
        j = i + 1;    
        while (j <= argc - 1)
        {
            if(!check_difference(argv[i], argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_number(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i <= argc - 1)
    {
        j = 0;
        while(argv[i][j] != '\0')
        {
            if (!ft_isdigit((int)argv[i][j]))
                return (0);
            j++;
        }
       i++;
    }
    return (1);
}

int check_error(int argc, char **argv)
{
    if(!check_number(argc, argv))
    {
        write(2, "Error", 6);
        write(2, "\n", 1);
        return (0);
    }
    if (argc < 3 || check_double(argc, argv) )    
    {
        write(2, "Error", 6);
        write(2, "\n", 1);
        return (0);
    }
    return (1);
}