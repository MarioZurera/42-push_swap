#include "unity.h"
#include "push_swap.h"

void setUp(void) {}

void tearDown(void) {}

static int add(int a, int b) { return a + b; }

static void test_Addition(void) {
	TEST_ASSERT_EQUAL(30, add(10, 20));
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	UNITY_BEGIN();
	RUN_TEST(test_Addition);
	return UNITY_END();
}
