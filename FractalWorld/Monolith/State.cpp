#include "State.h"

#include "Map/MapChunk.h"

#include <sstream>

namespace Monolith
{
	State::State()
		: output_str_{ "" }, error_str_{""}, pmap_{nullptr}
	{

	}

	State::State(Map& map)
		: output_str_{ "" }, error_str_{ "" }, pmap_{&map}
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
			return_stream << error_str_ << "\n";
		}

		if (!output_str_.empty())
		{
			return_stream << output_str_ << "\n";
		}

		clear();

		if (pmap_ != nullptr)
		{
			return_stream << pmap_->get_current_chunk() << "\n";
		}
		
		return return_stream.str();
	}

	void State::output(const std::string& output_str)
	{
		output_str_ = output_str;
	}

	void State::error(const std::string& error_str)
	{
		error_str_ = error_str;
	}

	void State::clear()
	{
		output_str_.clear();
		error_str_.clear();
	}

	std::ostream& operator<<(std::ostream& os, State& state)
	{
		os << state.display_str();

		return os;
	}
}