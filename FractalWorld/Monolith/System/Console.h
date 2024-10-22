#pragma once

#define NOMINMAX
#include <Windows.h>

namespace Monolith
{
	class Console
	{
		public:
			Console();
			~Console();

			void clear() const;

		private:
			HANDLE console_;
	};
}
