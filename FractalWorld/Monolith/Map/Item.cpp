#include "Item.h"

namespace Monolith
{
	Item::Item()
		: MapDescriptor{ DescriptorSettings{} }
	{
	}

	Item::Item(const DescriptorSettings& settings)
		: MapDescriptor{ settings }
	{

	}

	Item::~Item()
	{

	}

	std::ostream& operator<<(std::ostream& os, Item item)
	{
		os << ((item.is_plural()) ? "" : "A ") << item.name() << "--";
		os << item.short_description() << ".";
		return os;
	}
}
