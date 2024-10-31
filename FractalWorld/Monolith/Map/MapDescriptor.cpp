#include "MapDescriptor.h"

namespace Monolith
{
	MapDescriptor::MapDescriptor(const DescriptorSettings& settings)
		: id_{ idGenerator++ }, settings_{ settings }
	{

	}
}