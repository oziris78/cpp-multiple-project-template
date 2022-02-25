
#include "Functions.h"
#include <GLFW/glfw3.h>
#include <iostream>


int main() {
	telek::print_hi();

	int a = glfwInit();
	std::cout << a << std::endl;

	return 0;
}
