#include <cstdlib>
#include <iostream>
#include <Windows.h>

void main_menu();
void print_main_menu();
int clear_screen();

DWORD originalMode{ 0 };

int main(int argc, char** argv)
{
	main_menu();

	return EXIT_SUCCESS;
}

void main_menu()
{
	bool running{ true };
	while (running)
	{
		clear_screen();
		print_main_menu();
		int choice{ 0 };
		std::cin >> choice;
		if (choice == 5)
		{
			running = false;
			std::cout << "Thank you for playing!\n";
		}
		else
		{
			std::cout << "NO!\n";
		}
	}
}

void print_main_menu()
{
	std::cout << "Main Menu:\n";
	std::cout << "1. New Game\n";
	std::cout << "2. Load Game\n";
	std::cout << "3. Settings\n";
	std::cout << "4. Credits\n";
	std::cout << "5. Exit\n";
}

//From: https://learn.microsoft.com/en-us/windows/console/clearing-the-screen
int clear_screen()
{
	HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SMALL_RECT scroll_rect{};
	COORD scroll_target{};
	CHAR_INFO fill{};

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return -1;
	}

	scroll_rect.Left = 0;
	scroll_rect.Top = 0;
	scroll_rect.Right = csbi.dwSize.X;
	scroll_rect.Bottom = csbi.dwSize.Y;

	scroll_target.X = 0;
	scroll_target.Y = (SHORT)(0 - csbi.dwSize.Y);

	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(hConsole, &scroll_rect, NULL, scroll_target, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;

	SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);

	return 1;
}