#include "test_utils.h"

int	validate_sphere(char *line);

void	test_validate_sphere(void)
{
	// Valid test cases
	run_test("sp 0.0,0.0,20.6 12.6 10,0,255", 0, validate_sphere, "sphere");
	run_test("sp 1.0,1.0,1.0 5.0 255,255,255", 0, validate_sphere, "sphere");
	run_test("sp -1.0,-1.0,-1.0 1.0 0,0,0", 0, validate_sphere, "sphere");

	// Invalid test cases
	run_test("sp 0.0,0.0,20.6 12.6 10,0,256", 1, validate_sphere, "sphere"); // Invalid color value
	run_test("sp 0.0,0.0,20.6 12.6", 1, validate_sphere, "sphere"); // Missing color
	run_test("sp 0.0,0.0,20.6 -12.6 10,0,255", 1, validate_sphere, "sphere"); // Negative diameter
	run_test("sp 0.0,0.0,20.6 12.6 10,0,255,255", 1, validate_sphere, "sphere"); // Extra color value
	run_test("sp 0.0,0.0,20.6 12.6 10,0", 1, validate_sphere, "sphere"); // Incomplete color
	run_test("sp 0.0,0.0,20.6 12.6 10,0,255 extra", 1, validate_sphere, "sphere"); // Extra text
	run_test("sp 0.0,0.0,20.6 0.0 10,0,255", 1, validate_sphere, "sphere"); // Zero diameter
}
