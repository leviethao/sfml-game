#include "Application.h"
#include <iostream>
#include <exception>

#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")

int main()
{
	try
	{
	Application app;
	app.run();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}