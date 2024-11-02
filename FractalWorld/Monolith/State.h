#pragma once

#include "Map/Map.h"

#include <iostream>
#include <string>

namespace Monolith
{
	class State
	{
		public:
			State();
			State(Map& map);
			~State();

			Map* pmap() { return pmap_; }

			std::string display_str();
			void output(const std::string& output_str);
			void error(const std::string& error_str);
			void clear();

		private:
			std::string output_str_;
			std::string error_str_;
			Map* pmap_;
	};

	std::ostream& operator<<(std::ostream& os, State& state);
}
