#pragma once

#include <stdexcept>
#include <string>

namespace Monolith
{
	class ConsoleException : public std::runtime_error
	{
		public:
			ConsoleException(unsigned long code, const std::string& error_msg)
				: std::runtime_error(error_msg), code_{ code }
			{

			}

			unsigned long code() const { return code_; }

		private:
			unsigned long code_;

	};
}
