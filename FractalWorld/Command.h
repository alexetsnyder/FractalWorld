#pragma once

#include <string>

namespace Monolith
{
	class Command
	{
		public:
			Command();
			Command(const std::string& console_name);
			~Command();

			//bool operator==(const std::string& )

		private:
			const std::string console_name_;

	};
}
