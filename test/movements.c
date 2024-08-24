/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testing.h"

static void swap(int *a, int *b) {
	const int temp = *a;
	*a = *b;
	*b = temp;
}

static int *copy_list(int nums[], unsigned int size) {
	int *new_list = (int *)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		new_list[i] = nums[i];
	}
	return (new_list);
}

void	stack_swap(void) {
	int	t1a[6] = {0, 3, 2, 4, 1, 7};
	int	t1b[3] = {5, 8, 6};
	t_stack	a = {9, 6, (int[]){0, 3, 2, 4, 1, 7, -1, -1, -1}};
	t_stack	b = {9, 3, (int[]){5, 8, 6, -1, -1, -1, -1, -1, -1}};
	sa(a, b);
	swap(t1a, t1a + 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(a.list, t1a, a.size);
	TEST_ASSERT_EQUAL_INT_ARRAY(b.list, t1b, b.size);
	sb(a, b);
	swap(t1b, t1b + 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(a.list, t1a, a.size);
	TEST_ASSERT_EQUAL_INT_ARRAY(b.list, t1b, b.size);
	ss(a, b);
	swap(t1a, t1a + 1);
	swap(t1b, t1b + 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(a.list, t1a, a.size);
	TEST_ASSERT_EQUAL_INT_ARRAY(b.list, t1b, b.size);
}

void	stack_push(void) {
	const int	t1a[5] = {3, 2, 4, 1, 7};
	const int	t1b[4] = {0, 5, 8, 6};
	const t_stack a1 = {9, 6, (int[]){0, 3, 2, 4, 1, 7, -1, -1, -1}};
	const t_stack b1 = {9, 3, (int[]){5, 8, 6, -1, -1, -1, -1, -1, -1}};
	pa(a1, b1);
	TEST_ASSERT_EQUAL_INT_ARRAY(a1.list, t1a, a1.len);
	TEST_ASSERT_EQUAL_INT_ARRAY(b1.list, t1b, b1.len);
}