#pragma once

#include "MapDescriptor.h"
#include "Monolith/Structs/Settings.h"

#include <iostream>
#include <string>
#include <string_view>

namespace Monolith
{
	class MapObject : public MapDescriptor
	{
		public:
			MapObject();
			MapObject(const DescriptorSettings& settings);
			~MapObject();

		private:
	};

	std::ostream& operator<<(std::ostream& os, MapObject map_item);
}
