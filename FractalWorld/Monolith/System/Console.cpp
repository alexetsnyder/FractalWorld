#include "Console.h"

#include "Monolith/Exceptions/ConsoleException.h"

namespace Monolith
{
	Console::Console()
		: console_{ GetStdHandle(STD_OUTPUT_HANDLE) }
	{
		if (console_ == INVALID_HANDLE_VALUE)
		{
			throw ConsoleException{ GetLastError(), "Failed to get console handle."};
		}
	}

	Console::~Console()
	{

	}

	//From: https://learn.microsoft.com/en-us/windows/console/clearing-the-screen
	void Console::clear() const
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		SMALL_RECT scroll_rect{};
		COORD scroll_target{};
		CHAR_INFO fill{};

		if (!GetConsoleScreenBufferInfo(console_, &csbi))
		{
			throw ConsoleException{ GetLastError(), "Failed to get console screen buffer info." };
		}

		scroll_rect.Left = 0;
		scroll_rect.Top = 0;
		scroll_rect.Right = csbi.dwSize.X;
		scroll_rect.Bottom = csbi.dwSize.Y;

		scroll_target.X = 0;
		scroll_target.Y = (SHORT)(0 - csbi.dwSize.Y);

		fill.Char.UnicodeChar = TEXT(' ');
		fill.Attributes = csbi.wAttributes;

		if (!ScrollConsoleScreenBuffer(console_, &scroll_rect, NULL, scroll_target, &fill))
		{
			throw ConsoleException{ GetLastError(), "Failed to scroll the console screen buffer." };
		}

		csbi.dwCursorPosition.X = 0;
		csbi.dwCursorPosition.Y = 0;

		if (!SetConsoleCursorPosition(console_, csbi.dwCursorPosition))
		{
			throw ConsoleException{ GetLastError(), "Failed to set the console cursor position." };
		}
	}
}