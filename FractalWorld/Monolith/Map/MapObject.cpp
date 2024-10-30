#include "MapObject.h"

namespace Monolith
{
    MapObject::MapObject()
        : MapDescriptor{ "", "", "", false }
    {
     
    }

    MapObject::MapObject(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural)
        : MapDescriptor{ name, short_description, long_description, is_plural }
    {

    }

    MapObject::~MapObject()
    {

    }

    std::ostream& operator<<(std::ostream& os, MapObject map_object)
    {
        os << ((map_object.is_plural()) ? "" : "A ") << map_object.name() << "--";
        os << map_object.short_description();
        return os;
    }
}