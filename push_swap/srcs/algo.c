/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:47:09 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/07/30 18:41:13 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_numbers(pile *pile_a)
{
    int f;
    int s;
    int b;

    f = pile_a->element->number;
    s = pile_a->element->next->number;
    b = pile_a->element->next->next->number;
    if(f > s && s < b && f < b)
       swap(pile_a, 'a');
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

int    sort_b(pile *pile_a, pile *pile_b, int i)
{
 //   int i;
    
//    i = pile_a->base_size - 1;
    pile_b->rank_f = 1;
   // pile_b->upper = malloc(sizeof(*pile_b->upper));
    //if(pile_b->upper == NULL)
      //  return (-1);
    pile_b->upper = pile_b->element;
    while(pile_b->size > 1)
    {                  
        if(pile_b->upper->number == pile_a->base[i])
        {
            push_upper(pile_a, pile_b);     
            return(0);
        }
        pile_b->upper = pile_b->upper->next;
        pile_b->rank_f++;
    }
    return (0);
}

void    push_upper(pile *pile_a, pile *pile_b)
{
    int bottom;

    bottom = pile_b->size - pile_b->rank_f;
    if(pile_b->rank_f <= pile_b->size / 2)
    {
        while(pile_b->rank_f > 1)
        {
            rotate(pile_b, 'b');
            pile_b->rank_f--;
        }
    }
    else if(pile_b->rank_f > pile_b->size / 2)
    {
        while(bottom + 1 > 0)
        {
            reverse_rotate(pile_b, 'b');
            bottom--;
        }
    }
    push_to_a(pile_a, pile_b);
}

int before_pb(pile *pile_a, pile *pile_b)
{
    int fb;
    int sb;
    int fa;
    int sa;
    
    fb = pile_b->element->number;
    sb = pile_b->element->next->number;
    fa = pile_a->element->number;
    sa = pile_a->element->next->number;
    if (pile_b->size < 2 || pile_a->size < 2)
       return (0);
    if(fa < sa && pile_a->size >= 2)
        swap(pile_a, 'a');
    if(fb < sb)
        swap(pile_b, 'b');
   return (0); 
}