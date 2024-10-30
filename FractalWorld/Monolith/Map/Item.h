#pragma once

#include "MapDescriptor.h"

#include <string>

namespace Monolith
{
	class Item : public MapDescriptor
	{
		public:
			Item();
			Item(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural);
			~Item();

		private:
	};
}
