#include "test_utils.h"
#include <stdio.h>

// Prototypes des fonctions de test
void	test_validate_ambient(void);
void	test_validate_light(void);
void	test_validate_camera(void);

void	run_test(const char *line, int expected, validate_func func, const char *type)
{
	int result = func((char *)line);
	if (result == expected)
		printf("Test passed for %s line: \"%s\"\n", type, line);
	else
		printf("Test failed for %s line: \"%s\" (expected %d, got %d)\n",
			type, line, expected, result);
}

int	main(void)
{
	printf("----- Tests Ambiance -----\n");
	test_validate_ambient();
	printf("\n----- Tests Lumière -----\n");
	test_validate_light();
	printf("\n----- Tests Caméra -----\n");
	test_validate_camera();
	return (0);
}
