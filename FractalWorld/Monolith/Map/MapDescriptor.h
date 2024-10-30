#pragma once

#include <string>

namespace Monolith
{
	class MapDescriptor
	{
		public:
			static inline int idGenerator{ 0 };

			MapDescriptor(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural);
			virtual ~MapDescriptor() {};

			const int id() const { return id_; }
			std::string name() { return name_; }
			std::string short_description() { return short_description_; }
			std::string long_description() { return long_description_; }
			bool is_plural() const { return is_plural_; }

		private:
			const int id_;
			std::string name_;
			std::string short_description_;
			std::string long_description_;
			bool is_plural_;
	};

}
