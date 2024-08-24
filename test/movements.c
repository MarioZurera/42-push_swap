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

void	stack_swap(void) {
	int	t1a[6] = {0, 3, 2, 4, 1, 7};
	int	t1b[3] = {5, 8, 6};
	t_stack	a = {9, 6, (int[]){0, 3, 2, 4, 1, 7, -1, -1, -1}};
	t_stack	b = {9, 3, (int[]){5, 8, 6, -1, -1, -1, -1, -1, -1}};
	sa(&a, &b);
	swap(t1a, t1a + 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1a, a.list, a.len);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1b, b.list, b.len);
	sb(&a, &b);
	swap(t1b, t1b + 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1a, a.list, a.len);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1b, b.list, b.len);
	ss(&a, &b);
	swap(t1a, t1a + 1);
	swap(t1b, t1b + 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1a, a.list, a.len);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1b, b.list, b.len);
}

void	stack_push(void) {
	const int	ta[5] = {3, 2, 4, 1, 7};
	const int	tb[4] = {0, 5, 8, 6};
	t_stack a = {9, 6, (int[]){0, 3, 2, 4, 1, 7, -1, -1, -1}};
	t_stack b = {9, 3, (int[]){5, 8, 6, -1, -1, -1, -1, -1, -1}};
	pb(&a, &b);
	TEST_ASSERT_EQUAL_INT(5, a.len);
	TEST_ASSERT_EQUAL_INT(4, b.len);
	TEST_ASSERT_EQUAL_INT_ARRAY(ta, a.list, a.len);
	TEST_ASSERT_EQUAL_INT_ARRAY(tb, b.list, b.len);
}