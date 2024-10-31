#include "Item.h"

Monolith::Item::Item()
	: MapDescriptor{ DescriptorSettings{} }
{
}

Monolith::Item::Item(const DescriptorSettings& settings)
	: MapDescriptor{ settings }
{

}

Monolith::Item::~Item()
{

}
