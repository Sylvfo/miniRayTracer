#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype de la fonction à tester
int	validate_ambient(char *line);

void	run_test(char *line, int expected)
{
	int	result = validate_ambient(line);
	if (result == expected)
		printf("Test passed for line: \"%s\"\n", line);
	else
		printf("Test failed for line: \"%s\" (expected %d, got %d)\n", line, expected, result);
}

int	main(void)
{
	// Cas de test valides
	run_test("A 0.2 255,255,255", 1);
	run_test("A 0.5 100,100,100", 1);
	run_test("A 1.0 0,0,0", 1);

	// Cas de test invalides
	run_test("A 1.2 255,255,255", 0); // Ratio invalide
	run_test("A 0.5 256,100,100", 0); // Valeur de couleur invalide
	run_test("A 0.5 100,100", 0); // Format de couleur invalide
	run_test("B 0.5 100,100,100", 0); // Type invalide
	run_test("A 0.5 100,100,100,100", 0); // Trop de valeurs de couleur

	return 0;
}
