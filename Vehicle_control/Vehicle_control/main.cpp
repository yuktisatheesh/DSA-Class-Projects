#include "Cars.h"

vehicle_control::controls This;

int main() {
	std::cout << "Simple Vehicle control program\n";
	std::cout << "Version 0.0.0.0\n" << std::endl;
	while (true) {
		try {
			This.interaction();
		}
		catch (std::exception& e) {
			std::cerr << '\n' << e.what() << '\n' << std::endl;
			std::cin.clear();
			std::cin.get();
		}
	}
    return 0;
}
