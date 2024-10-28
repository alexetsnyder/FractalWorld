#pragma once

#include "Map/Map.h"

#include <string>

namespace Monolith
{
	class CommandParser
	{
		public:
			CommandParser();
			~CommandParser();

			bool execute(const std::string& command, Map& map);

		private:
	};
}
