#pragma once

#include <string>

namespace Monolith
{
	struct DescriptorSettings
	{
		std::string name{ "" };
		std::string short_description{ "" };
		std::string long_description{ "" };
		bool is_plural;
	};
}