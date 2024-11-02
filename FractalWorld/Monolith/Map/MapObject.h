#pragma once

#include "Item.h"
#include "MapDescriptor.h"
#include "Monolith/Structs/Settings.h"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace Monolith
{
	class MapObject : public MapDescriptor
	{
		public:
			MapObject();
			MapObject(const DescriptorSettings& settings, const std::vector<Item>& items);
			~MapObject();

			const std::vector<Item>& items() const { return items_; }

		private:
			std::vector<Item> items_;
	};

	std::ostream& operator<<(std::ostream& os, MapObject map_object);
}
