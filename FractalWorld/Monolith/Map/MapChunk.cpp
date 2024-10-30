#include "MapChunk.h"

namespace Monolith
{
	MapChunk::MapChunk()
		: name_{}, description_{}, objects_ {}
	{

	}

	MapChunk::MapChunk(const std::string& name, const std::string& description, const std::vector<MapObject>& items)
		: name_{ name }, description_{ description }, objects_{ items }
	{
		
	}

	MapChunk::~MapChunk()
	{

	}

	std::ostream& operator<<(std::ostream& os, MapChunk& map_chunk)
	{
		os << map_chunk.description() << "\n";
		os << "In the " << map_chunk.name() << " lies: ";

		for (MapObject item : map_chunk.items())
		{
			os << item << "\n";

		}

		return os;
	}
	
}