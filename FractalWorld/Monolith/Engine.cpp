#include "Engine.h"
#include "CommandParser.h"
#include "Map/MapChunk.h"
#include "State.h"

#include <algorithm>
#include <format>
#include <iostream>

namespace Monolith
{
	/*std::vector<Monolith::MapItem> map_items
	{
		Monolith::MapItem{ "Haunted House", "An old cabin lying broken upon the earth.", "", false },
		Monolith::MapItem{ "Tree", "Rough bark leads upward to thick branches; a rope hangs from a branch carrying a tire swing swinging softly in the breeze.", "", false },
		Monolith::MapItem{ "Stars", "The vaulted heavens cold and distant.", "", true },
	};*/

	Engine::Engine(bool clear_screen_flag)
		: state_{ GameState::RUNNING }, clear_screen_flag_{ clear_screen_flag }, console_{}, commands_{}, map_{}
			//"Glade", "You are standing on a path in a glade. Dewy grass shinning in the starlight.", map_items }
	{
		commands_.insert(
		{ 
			{ "quit", &Engine::exit_game },
			{ "q", &Engine::exit_game },
			{ "exit", &Engine::exit_game },
			{ "new", &Engine::new_game },
			{ "load", &Engine::load_game },
			{ "settings", &Engine::settings },
			{ "credits", &Engine::credits },
		});
	}

	Engine::~Engine()
	{

	}

	void Engine::run()
	{
		while (state_ != GameState::EXIT)
		{
			main_menu();
		}
	}

	void Engine::main_menu()
	{
		clear_screen();
		print_main_menu();

		std::string input{ getInput() };

		if (input != "" && commands_.count(input) == 1)
		{
			(this->*(commands_.at(input)))();
		}
	}

	void Engine::print_main_menu()
	{
		std::cout << "Main Menu:\n";
		std::cout << "1. New Game\n";
		std::cout << "2. Load Game\n";
		std::cout << "3. Settings\n";
		std::cout << "4. Credits\n";
		std::cout << "5. Exit\n";
	}

	std::string Engine::getInput()
	{
		std::string input{};
		if (!std::getline(std::cin >> std::ws, input))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return "";
		}

		std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });

		return input;
	}

	void Engine::game_loop()
	{
		State state{ map_ };
		CommandParser parser{};

		while (true)
		{
			clear_screen();

			std::cout << state << "\n";

			std::cout << ">>> ";

			std::string input{ getInput() };

			if (parse_exit(input))
			{
				break;
			}

			if (!parser.execute(input, map_))
			{
				state.error(std::format("The glass dome prevents you from going any further {}\n", input));
			}
		}
	}

	void Engine::new_game()
	{
		clear_screen();
		game_loop();
		//std::cout << "You are on a path in the woods. You are walking towards an unknown destination.\n"; 
		//std::cout << "The hoary faces of ancient trees watch your progress: silent judges of what's to come.\n";
		/*std::cout << map_ << "\n";
		print_prompt();*/
	}

	void Engine::load_game()
	{
		clear_screen();
		std::cout << "Saves:\n";
		std::cout << "1. Brave New World.\n";
		std::cout << "2. Fake Save 2.\n";
		std::cout << "3. Bloodroot.\n";
		print_prompt();
	}

	void Engine::settings()
	{
		clear_screen();
		std::cout << "Settings:\n";
		std::cout << "Clear Screen: " << std::boolalpha << clear_screen_flag_ << "\n";
		print_prompt();
	}

	void Engine::credits()
	{
		clear_screen();
		std::cout << "Credits:\n";
		std::cout << "Autumn Snyder\n";
		print_prompt();
	}

	void Engine::exit_game()
	{
		std::cout << "Thank you for playing!\n";
		state_ = GameState::EXIT;
	}

	void Engine::print_prompt()
	{
		std::cout << "Press enter to return: ";
		std::cin.ignore();
	}

	void Engine::clear_screen()
	{
		if (clear_screen_flag_)
		{
			console_.clear();
		}
	}

	bool Engine::parse_exit(const std::string& input)
	{
		if (input == "exit" || input == "quit" || input == "q")
		{
			return true;
		}
		return false;
	}
}