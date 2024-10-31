#pragma once

#include "MapObject.h"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace Monolith
{
	class MapChunk
	{
		public:
			MapChunk();
			MapChunk(const std::string& name, const std::string& description, const std::vector<MapObject>& items);
			~MapChunk();

			std::string_view name() const { return name_; }
			std::string_view description() const { return description_; }
			const std::vector<MapObject>& items() const { return objects_; }

		private:
			std::string name_;
			std::string description_;
			std::vector<MapObject> objects_;
	};

	std::ostream& operator<<(std::ostream& os, const MapChunk& map_chunk);
}
