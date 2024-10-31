#pragma once

#include "Monolith/Structs/Settings.h"

#include <string>

namespace Monolith
{
	class MapDescriptor
	{
		public:
			static inline int idGenerator{ 0 };

			MapDescriptor(const DescriptorSettings& settings);
			virtual ~MapDescriptor() {};

			const int id() const { return id_; }
			std::string name() const { return settings_.name; }
			std::string short_description() const { return settings_.short_description; }
			std::string long_description() const { return settings_.long_description; }
			bool is_plural() const { return settings_.is_plural; }

		private:
			const int id_;
			DescriptorSettings settings_;
	};

}
