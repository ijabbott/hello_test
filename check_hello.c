#include <stdlib.h>
#include <check.h>
#include "hello_world.h"

START_TEST(test_say_hello)
{
	char *s = say_hello();
	ck_assert_str_eq(s, "hello");
}
END_TEST

Suite * hello_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Hello");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_say_hello);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = hello_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
