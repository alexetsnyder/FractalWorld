#include "Item.h"

Monolith::Item::Item()
	: MapDescriptor{ "", "", "", false }
{
}

Monolith::Item::Item(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural)
	: MapDescriptor{ name, short_description, long_description, is_plural }
{

}

Monolith::Item::~Item()
{

}
