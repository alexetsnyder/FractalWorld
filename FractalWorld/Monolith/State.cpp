#include "State.h"

namespace Monolith
{
	State::State()
		: empty_{ true }, display_ {}
	{

	}

	State::~State()
	{

	}

	std::string State::display_str()
	{
		return display_.str();
	}

	void State::add(const std::string& str)
	{
		if (empty_)
		{
			empty_ = false;
		}
		display_ << str;
	}

	void State::clear()
	{
		display_.str("");
		display_.clear();
		empty_ = true;
	}

	std::ostream& operator<<(std::ostream& os, State& state)
	{
		os << state.display_str();

		return os;
	}
}