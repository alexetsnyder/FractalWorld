#pragma once

#include "State.h"

#include <string>

namespace Monolith
{
	class CommandParser
	{
		public:
			CommandParser();
			~CommandParser();

			bool execute(const std::string& command, State& state);

		private:
			void show_all_items(State& state);
	};
}
