/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:57:08 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/30 18:19:24 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_top(pile *pile_a)
{
	if (pile_a->rank_f > 1)
	{
		if (pile_a->rank_f <= pile_a->size / 2)
		{
			while (pile_a->rank_f > 1)
			{
				rotate(pile_a, 'a');
				pile_a->rank_f--;
			}
		}
		if (pile_a->rank_f > pile_a->size / 2)
		{
			while (pile_a->rank_f + 1 > 1)
			{	
				reverse_rotate(pile_a, 'a');
				pile_a->rank_f--;
			}
		}
	}
}

void	push_from_bottom(pile *pile_a)
{
	int	i;

	i = pile_a->size - pile_a->rank_s;
	if (pile_a->rank_s >= pile_a->size / 2)
	{
		while (i > 0)
		{
			reverse_rotate(pile_a, 'a');
			i--;
		}
	}
	if (pile_a->rank_s < pile_a->size / 2)
	{
		while (pile_a->rank_s)
		{
			rotate(pile_a, 'a');
			pile_a->rank_s--;
		}
	}
}

int	push_smaller(pile *pile_a, pile *pile_b, int m)
{
	int	b;
	int	b1;

	b = 0;
	b1 = 0;
	if (pile_a->rank_f <= pile_a->bottom)
	{
		if (pile_a->hold_first->element->number < m)
			push_from_top(pile_a);
	}
	if (pile_a->bottom < pile_a->rank_f)
	{
		if (pile_a->hold_second->element->number < m)
			push_from_bottom(pile_a);
	}
	push_to_b(pile_b, pile_a);
	return (0);
}

void	get_closer(pile *pile_a, int m)
{
	pile	*temp;

	temp = malloc(sizeof(*temp));
	while (pile_a->hold_first->element != NULL)
	{
		if (pile_a->hold_first->element->number < m)
			break ;
		pile_a->hold_first->element = pile_a->hold_first->element->next;
		pile_a->rank_f++;
	}
	while (pile_a->hold_second->element != pile_a->element)
	{
		temp->element = pile_a->element;
		if (pile_a->hold_second->element->number < m)
			break ;
		while (temp->element->next != pile_a->hold_second->element)
		{
			temp->element = temp->element->next;
			pile_a->rank_s--;
		}
		pile_a->hold_second->element = temp->element;
		pile_a->bottom++;
	}
	free(temp);
}

int	sort_a(pile *pile_a, pile *pile_b, int m)
{
	pile_a->rank_f = 1;
	pile_a->bottom = 1;
	pile_a->hold_first = malloc(sizeof(pile_a->hold_first));
	if (pile_a->size == 1)
	{
		push_to_b(pile_b, pile_a);
		return (0);
	}
	if (pile_a->hold_first == NULL)
		return (-1);
	pile_a->hold_first->element = pile_a->element;
	pile_a->hold_second = get_bottom(pile_a);
	get_closer(pile_a, m);
	pile_a->rank_s = pile_a->size - pile_a->bottom;
	if (pile_a->hold_first->element == NULL)
	{
		pile_a->hold_second = NULL;
		pile_a->hold_first = NULL;
		free(pile_a->hold_second);
		free(pile_a->hold_first);
		return (0);
	}
	push_smaller(pile_a, pile_b, m);
	sort_a(pile_a, pile_b, m);
	return (0);
}
