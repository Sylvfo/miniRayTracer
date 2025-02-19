#include "test_utils.h"

int	validate_plane(char *line);

void	test_validate_plane(void)
{
	// Valid test cases
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225", 0, validate_plane, "plane");
	run_test("pl 1.0,2.0,3.0 0.0,0.0,1.0 255,255,255", 0, validate_plane, "plane");
	run_test("pl -1.0,-2.0,-3.0 -1.0,-1.0,-1.0 100,100,100", 0, validate_plane, "plane");

	// Invalid test cases
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,256", 1, validate_plane, "plane"); // Invalid color value
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,0.0", 1, validate_plane, "plane"); // Missing color
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,2.0 0,0,225", 1, validate_plane, "plane"); // Invalid normal vector
	run_test("pl 0.0,0.0,-10.0 0.0,1.0 0,0,225", 1, validate_plane, "plane"); // Incomplete normal vector
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225,225", 1, validate_plane, "plane"); // Extra color value
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0", 1, validate_plane, "plane"); // Incomplete color
	run_test("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225 extra", 1, validate_plane, "plane"); // Extra text
}
