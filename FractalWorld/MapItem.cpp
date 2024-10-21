#include "MapItem.h"

namespace Monolith
{
    MapItem::MapItem()
        : id_{ idGenerator++ }, name_{ "" }, short_description_{ "" }, long_description_{ "" }, is_plural_{ false }
    {
     
    }

    MapItem::MapItem(const std::string& name, const std::string& short_description, const std::string& long_description, bool is_plural)
        : id_{ idGenerator++ }, name_{ name }, short_description_{ short_description }, long_description_{ long_description_ }, is_plural_{ is_plural }
    {

    }

    MapItem::~MapItem()
    {

    }

    std::ostream& operator<<(std::ostream& os, MapItem map_item)
    {
        os << ((map_item.is_plural()) ? "" : "A ") << map_item.name() << "--";
        os << map_item.short_description();
        return os;
    }
}