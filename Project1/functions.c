#include "header.h"

double x_component(double theta, double v)
{
	return v * cos(theta);
}

double y_component(double theta, double v)
{
	return v * sin(theta);
}

double f(double R, double v0,double vterm, double theta, double tau)
{
	double vy0 = y_component(theta, v0);
	double vx0 = x_component(theta, v0);

	return (((vy0 + vterm) / vx0) * R) + vterm * tau * log(1 - (R / (vx0 * tau)));
}

double f_prime(double R, double v0, double vterm, double theta, double tau)
{
	double vy0 = y_component(theta, v0);
	double vx0 = x_component(theta, v0);

	return ((vterm * R) + (R * vy0) - (tau * vx0 * vy0)) / ((R * vx0) - (tau * (vx0 * vx0)));
}

double newtons_method(double initial_guess, double tolerance, int max_interations, double v0, double vterm, double theta, double tau)
{
	double R = initial_guess;
	double R_next = 0.0;
	for (int i = 0; i < max_interations; i++)
	{
		R_next = R - f(R,v0,vterm,theta,tau) / f_prime(R,v0,vterm,theta,tau);
		if (fabs(R_next - R) < tolerance)
		{
			return R_next; // converged
		}
		R = R_next;
	}
	return -1; // did not converge
}

double newtons_method_print(double initial_guess, double tolerance, int max_iterations, double theta, double vterm, double tau, double v0) {
	double R = initial_guess;
	printf("Iteration  | R          | f(R)       | f'(R)\n");
	printf("---------------------------------------------\n");

	for (int i = 0; i < max_iterations; i++) {
		double f_val = f(R, v0, vterm, theta, tau);
		double f_prime_val = f_prime(R, v0, vterm, theta, tau);
		double R_next = R - f_val / f_prime_val;

		// Print the current iteration, R, f(R), and f'(R)
		printf("%-10d | %-10.6f | %-10.6f | %-10.6f\n", i + 1, R, f_val, f_prime_val);

		if (fabs(R_next - R) < tolerance) {
			return R_next;  // Converged
		}
		R = R_next;
	}
	// If we reach here, Newton's method did not converge within the max iterations
	return R;
}