/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:47:09 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/07/07 22:56:55 by samirbouzid      ###   ########.fr       */
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
        swap(pile_a, 'a');
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
       swap(pile_a, 'a');
    }
    if(f > s && s > b)
    {
        swap(pile_a, 'a');
        reverse_rotate(pile_a, 'a'); 
    }
    if(f > s && s < b && f > b)
        rotate(pile_a, 'a'); 
    if(f < s && s > b && f > b)
        reverse_rotate(pile_a, 'a'); 
    if(f < s && s > b && f < b)
    {
        swap(pile_a, 'a');
        rotate(pile_a, 'a'); 
    }
}

void    under_hundred(pile *pile_a, pile *pile_b)
{
    int f;
    int s;
    pile *bottom;
    int size;
    
    f = pile_a->element->number;
    s = pile_a->element->next->number;
    size = 0;
    while(pile_a->size > 3)    
    {
        push_to_b(pile_b, pile_a);
        size++;
    }
    three_numbers(pile_a);
    while (size > 0)
    {  
        push_to_a(pile_a, pile_b);   
        size--;
        bottom = get_bottom(pile_a);  
        if(pile_a->element->number > bottom->element->number) 
            rotate(pile_a, 'a');
            while(pile_a->element->number > pile_a->element->next->number )
            { 
                swap(pile_a, 'a');
                push_to_b(pile_b, pile_a);
                size++;
            }
    }
    free(bottom);
}

void    algo(pile *pile_a, pile *pile_b)
{
    if(pile_a->size < 3)
        two_numbers(pile_a);
    if (pile_a->size == 3)
        three_numbers(pile_a);
    if (pile_a->size > 3)
        under_hundred(pile_a, pile_b);

}