#include "test_utils.h"

int	validate_cylinder(char *line);

void	test_validate_cylinder(void)
{
	// Valid test cases
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255", 0, validate_cylinder, "cylinder");
	run_test("cy 0.0,0.0,0.0 1.0,0.0,0.0 10.0 20.0 255,255,255", 0, validate_cylinder, "cylinder");
	run_test("cy -50.0,-50.0,-50.0 -1.0,-1.0,-1.0 5.0 10.0 0,0,0", 0, validate_cylinder, "cylinder");

	// Invalid test cases
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,256", 1, validate_cylinder, "cylinder");
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42", 1, validate_cylinder, "cylinder");
	run_test("cy 50.0,0.0,20.6 0.0,0.0,2.0 14.2 21.42 10,0,255", 1, validate_cylinder, "cylinder");
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 -21.42 10,0,255", 1, validate_cylinder, "cylinder");
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255,255", 1, validate_cylinder, "cylinder");
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0", 1, validate_cylinder, "cylinder");
	run_test("cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 extra", 1, validate_cylinder, "cylinder");
}
