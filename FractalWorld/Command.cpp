#include "Command.h"

namespace Monolith
{
	Command::Command()
		: console_name_{ "" }
	{

	}

	Command::Command(const std::string& console_name)
		: console_name_{ console_name }
	{

	}

	Command::~Command()
	{

	}
}