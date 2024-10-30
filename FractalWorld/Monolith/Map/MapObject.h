#pragma once

#include "MapDescriptor.h"

#include <iostream>
#include <string>
#include <string_view>

namespace Monolith
{
	class MapObject : public MapDescriptor
	{
		public:
			MapObject();
			MapObject(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural);
			~MapObject();

		private:
	};

	std::ostream& operator<<(std::ostream& os, MapObject map_item);
}
