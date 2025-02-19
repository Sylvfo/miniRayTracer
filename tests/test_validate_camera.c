#include "test_utils.h"

int	validate_camera(char *line);

void	test_validate_camera(void)
{
	// Cas de test valides
	run_test("C -50.0,0,20 0,0,1 70", 0, validate_camera, "camera");
	run_test("C 10,10,10 0,1,0 90", 0, validate_camera, "camera");
	run_test("C 0,0,0 1,0,0 45", 0, validate_camera, "camera");
	run_test("C 1,1,1 0,0,1 60", 0, validate_camera, "camera");
	run_test("C -1,-1,-1 -1,0,0 30", 0, validate_camera, "camera");
	run_test("C 0,0,0 0,1,0 75", 0, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 90", 0, validate_camera, "camera");
	run_test("C 0,0,0 1,1,1 120", 0, validate_camera, "camera");

	// Cas de test invalides
	run_test("C -50.0,0 0,0,1 70", 1, validate_camera, "camera");
	run_test("C -50.0,0,20 2,0,0 70", 1, validate_camera, "camera");
	run_test("C -50.0,0,20 0,0,1 190", 1, validate_camera, "camera");
	run_test("D -50.0,0,20 0,0,1 70", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,2 45", 1, validate_camera, "camera");
	run_test("C 0,0,0 1,1,1 200", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,0 75", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 0", 1, validate_camera, "camera");
	run_test("C 0,0,0 1,1,1 181", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 -10", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 190", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 200", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 210", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 220", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 230", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 240", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 250", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 260", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 270", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 280", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 290", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 300", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 310", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 320", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 330", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 340", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 350", 1, validate_camera, "camera");
	run_test("C 0,0,0 0,0,1 360", 1, validate_camera, "camera");
}