#include "CommandParser.h"

#include <map>

namespace Monolith
{
	enum class StringCode
	{
		NONE,
		MOVE_NORTH,
		MOVE_SOUTH,
		MOVE_EAST,
		MOVE_WEST,
	};

	std::map<std::string, StringCode> StringParser
	{
		{ "north", StringCode::MOVE_NORTH },
		{ "south", StringCode::MOVE_SOUTH },
		{ "east", StringCode::MOVE_EAST },
		{ "west", StringCode::MOVE_WEST },
	};

	CommandParser::CommandParser()
	{
	}

	CommandParser::~CommandParser()
	{
	}

	bool CommandParser::execute(const std::string& command, Map& map)
	{
		StringCode code{ StringCode::NONE };
		if (StringParser.count(command))
		{
			code = StringParser[command];
		}

		switch (code)
		{
			case StringCode::MOVE_NORTH:
				return map.move_north();

			case StringCode::MOVE_SOUTH:
				return map.move_south();

			case StringCode::MOVE_EAST:
				return map.move_east();

			case StringCode::MOVE_WEST:
				return map.move_west();

			default:
				return false;
		}	
	}
}