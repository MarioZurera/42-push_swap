/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:45:16 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:18:54 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testing.h"

void	stack_invalid_input(void)
{
	t_stack *result;

	result = tokenize_numbers(3, (char *[]){"", "", ""});
	TEST_ASSERT_NULL(result);
	result = tokenize_numbers(4, (char *[]){"", "     ", "           ", ""});
	TEST_ASSERT_NULL(result);
	result = tokenize_numbers(10, (char *[]){"", "\r\t\n\r\v \f \n\n\n\t\r \v\v\f \n\n\n\t\r\v \v\f  \n\t\n\r\v\f		\n\t\n\r\v\f \n\n\n\t\r\v \v\f\n\t\n\r\v\f \n\n\n\t\r\v\v\f\n \r"});
	TEST_ASSERT_NULL(result);
	result = tokenize_numbers(6, (char *[]){"", "\t1\t", "2", "\n3", "\rfour", "\v5"});
	TEST_ASSERT_NULL(result);
	result = tokenize_numbers(3, (char *[]){"", "1234567890", "09876543210"});
	TEST_ASSERT_NULL(result);
	result = tokenize_numbers(2, (char *[]){"", "2147483647 2147483648"});
	TEST_ASSERT_NULL(result);
	result = tokenize_numbers(2, (char *[]){"", "-2147483648 -2147483649"});
	TEST_ASSERT_NULL(result);
}

void	stack_valid_input(void) {
	t_stack *result;

	const int	t1[4] = {1, 2, 3, 42};
	result = tokenize_numbers(5, (char*[]){"", "1", "2", "3", "42"});
	TEST_ASSERT_EQUAL_INT(4, result->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1, result->list, 4);
	free(result);

	const int	t2[6] = {10, -10, 9, -9, 10, -10};
	result = tokenize_numbers(2, (char*[]){"", "10 -10 9 -9 10 -10"});
	TEST_ASSERT_EQUAL_INT(6, result->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(t2, result->list, 6);
	free(result);

	const int	t3[2] = {INT_MAX, INT_MAX - 1};
	result = tokenize_numbers(2, (char*[]){"", "2147483647 2147483646"});
	TEST_ASSERT_EQUAL_INT(2, result->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(t3, result->list, 2);
	free(result);

	const int	t4[2] = {INT_MIN, INT_MIN + 1};
	result = tokenize_numbers(3, (char*[]){"", "-2147483648", "-2147483647"});
	TEST_ASSERT_EQUAL_INT(2, result->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(t4, result->list, 2);
	free(result);

	const int	t5[5] = {INT_MAX, INT_MIN, 0, INT_MAX - 1, INT_MIN + 1};
	result = tokenize_numbers(6, (char*[]){"", "2147483647", "-2147483648", "0", "2147483646", "-2147483647"});
	TEST_ASSERT_EQUAL_INT(5, result->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(t5, result->list, 5);
	free(result);
}

void	stack_with_repetitions(void) {
	t_stack *result;

	result = parse_numbers(tokenize_numbers(7, (char *[]){"", "-1", "1", "2", "3", "zero", "-1"}));
	TEST_ASSERT_NULL(result);
	result = parse_numbers(tokenize_numbers(7, (char *[]){"", "-1", "1", "2", "3", "0", "-1"}));
	TEST_ASSERT_NULL(result);

}

void	stack_without_repetitions(void) {
	t_stack *result;
	const int t1[6] = {1, 3, 4, 5, 2, 0};
	result = parse_numbers(tokenize_numbers(7, (char *[]){"", "-1", "1", "2", "3", "0", "-2"}));
	TEST_ASSERT_EQUAL_INT(6, result->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(t1, result->list, 6);
}