#pragma once

#include "Map/MapChunk.h"
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
			void new_game();
			void load_game();
			void settings();
			void credits();
			void exit_msg();
			void print_prompt();
			void clear_screen();

			std::unordered_map<std::string, void (Engine::*)()> commands_;
			bool clear_screen_flag_;
			Console console_;
			MapChunk map_;
	};
}
