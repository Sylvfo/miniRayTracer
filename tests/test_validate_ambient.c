// langage: C
#include "test_utils.h"

// Prototype de la fonction à tester (définie dans srcs/parsing/parse.c)
int	validate_ambient(char *line);

void	test_validate_ambient(void)
{
	// Cas de test valides
	run_test("A 0.2 255,255,255", 1, validate_ambient, "ambient");
	run_test("A 0.5 100,100,100", 1, validate_ambient, "ambient");
	run_test("A 1.0 0,0,0", 1, validate_ambient, "ambient");
	run_test("A 0.5 100,100,100  ", 1, validate_ambient, "ambient");
	// Cas de test invalides
	run_test("A 1.2 255,255,255", 0, validate_ambient, "ambient");
	run_test("A 0.5 256,100,100", 0, validate_ambient, "ambient");
	run_test("A 0.5 100,100", 0, validate_ambient, "ambient");
	run_test("B 0.5 100,100,100", 0, validate_ambient, "ambient");
	run_test("A 0.5 100,100,100,100", 0, validate_ambient, "ambient");
	run_test("A 0.5 100,100,100,", 0, validate_ambient, "ambient");
	run_test("A 0.5 ", 0, validate_ambient, "ambient");
	run_test("A", 0, validate_ambient, "ambient");
}
