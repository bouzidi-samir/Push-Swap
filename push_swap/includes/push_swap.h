/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:28:01 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/06 18:54:25 by samirbouzid      ###   ########.fr       */
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
    int rank;
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
int    rotate(pile *pile_a, char c);
int    reverse_rotate(pile *pile_a, char c);
int    swap(pile *pile_a, char c);
int    push_to_a(pile *pile_a, pile *pile_b);
int    push_to_b(pile *pile_b, pile *pile_a);
void    algo(pile *pile_a, pile *pile_b);
void    two_numbers(pile *pile_a);
void    three_numbers(pile *pile_a);
void    under_hundred(pile *pile_a, pile *pile_b);
pile    *get_bottom(pile *pile_a);


#endif