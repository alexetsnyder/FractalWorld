#include "MapChunk.h"

namespace Monolith
{
	MapChunk::MapChunk()
		: name_{}, description_{}, map_objects_ {}
	{

	}

	MapChunk::MapChunk(const std::string& name, const std::string& description, const std::vector<MapObject>& map_objects)
		: name_{ name }, description_{ description }, map_objects_{ map_objects }
	{
		
	}

	MapChunk::~MapChunk()
	{

	}

	std::ostream& operator<<(std::ostream& os, const MapChunk& map_chunk)
	{
		os << map_chunk.description() << "\n";
		os << "In the " << map_chunk.name() << " lies: ";

		for (MapObject item : map_chunk.map_objects())
		{
			os << item << "\n";

		}

		return os;
	}
	
}