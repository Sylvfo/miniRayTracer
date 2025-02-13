// langage: C
// langage: C
#include "test_utils.h"

int	validate_light(char *line);

void	test_validate_light(void)
{
	// Cas de test valides
	run_test("L 0,0,0 0.5 255,255,255", 1, validate_light, "light");
	run_test("L 10,20,30 1.0 0,0,0", 1, validate_light, "light");
	run_test("L -5.5,3.2,7 0.0 100,150,200", 1, validate_light, "light");
	// Cas de test invalides
	run_test("L 0,0 0.5 255,255,255", 0, validate_light, "light");
	run_test("L 0,0,0 1.5 255,255,255", 0, validate_light, "light");
	run_test("L 0,0,0 0.5 256,10,10", 0, validate_light, "light");
	run_test("M 0,0,0 0.5 255,255,255", 0, validate_light, "light");
}
