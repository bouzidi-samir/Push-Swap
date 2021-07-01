/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:47:09 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/07/01 14:57:50 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    two_numbers(pile *pile_a)
{
    int f;
    int s;
    
    f = pile_a->element->number;
    s = pile_a->element->next->number;
    if(f > s) 
    {
        swap(pile_a);
        write(1,"sa", 2);
        write(1,"\n", 1);
    }
}

void    three_numbers(pile *pile_a)
{
    int f;
    int s;
    int b;

    f = pile_a->element->number;
    s = pile_a->element->next->number;
    b = pile_a->element->next->next->number;
    if(f > s && s < b && f < b)
    {
       two_numbers(pile_a);
    }
    if(f > s && s > b)
    {
        two_numbers(pile_a);
        reverse_rotate(pile_a); 
        write(1,"rra", 2);
        write(1,"\n", 1);
    }
    if(f > s && s < b && f > b)
    {
        rotate(pile_a); 
        write(1,"ra", 2);
        write(1,"\n", 1);
    }
}

void    algo(pile *pile_a)
{
    if(pile_a->size < 3)
        two_numbers(pile_a);
    if (pile_a->size)
        three_numbers(pile_a);
    


}