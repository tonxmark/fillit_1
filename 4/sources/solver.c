#include "fillit.h"

//=============================================================================>
int		overlap(t_map *map, t_piece *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->blockcoords[i] + piece->x_offset;
	y = piece->blockcoords[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
	}
	return (i != 8);
}

void	place(t_piece *piece, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}


int		solve_map(t_map *map, t_piece *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;

	while ((piece->blockcoords[7] + piece->y_offset) < map_size)
	{
		while ((piece->blockcoords[0] + piece->x_offset) < map_size)
		{
			if (overlap(map, piece) == 0)
			{
				place(piece, map, piece->pieceletter);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
					place(piece, map, '.');
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

void	solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;
	int		i;

	i = 0;
	map_size = 2;
	map = new_map(map_size);
	while (solve_map(map, piecelist, map_size) == 0)
	{
		free_map(map, map_size++);
		map = new_map(map_size);
	}
	while (i <= map_size - 1)
		ft_putendl(map->array[i++]);
	free_map(map, map_size);
}
