#pragma once

#include "MapChunk.h"

#include <optional>
#include <vector>

namespace Monolith
{
	struct Pair
	{
		int x;
		int y;
	};

	class Map
	{
		public:
			Map(int rows  = 4, int cols = 4);

			const Pair& current_pos() { return current_pos_; }

			std::optional<MapChunk> get_chunk(int i, int j);
			bool move_pos(int i, int j);
			bool out_of_bounds(int i, int j) const;

		private:
			Pair current_pos_;
			std::vector<MapChunk> map_chunks_;
			int rows_;
			int cols_;
	};
}
