#include "test_utils.h"
#include <stdio.h>
#include <unistd.h> // Pour la fonction sleep

// Prototypes des fonctions de test
void	test_validate_ambient(void);
void	test_validate_light(void);
void	test_validate_camera(void);
void	test_validate_plane(void);
void	test_validate_cylinder(void);
void	test_validate_sphere(void);

static int total_tests = 0;
static int passed_tests = 0;

#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

void	print_test_result(const char *type, const char *line, int expected, int result)
{
	if (result == expected)
	{
		passed_tests++;
		printf(GREEN_TEXT "✔ Test passed" RESET_TEXT " for %s line: \"%s\"\n", type, line);
	}
	else
	{
		printf(RED_TEXT "✘ Test failed" RESET_TEXT " for %s line: \"%s\" (expected %d, got %d)\n",
			type, line, expected, result);
	}
}

void	run_test(const char *line, int expected, validate_func func, const char *type)
{
	int	result = func((char *)line);
	total_tests++;
	print_test_result(type, line, expected, result);
	/* usleep(50000); // Pause de 50ms pour l'animation */
}

void	print_summary(void)
{
	printf("\n----- Test Summary -----\n");
	printf("Total tests: %d\n", total_tests);
	printf("Passed tests: %d\n", passed_tests);
	printf("Failed tests: %d\n", total_tests - passed_tests);
	if (passed_tests == total_tests)
		printf(GREEN_TEXT "All tests passed!" RESET_TEXT "\n\n");
	else
		printf(RED_TEXT "Some tests failed." RESET_TEXT "\n\n");
}

int	main(void)
{
	printf("----- Tests Ambiance -----\n");
	test_validate_ambient();
	printf("\n----- Tests Lumière -----\n");
	test_validate_light();
	printf("\n----- Tests Caméra -----\n");
	test_validate_camera();
	printf("\n----- Tests Plan -----\n");
	test_validate_plane();
	printf("\n----- Tests Cylindre -----\n");
	test_validate_cylinder();
	printf("\n----- Tests Sphère -----\n");
	test_validate_sphere();
	print_summary();
	return (0);
}
