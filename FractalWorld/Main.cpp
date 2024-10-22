#include "Monolith/Engine.h"
#include "Monolith/Exceptions/ConsoleException.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
	try
	{
		Monolith::Engine engine{ true };
		engine.run();
	}
	catch (const Monolith::ConsoleException& exception)
	{
		std::cout << exception.code() << ": " << exception.what();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
