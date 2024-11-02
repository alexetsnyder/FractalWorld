#pragma once

#include "MapDescriptor.h"

#include <iostream>
#include <string>

namespace Monolith
{
	class Item : public MapDescriptor
	{
		public:
			Item();
			Item(const DescriptorSettings& settings);
			~Item();

		private:
	};

	std::ostream& operator<<(std::ostream& os, Item item);
}
