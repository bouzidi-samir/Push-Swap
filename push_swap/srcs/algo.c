/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:47:09 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/07/30 15:46:01 by samirbouzid      ###   ########.fr       */
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

void    push_from_top(pile *pile_a)
{
    if(pile_a->rank_f > 1)
    {
        if (pile_a->rank_f <= pile_a->size / 2)
        {
            while(pile_a->rank_f > 1)
            {
                rotate(pile_a, 'a');
                pile_a->rank_f--;
            }
        }       
        if (pile_a->rank_f > pile_a->size / 2)
        {
            while(pile_a->rank_f + 1 > 1)
            {
                reverse_rotate(pile_a, 'a');
                pile_a->rank_f--;
            }
        }    
    }
}

void    push_from_bottom(pile *pile_a)
{
    int i;

    i = pile_a->size - pile_a->rank_s;
    if (pile_a->rank_s >= pile_a->size / 2)
    {
        while(i > 0)
        {
            reverse_rotate(pile_a, 'a');
            i--;
        }
    }    
    if (pile_a->rank_s < pile_a->size / 2)
    {
        while(pile_a->rank_s)
        {
            rotate(pile_a, 'a');
            pile_a->rank_s--;
        }
    }    
}

int    push_smaller(pile *pile_a, pile *pile_b, int m)
{
    int b;
    int b1;

    b = 0;
    b1 = 0;
    if(pile_a->rank_f <= pile_a->bottom)
    {
        if(pile_a->hold_first->element->number < m)
            push_from_top(pile_a);
    }
    if(pile_a->bottom < pile_a->rank_f)
    {
        if(pile_a->hold_second->element->number < m )
            push_from_bottom(pile_a);
    }
     //before_pb(pile_a, pile_b);
    push_to_b(pile_b, pile_a);
    return (0);
}

int    sort_a(pile *pile_a, pile *pile_b, int m)
{   
    pile    *temp;
    pile_a->rank_f = 1;
    pile_a->bottom = 1; 
    pile_a->hold_first = malloc(sizeof(pile_a->hold_first));
    if(pile_a->size == 1)
    {
        push_to_b(pile_b, pile_a);
        return (0);
    }
    if (pile_a->hold_first == NULL)
        return (-1);
    pile_a->hold_first->element = pile_a->element;
    pile_a->hold_second = get_bottom(pile_a);
    temp = malloc(sizeof(*temp));   
    while(pile_a->hold_first->element != NULL)
    {
        if(pile_a->hold_first->element->number < m)
            break;
        pile_a->hold_first->element = pile_a->hold_first->element->next;
        pile_a->rank_f++;
    }
    while(pile_a->hold_second->element != pile_a->element)
    {
         temp->element = pile_a->element;
        if(pile_a->hold_second->element->number < m)
            break;
        while (temp->element->next != pile_a->hold_second->element)
        {
            temp->element = temp->element->next;
            pile_a->rank_s--;
        }       
        pile_a->hold_second->element = temp->element;
        pile_a->bottom++;
    }     
   pile_a->rank_s = pile_a->size - pile_a->bottom; 
 //  printf("%d", pile_a->bottom);
  
    if(pile_a->hold_first->element == NULL)
    {       
        temp = NULL;
        pile_a->hold_second = NULL;
        pile_a->hold_first = NULL;
        free(temp);
        free(pile_a->hold_second);
        free(pile_a->hold_first);
        return (0);
    }    
    push_smaller(pile_a, pile_b, m);
   sort_a(pile_a, pile_b, m);
    return (0);
}

void    algo(pile *pile_a, pile *pile_b)
{
    int m;
    int size;
    int i;
    
    i = pile_a->base_size - 1;   
    m = pile_a->size / 5;
    size = pile_a->size - 1;
    if(pile_a->size < 3)
        two_numbers(pile_a);
    if (pile_a->size == 3)
        three_numbers(pile_a);
    if (pile_a->size <= 5)
        under_hundred(pile_a, pile_b);
    //if (pile_a->size > 99)
    else
    {
        while(pile_a->size > 3)
        {
            sort_a(pile_a, pile_b, m);
            sort_a(pile_a, pile_b, pile_a->base[m * 2]);
            sort_a(pile_a, pile_b, pile_a->base[m * 3]);
            sort_a(pile_a, pile_b, pile_a->base[m * 4]);
            sort_a(pile_a, pile_b, pile_a->base[size]);
        }
        while(i >= 0)
        {    
            sort_b(pile_a, pile_b, i);    
            i--;
        }
        push_to_a(pile_a, pile_b);
    }
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