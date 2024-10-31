#pragma once

#include "MapDescriptor.h"

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
}
