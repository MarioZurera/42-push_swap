/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	copy_list(int src[], int *dest[], unsigned int size)
{
	unsigned int	i;

	if (src == NULL || size == 0)
		return (0);
	*dest = malloc(sizeof(int) * size);
	if (*dest == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		(*dest)[i] = src[i];
		i++;
	}
	return (1);
}

int	pa(const t_pair *pair)
{
	int				*temp_list;
	unsigned int	i;
	t_stack			*sa;
	t_stack			*sb;

	if (pair == NULL)
		return (0);
	sa = pair->stack_a;
	sb = pair->stack_b;
	if (!check_stack(sa) || !check_stack(sb))
		return (0);
	temp_list = malloc(sizeof(int) * (sa->size + 1));
	if (temp_list == NULL)
		return (0);
	i = 0;
	temp_list[0] = sb->list[0];
	while (++i < sa->size)
		temp_list[i] = sa->list[i];
	free(sa->list);
	sa->list = temp_list;
	if (!copy_list(sb->list + 1, &temp_list, sb->size - 1))
		return (0);
	free(sb->list);
	sb->list = temp_list;
	return (ft_printf("pa"), 1);
}

int	pb(const t_pair *pair)
{
	int				*temp_list;
	unsigned int	i;
	t_stack			*sa;
	t_stack			*sb;

	if (pair == NULL)
		return (0);
	sa = pair->stack_a;
	sb = pair->stack_b;
	if (!check_stack(sa) || !check_stack(sb))
		return (0);
	temp_list = malloc(sizeof(int) * (sb->size + 1));
	if (temp_list == NULL)
		return (0);
	i = 0;
	temp_list[0] = sa->list[0];
	while (++i < sb->size)
		temp_list[i] = sb->list[i];
	free(sb->list);
	sb->list = temp_list;
	if (!copy_list(sa->list + 1, &temp_list, sa->size - 1))
		return (0);
	free(sa->list);
	sa->list = temp_list;
	return (ft_printf("pb"), 1);
}