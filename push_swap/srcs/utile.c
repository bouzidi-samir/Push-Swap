/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:41:06 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/06/30 14:58:08 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

pile    *get_bottom(pile *pile_a)
{
    pile *bottom_a;
    
    bottom_a = malloc(sizeof(*bottom_a));
    bottom_a->element = pile_a->element;

    while (bottom_a->element->next != NULL)
    {
        bottom_a->element = bottom_a->element->next;
    }
    return(bottom_a);
}

