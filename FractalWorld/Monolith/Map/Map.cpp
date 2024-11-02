#include "Map.h"

#include "MapObject.h"

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
				DescriptorSettings item_settings
				{
					"Knife",
					"A glittering blade with a jeweled hilt",
					"",
					false,
				};

				Item item{ item_settings };

				DescriptorSettings object_settings
				{
					"Table",
					"Solid oak with four thick cylindrical legs",
					"",
					false,
				};

				MapObject object{ object_settings, { item } };
				MapChunk chunk{ std::format("Coord {}:{}", i, j), "A Map Coordinate", std::vector{ object } };
				map_chunks_.push_back(chunk);
			}
		}
	}

	const MapChunk& Map::get_current_chunk()
	{
		int index = current_pos_.i + current_pos_.j * cols_;
		return map_chunks_[index];
	}

	bool Map::move_north()
	{
		return move_pos(current_pos_.i - 1, current_pos_.j);
	}

	bool Map::move_south()
	{
		return move_pos(current_pos_.i + 1, current_pos_.j);
	}

	bool Map::move_east()
	{
		return move_pos(current_pos_.i, current_pos_.j + 1);
	}

	bool Map::move_west()
	{
		return move_pos(current_pos_.i, current_pos_.j - 1);
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
		if (current_pos_.i == i && current_pos_.j == j || out_of_bounds(i, j))
		{
			return false;
		}

		current_pos_.i = i;
		current_pos_.j = j;

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