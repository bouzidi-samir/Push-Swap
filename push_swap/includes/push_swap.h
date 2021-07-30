/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:28:01 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/30 18:08:44 by samirbouzid      ###   ########.fr       */
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
    int *base;
    struct pile    *hold_first;
    struct pile    *hold_second;
    struct element *upper;
    int rank_f;
    int rank_s;
    int base_size;
    int bottom;
}   pile;

typedef struct	t_arg
{
	int			ac;
	char		**av;
}	t_arg;

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
int     args_number(char **arg);
void    algo(pile *pile_a, pile *pile_b);
void    two_numbers(pile *pile_a);
void    three_numbers(pile *pile_a);
void    under_hundred(pile *pile_a, pile *pile_b);
void	get_arg(int argc, char **argv, t_arg *arg);
void	free_arg(t_arg *arg);
pile    *get_bottom(pile *pile_a);
void	free_pile(pile *pile_a);
int    sort_a(pile *pile_a, pile *pile_b, int m);
void	base_sort(pile *pile_a, int *base);
void    quick_sort(pile *pile_a, pile *pile_b);
int    push_smaller(pile *pile_a, pile *pile_b, int m);
void    push_from_top(pile *pile_a);
void    push_from_bottom(pile *pile_a);
int    before_pb(pile *pile_a, pile *pile_b);
int    sort_b(pile *pile_a, pile *pile_b, int i);
void    push_upper(pile *pile_a, pile *pile_b);
void    get_closer(pile *pile_a, int m);

#endif