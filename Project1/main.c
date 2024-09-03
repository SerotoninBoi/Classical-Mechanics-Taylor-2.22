#include "header.h"
/*****************************************
* Deegan Bator
* Classical Mechanics Problem 2.22
* 8/03/2024
* Problem: Consider a projectile launched at angle theta above the horizontal with initial speed v0.
* Choose units such that v0 = 1.0 and g = 1.0. Suppose also that the terminal seed vterm is 1.0 (with v0 = vterm, air resistance should be fairly important).
* We know in a vacuum the max range occurs at theta = pi/4.
* A) What is the maximum range in a vacuum?
* B) Solve for the range in the given medium at the same angle of theta = pi/4.
* C) Use newtons method to solve for the angle that gives the maximum range in the given medium.
*/
int main(void)
{
	const double tau = 1.0;
	const double v0 = 1.0;
	const double vterm = 1.0;
	const double g = 1.0;
	const double theta = PI / 4;
	
	double initial_guess = 0.5;
	double tolerance = 1.0e-8; //adjust for number of decimal places
	int max_interations = 100;

	//solve max range in a vacuum
	double R_vacuum_solution = (2 * x_component(PI / 4, v0) * y_component(PI / 4, v0)) / g;
	printf(ANSI_COLOR_LIGHT_BLUE"\nPart A\n" ANSI_COLOR_RESET);
	printf("Max range in a vacuum: %lf\n", R_vacuum_solution);

	//solve range in the given medium at theta = pi/4
	//double R_given_medium_solution = newtons_method(initial_guess, tolerance, max_interations, v0, vterm, theta, tau);
	printf(ANSI_COLOR_LIGHT_BLUE"\nPart B\n" ANSI_COLOR_RESET);
	double R_given_medium_solution = newtons_method_print(initial_guess, tolerance, max_interations, theta, vterm, tau, v0);
	printf("Range in the given medium at theta = pi/4: %lf\n", R_given_medium_solution);


	//solve for the angle that gives the maximum range in the given medium

	double max_R = 0.0;
	double max_theta = 0.0;

	//loop over a range of angles to find the maximum range
	//Could me made more efficient by using a binary search
	for (double theta_index = 0.001; theta_index < PI / 2; theta_index += 0.001)
	{
		double R = newtons_method(initial_guess, tolerance, max_interations, v0, vterm, theta_index, tau);
		if (R > max_R)
		{
			max_R = R;
			max_theta = theta_index;
		}
	}
	//convert radians to degrees
	max_theta = max_theta * 180 / PI;
	printf(ANSI_COLOR_LIGHT_BLUE"\nPart C and D\n" ANSI_COLOR_RESET);
	printf("Max range in the given medium: %lf at angle: %lf degrees\n", max_R, max_theta); 

	return 0;

}
