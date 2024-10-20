#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>

#define NOMINMAX
#include <Windows.h>

bool clear_screen_flag{ true };

void main_menu();
void print_main_menu();
void new_game();
void load_game();
void settings();
void credits();
void print_back_prompt();
int clear_screen();

std::unordered_map<std::string, void(*)()> commands
{
	{ "exit", []() { std::cout << "Thank you for playing!\n"; } },
	{ "new", &new_game },
	{ "load", &load_game },
	{ "settings", &settings },
	{ "credits", &credits },
};

int main(int argc, char** argv)
{
	main_menu();

	return EXIT_SUCCESS;
}

void main_menu()
{
	while (true)
	{
		if (clear_screen_flag)
		{
			clear_screen();
		}
		print_main_menu();

		std::string input{};
		if (!std::getline(std::cin >> std::ws, input))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });

		if (commands.count(input) == 1)
		{
			commands.at(input)();
		}

		if (input == "exit")
		{
			break;
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

void new_game()
{
	std::cout << "You are on a path in the woods. You are walking towards an unknown destination.\n"; 
	std::cout << "The hoary faces of ancient trees watch your progress: silent judges of what's to come.\n";
	print_back_prompt();
}

void load_game()
{
	std::cout << "Saves:\n";
	std::cout << "1. Brave New World.\n";
	std::cout << "2. Fake Save 2.\n";
	std::cout << "3. Bloodroot.\n";
	print_back_prompt();
}

void settings()
{
	std::cout << "Settings:\n";
	std::cout << "Clear Screen: " << std::boolalpha << clear_screen_flag << "\n";
	print_back_prompt();
}

void credits()
{
	std::cout << "Credits:\n";
	std::cout << "Autumn Snyder\n";
	print_back_prompt();
}

void print_back_prompt()
{
	std::cout << "Press enter to return: ";
	std::cin.ignore();
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
