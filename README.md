Documentation
This project solves a classical mechanics problem involving projectile motion with air resistance. The problem is divided into three parts:
1.	Part A: Calculate the maximum range of a projectile in a vacuum.
2.	Part B: Calculate the range of a projectile in a medium with air resistance at a given angle.
3.	Part C: Use Newton's method to find the angle that gives the maximum range in the given medium.

Part A: Maximum Range in a Vacuum
In a vacuum, the maximum range of a projectile occurs at an angle of 45 degrees (π/4 radians). The formula for the range ( R ) in a vacuum is given by:

[ R = \frac{2 \cdot v_0 \cdot \cos(\theta) \cdot v_0 \cdot \sin(\theta)}{g} ]

In the code, this is calculated as follows:

double R_vacuum_solution = (2 * x_component(PI / 4, v0) * y_component(PI / 4, v0)) / g;

Part B: Range in a Given Medium
In a medium with air resistance, the range is calculated using Newton's method to solve the equation for the range ( R ). The function newtons_method_print is used to iteratively find the range at a given angle (π/4 radians):

double R_given_medium_solution = newtons_method_print(initial_guess, tolerance, max_interations, theta, vterm, tau, v0);

This function prints the iteration details and returns the range when the method converges.

Part C: Angle for Maximum Range in a Given Medium
To find the angle that gives the maximum range in the given medium, the code iterates over a range of angles from 0 to π/2 radians. For each angle, it uses 
Newton's method to calculate the range and keeps track of the maximum range and corresponding angle:

double max_R = 0.0;
double max_theta = 0.0;

for (double theta_index = 0.001; theta_index < PI / 2; theta_index += 0.001)
{
    double R = newtons_method(initial_guess, tolerance, max_interations, v0, vterm, theta_index, tau);
    if (R > max_R)
    {
        max_R = R;
        max_theta = theta_index;
    }
}

Finally, the angle is converted from radians to degrees and printed:

max_theta = max_theta * 180 / PI;

printf("Max range in the given medium: %lf at angle: %lf degrees\n", max_R, max_theta);

Summary
•	Part A: Calculates the maximum range in a vacuum using the known formula.
•	Part B: Uses Newton's method to find the range in a medium with air resistance at a specific angle.
•	Part C: Iterates over a range of angles to find the angle that gives the maximum range in the given medium using Newton's method.

