#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	for(double i = -2.0; i <= 2.0; i += 0.2)
		std::cout << std::setprecision(50) << i << std::endl;

		return 0;
}
