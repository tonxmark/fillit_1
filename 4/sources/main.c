#include "fillit.h"

void		free_piecelist(t_piece *list)
{
	t_piece *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
void	print_map(t_map *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
//============================================================================>

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->array = (char**)ft_memalloc(sizeof(char*) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	t_piece	*piecelist;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((piecelist = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(piecelist);
	free_piecelist(piecelist);
	return (0);
}
