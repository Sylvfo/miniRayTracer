// langage: C
#include "test_utils.h"

int	validate_camera(char *line);

void	test_validate_camera(void)
{
	// Cas de test valides
	run_test("C -50.0,0,20 0,0,1 70", 1, validate_camera, "camera");
	run_test("C 10,10,10 0,1,0 90", 1, validate_camera, "camera");
	// Cas de test invalides
	run_test("C -50.0,0 0,0,1 70", 0, validate_camera, "camera");
	run_test("C -50.0,0,20 2,0,0 70", 0, validate_camera, "camera");
	run_test("C -50.0,0,20 0,0,1 190", 0, validate_camera, "camera");
	run_test("D -50.0,0,20 0,0,1 70", 0, validate_camera, "camera");
}
