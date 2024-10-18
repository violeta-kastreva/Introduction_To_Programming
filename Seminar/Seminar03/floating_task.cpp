#include <iostream>
#include <cmath>

// Error limit in comparing floating point numbers
const double EPSILON = 0.000000005;
const double CIRCLE_RADIUS = 1;

int main() {
	double x, y;
	std::cout << "Please input x and y coordinates: ";
	std::cin >> x >> y;

	double distance = sqrt(x*x + y*y);

	// On the edge of circle (distance == CIRCLE_RADIUS)
	bool onEdge = fabsf64(distance - CIRCLE_RADIUS) <= EPSILON;

	// In circle (distance < CIRCLE_RADIUS)
	bool inCircle = !(distance > CIRCLE_RADIUS || onEdge);

	// Print result

    return 0;
}