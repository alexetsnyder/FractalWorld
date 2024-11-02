#include "MapObject.h"

namespace Monolith
{
    MapObject::MapObject()
        : MapDescriptor{ DescriptorSettings{} }, items_{}
    {
     
    }

    MapObject::MapObject(const DescriptorSettings& settings, const std::vector<Item>& items)
        : MapDescriptor{ settings }, items_{ items }
    {

    }

    MapObject::~MapObject()
    {

    }

    std::ostream& operator<<(std::ostream& os, MapObject map_object)
    {
        os << ((map_object.is_plural()) ? "" : "A ") << map_object.name() << "--";
        os << map_object.short_description() << ".";
        return os;
    }
}