#include "CommandParser.h"

#include "Map/MapChunk.h"

#include <format>
#include <map>
#include <sstream>

namespace Monolith
{
	enum class StringCode
	{
		NONE,
		MOVE_NORTH,
		MOVE_SOUTH,
		MOVE_EAST,
		MOVE_WEST,
		SEARCH,
	};

	std::map<std::string, StringCode> StringParser
	{
		{ "north", StringCode::MOVE_NORTH },
		{ "south", StringCode::MOVE_SOUTH },
		{ "east", StringCode::MOVE_EAST },
		{ "west", StringCode::MOVE_WEST },
		{ "search", StringCode::SEARCH },
	};

	CommandParser::CommandParser()
	{

	}

	CommandParser::~CommandParser()
	{

	}

	bool CommandParser::execute(const std::string& command, State& state)
	{
		StringCode code{ StringCode::NONE };
		if (StringParser.count(command))
		{
			code = StringParser[command];
		}

		switch (code)
		{
			case StringCode::MOVE_NORTH:
				return state.pmap()->move_north();

			case StringCode::MOVE_SOUTH:
				return state.pmap()->move_south();

			case StringCode::MOVE_EAST:
				return state.pmap()->move_east();

			case StringCode::MOVE_WEST:
				return state.pmap()->move_west();

			case StringCode::SEARCH:
				show_all_items(state);			
				return true;

			default:
				return false;
		}	
	}

	void CommandParser::show_all_items(State& state)
	{
		std::stringstream output_stream{};

		MapChunk chunk{ state.pmap()->get_current_chunk() };

		output_stream << std::format("In the {}, there are: \n", chunk.name());

		for (auto& obj : chunk.map_objects())
		{
			for (auto& item : obj.items())
			{
				output_stream << item << "\n";
			}
		}

		state.output(output_stream.str());
	}
}