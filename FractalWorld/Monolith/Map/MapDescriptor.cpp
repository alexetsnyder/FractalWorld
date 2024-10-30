#include "MapDescriptor.h"

namespace Monolith
{
	MapDescriptor::MapDescriptor(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural)
		: id_{ idGenerator++ }, name_{ name }, short_description_{ short_description }, long_description_{ long_description_ }, is_plural_{ is_plural }
	{

	}
}