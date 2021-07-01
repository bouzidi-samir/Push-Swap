/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:28:01 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/01 14:34:04 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  element
{
    int number;
    struct element *next;    
}   element;

typedef struct  pile
{
    struct element *element;
    int size;
}   pile;

int     check_error(int argc, char **argv);
int     check_number(int argc, char **argv);
int     check_double(int argc, char **argv);
int     check_difference(char *str, char *s);
int     init_a(int n, pile *pile_a);
int    rotate(pile *pile_a);
int    reverse_rotate(pile *pile_a);
int    swap(pile *pile_a);
int    push_to_a(pile *pile_a, pile *pile_b);
int    push_to_b(pile *pile_b, pile *pile_a);
void    algo(pile *pile_a);
void    two_numbers(pile *pile_a);
void    three_numbers(pile *pile_a);
pile    *get_bottom(pile *pile_a);


#endif