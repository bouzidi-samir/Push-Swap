/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:13:13 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/04 18:26:46 by samirbouzid      ###   ########.fr       */
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

int    under_hundred(pile *pile_a, pile *pile_b)
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
        if(bottom == NULL)
            return (-1);
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
    return (0);
}

void    quick_sort(pile *pile_a, pile *pile_b, int d)
{
    int m;
    int size;
    int i;
    int	r;
	
    i = pile_a->base_size - 1;   
    m = pile_a->size / d;
    size = pile_a->size - 1;
    r = 1;
	while(pile_a->size > 3)
        {
            while(r < d)
			{
				sort_a(pile_a, pile_b, pile_a->base[m * r]);
				r++;
			}
			sort_a(pile_a, pile_b, pile_a->base[size]);
        }
        while(i >= 0)
        {    
            sort_b(pile_a, pile_b, i);    
            i--;
        }
        push_to_a(pile_a, pile_b);
}

void    push_swap(pile *pile_a, pile *pile_b)
{   
    int f;
    int s;
    
    f = pile_a->element->number;
    s = pile_a->element->next->number;
    if(pile_a->size < 3)
    {
        if(f > s) 
            swap(pile_a, 'a');    
    }    
    if (pile_a->size == 3)
        three_numbers(pile_a);
    if (pile_a->size == 5 || pile_a->size == 4)
        sort_five(pile_a, pile_b);
    if (pile_a->size > 5 && pile_a->size < 500)
       quick_sort(pile_a, pile_b, 5);      
    if (pile_a->base_size >= 500) 
        quick_sort(pile_a, pile_b, 11);              
}
