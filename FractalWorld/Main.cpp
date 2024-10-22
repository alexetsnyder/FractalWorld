#include "Exceptions/ConsoleException.h"
#include "MapChunk.h"
#include "MapItem.h"
#include "System/Console.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

bool clear_screen_flag{ true };

void main_menu(Monolith::Console console);
void print_main_menu();
void new_game(Monolith::Console console);
void load_game(Monolith::Console console);
void settings(Monolith::Console console);
void credits(Monolith::Console console);
void print_back_prompt();
void clear_screen(Monolith::Console console);

std::unordered_map<std::string, void(*)(Monolith::Console)> commands
{
	{ "exit", [](Monolith::Console) { std::cout << "Thank you for playing!\n"; } },
	{ "new", &new_game },
	{ "load", &load_game },
	{ "settings", &settings },
	{ "credits", &credits },
};

std::vector<Monolith::MapItem> map_items
{
	Monolith::MapItem{ "Haunted House", "An old cabin lying broken upon the earth.", "", false },
	Monolith::MapItem{ "Tree", "Rough bark leads upward to thick branches; a rope hangs from a branch carrying a tire swing swinging softly in the breeze.", "", false },
	Monolith::MapItem{ "Stars", "The vaulted heavens cold and distant.", "", true },
};

Monolith::MapChunk map{ "Glade", "You are standing on a path in a glade. Dewy grass shinning in the starlight.", map_items};

int main(int argc, char** argv)
{
	try
	{
		Monolith::Console console{};
		main_menu(console);
	}
	catch (const Monolith::ConsoleException& exception)
	{
		std::cout << exception.code() << ": " << exception.what();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void main_menu(Monolith::Console console)
{
	while (true)
	{
		clear_screen(console);
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
			commands.at(input)(console);
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

void new_game(Monolith::Console console)
{
	clear_screen(console);
	//std::cout << "You are on a path in the woods. You are walking towards an unknown destination.\n"; 
	//std::cout << "The hoary faces of ancient trees watch your progress: silent judges of what's to come.\n";
	std::cout << map << "\n";
	print_back_prompt();
}

void load_game(Monolith::Console console)
{
	clear_screen(console);
	std::cout << "Saves:\n";
	std::cout << "1. Brave New World.\n";
	std::cout << "2. Fake Save 2.\n";
	std::cout << "3. Bloodroot.\n";
	print_back_prompt();
}

void settings(Monolith::Console console)
{
	clear_screen(console);
	std::cout << "Settings:\n";
	std::cout << "Clear Screen: " << std::boolalpha << clear_screen_flag << "\n";
	print_back_prompt();
}

void credits(Monolith::Console console)
{
	clear_screen(console);
	std::cout << "Credits:\n";
	std::cout << "Autumn Snyder\n";
	print_back_prompt();
}

void print_back_prompt()
{
	std::cout << "Press enter to return: ";
	std::cin.ignore();
}

void clear_screen(Monolith::Console console)
{
	if (clear_screen_flag)
	{
		console.clear();
	}
}
