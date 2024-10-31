#include "State.h"

#include "Map/MapChunk.h"

#include <sstream>

namespace Monolith
{
	State::State()
		: error_str_{ "" }, pmap_{ nullptr }
	{

	}

	State::State(Map& map)
		: error_str_{ "" }, pmap_{&map}
	{

	}

	State::~State()
	{

	}

	std::string State::display_str()
	{
		std::stringstream return_stream{};

		if (!error_str_.empty())
		{
			return_stream << error_str_ + "\n";
			clear();
		}

		if (pmap_ != nullptr)
		{
			return_stream << pmap_->get_current_chunk() << "\n";
		}
		
		return return_stream.str();
	}

	void State::error(const std::string& error_str)
	{
		error_str_ = error_str;
	}

	void State::clear()
	{
		error_str_.clear();
	}

	std::ostream& operator<<(std::ostream& os, State& state)
	{
		os << state.display_str();

		return os;
	}
}