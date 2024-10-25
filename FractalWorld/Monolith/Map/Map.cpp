#include "Map.h"

#include "MapItem.h"

#include <format>

namespace Monolith
{
	Map::Map(int rows, int cols)
		: current_pos_{ 0, 0 }, map_chunks_ {}, rows_{ rows, }, cols_{ cols }
	{
		for (int j = 0; j < cols; j++)
		{
			for (int i = 0; i < rows; i++)
			{
				MapItem item{ "knife", "A glittering blade with a jeweled hilt.", "", false };
				MapChunk chunk{ std::format("Coord {}:{}", i, j), "A Map Coordinate.", std::vector{ item } };
				map_chunks_.push_back(chunk);
			}
		}
	}

	std::optional<MapChunk> Map::get_chunk(int i, int j)
	{
		if (!out_of_bounds(i, j))
		{
			int index = i + j * cols_;
			return map_chunks_[index];
		}

		return {};
	}

	bool Map::move_pos(int i, int j)
	{
		if (current_pos_.x == i && current_pos_.y == j || out_of_bounds(i, j))
		{
			return false;
		}

		current_pos_.x = i;
		current_pos_.y = j;

		return true;
	}

	bool Map::out_of_bounds(int i, int j) const
	{
		if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
		{
			return true;
		}
		return false;
	}
}