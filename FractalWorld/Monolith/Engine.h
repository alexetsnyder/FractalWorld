#pragma once

#include "Enums/State.h"
#include "Map/Map.h"
#include "System/Console.h"

#include <unordered_map>
#include <string>

namespace Monolith
{
	class Engine
	{
		public:
			Engine(bool clear_screen_flag);
			~Engine();

			void run();

		private:
			void main_menu();
			void print_main_menu();
			std::string getInput();
			void game_loop();
			void new_game();
			void load_game();
			void settings();
			void credits();
			void exit_game();
			void print_prompt();
			void clear_screen();
			bool parse_exit(const std::string& input);

			GameState state_;
			std::unordered_map<std::string, void (Engine::*)()> commands_;
			bool clear_screen_flag_;
			Console console_;
			Map map_;
	};
}
