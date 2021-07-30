/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:13:13 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/30 19:04:38 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void afficherPile(pile *pile_a)
{
    if (pile_a == NULL)
    {
        exit(EXIT_FAILURE);
    }
    element *actuel;  
    actuel = malloc(sizeof(*actuel));
    actuel = pile_a->element;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->number);
        actuel = actuel->next;
    }

    printf("\n");
    free(actuel);
}

int    init_a(int n, pile *pile_a)
{   
    element *element_a;

    element_a = malloc(sizeof(*element_a));
    if (element_a == NULL)
        return (-1);
    element_a->number = n;
    element_a->next = pile_a->element;    
    pile_a->element = element_a;
    pile_a->size++;
    return (0);    
}

void	base_sort(pile *pile_a, int *base)
{
	int	i;
	int j;
	int s;

	i = 0;
	s = 0;
	while(base[i] != '\0')
	{
		j = i + 1;
		while(base[j] != '\0')
		{
			if(base[i] > base[j])
			{
				s = base[i];
				base[i] = base[j];
				base[j] = s;
			}
			j++;
		}
		i++;
	}
	pile_a->base_size = pile_a->size;
}

void    quick_sort(pile *pile_a, pile *pile_b)
{
    int m;
    int size;
    int i;
    
    i = pile_a->base_size - 1;   
    m = pile_a->size / 5;
    size = pile_a->size - 1;
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

void    algo(pile *pile_a, pile *pile_b)
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
        under_hundred(pile_a, pile_b);
    else
        quick_sort(pile_a, pile_b);   
}

int main(int argc, char **argv)
{
    int i;
    int n;
    int j;
    pile    *pile_a;
    pile    *pile_b;   
    t_arg		arg;
    
    n = 0;
    j = 0;
    get_arg(argc, argv, &arg);
    i = args_number(argv) - 1;
    if(!check_error(argc, argv))
        return(-1);
    pile_a = malloc(sizeof(*pile_a));
    pile_b = malloc(sizeof(*pile_b));
    if(pile_a == NULL || pile_b == NULL)
        return (-1);
    pile_a->element = NULL;
    pile_b->element = NULL;
    pile_a->base = malloc(sizeof(int) * i + 1);    
    if(pile_a->base == NULL)
        return (-1);
    while (i >= 1)
    {   
       n = ft_atoi(argv[i]);
        init_a(n, pile_a);
        pile_a->base[j] = n;
        j++;
        i--;
    }
    base_sort(pile_a, pile_a->base);
    algo(pile_a, pile_b);
 // afficherPile(pile_a);
    free_arg(&arg);
    free_pile(pile_a);
    free_pile(pile_b);
    return (0);
}