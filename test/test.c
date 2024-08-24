/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:43:05 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_testing.h"

void setUp(void) {}

void tearDown(void) {}

static void run_stack_tests(void) {
	TEST_MESSAGE("Test Stack");
	RUN_TEST(stack_invalid_input);
	RUN_TEST(stack_valid_input);
	RUN_TEST(stack_with_repetitions);
	RUN_TEST(stack_without_repetitions);
}

static void run_movement_tests(void) {
	TEST_MESSAGE("Test Movements");
	RUN_TEST(stack_swap);
	RUN_TEST(stack_push);
	RUN_TEST(stack_rotate);
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	UNITY_BEGIN();
	run_stack_tests();
	run_movement_tests();
	return (UNITY_END());
}
