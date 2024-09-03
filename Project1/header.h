#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS_
// Constants
#define PI 3.1415926535

//Terminal Color Codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
//light colors
#define ANSI_COLOR_LIGHT_RED     "\x1b[91m"
#define ANSI_COLOR_LIGHT_GREEN   "\x1b[92m"
#define ANSI_COLOR_LIGHT_YELLOW  "\x1b[93m"
#define ANSI_COLOR_LIGHT_BLUE    "\x1b[94m"
#define ANSI_COLOR_LIGHT_MAGENTA "\x1b[95m"
#define ANSI_COLOR_LIGHT_CYAN    "\x1b[96m"


// Function Prototypes
double x_component(double theta, double v);
double y_component(double theta, double v);
double f(double R, double v0, double vterm, double theta, double tau);
double f_prime(double R, double v0, double vterm, double theta, double tau);
double newtons_method(double initial_guess, double tolerance, int max_interations, double v0, double vterm, double theta, double tau);
double newtons_method_print(double initial_guess, double tolerance, int max_iterations, double theta, double vterm, double tau, double v0);



