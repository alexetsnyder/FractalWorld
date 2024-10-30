#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace Monolith
{
	class State
	{
		public:
			State();
			~State();

			bool empty() const { return empty_; }
			std::string display_str();
			void add(const std::string& str);
			void clear();

		private:
			bool empty_;
			std::stringstream display_;
	};

	std::ostream& operator<<(std::ostream& os, State& state);
}
