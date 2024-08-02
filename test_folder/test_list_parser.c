/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:45:16 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 20:35:56 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testing.h"

void	test_list_parser(void)
{
   	ft_printf(B"================= TESTING LIST PARSER ===============\n"NC);
	START_TEST("Empty List:");
	ASSERT(parse_numbers(3, (char*[]){"", "", ""}) == NULL);
	ASSERT(parse_numbers(3, (char*[]){"", "", " "}) == NULL);
	ASSERT(parse_numbers(4, (char*[]){"", "     ", "           ", ""}) == NULL);
	ASSERT(parse_numbers(4, (char*[]){"", "\t\n\r", "\v\f", " \n\n\n\t   \r\v\v\f\n"}) == NULL);
	ASSERT(parse_numbers(10, (char*[]){"", "\r\t\n\r\v", "\f \n\n\n\t\r", "\v\v\f", "\n\n\n\t\r\v", "\v\f", "", "\n\t\n\r\v\f		\n\t\n\r\v\f \n\n\n\t\r\v", "\v\f\n\t\n\r\v\f \n\n\n\t\r\v\v\f\n", "\r"}) == NULL);
	END_TEST();


	START_TEST("Invalid List:");
	ASSERT(parse_numbers(5, (char*[]){"", "1", "two", "3", "4"}) == NULL);
	ASSERT(parse_numbers(6, (char*[]){"", "\t1\t", "2", "\n3", "\rfour", "\v5"}) == NULL);
	ASSERT(parse_numbers(3, (char*[]){"", "42b42", "42"}) == NULL);
	ASSERT(parse_numbers(3, (char*[]){"", "42b", "42"}) == NULL);
	ASSERT(parse_numbers(3, (char*[]){"", "42", "b42"}) == NULL);
	END_TEST();


	START_TEST("Simple List:");
    {
		t_stack s = {4, (int []){1, 2, 3, 42}};
		t_stack *result = parse_numbers(5, (char*[]){"", "1", "2", "3", "42"});
		assert_stack(result, &s);
    }
    {
		t_stack s = {6, (int []){1, 2, 3, 4, 5, 6}};
		t_stack *result = parse_numbers(7, (char*[]){"", "\t1", "\t2\n", "3\r", "4", "\v5\f", "6\t"});
		assert_stack(result, &s);

    }
    {
		t_stack s = {6, (int []){10, -10, 9, -9, 10, -10}};
		t_stack *result = parse_numbers(7, (char*[]){"", "10",  "-10", "9", "-9", "10", "-10"});
		assert_stack(result, &s);
    }
	END_TEST();

	ft_printf(B"=================== END LIST PARSER =================\n"NC);
}