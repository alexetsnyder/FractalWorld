#pragma once

#include "MapChunk.h"

#include <optional>
#include <vector>

namespace Monolith
{
	struct Pair
	{
		int i;
		int j;
	};

	class Map
	{
		public:
			Map(int rows  = 4, int cols = 4);

			const Pair& current_pos() { return current_pos_; }

			const MapChunk& get_current_chunk();
			bool move_north();
			bool move_south();
			bool move_east();
			bool move_west();

			std::optional<MapChunk> get_chunk(int i, int j);
			bool move_pos(int i, int j);
			bool out_of_bounds(int i, int j) const;

		private:
			int rows_;
			int cols_;
			Pair current_pos_;
			std::vector<MapChunk> map_chunks_;
	};
}
