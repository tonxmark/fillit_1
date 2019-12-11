#include "fillit.h"

t_piece		*makepiece(char *buf, char pieceletter)
{
	t_piece	*piece_ptr;
	int		x;
	int		y;
	int		i;

	x = -2;
	y = -1;
	i = -1;
	if (!(piece_ptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i++ <= 19)
	{
		if (buf[i] == '#')
		{
			piece_ptr->blockcoords[x += 2] = i >= 5 ? i % 5 : i;
			piece_ptr->blockcoords[y += 2] = i / 5;
		}
	}
	while (piece_ptr->blockcoords[0] != 0 && (i = -1))
		while (i++ < 7)
			(i % 2 == 0) ? (piece_ptr->blockcoords[i] += -1) : 0;
	while (piece_ptr->blockcoords[1] != 0 && (i = -1))
		while (i++ < 7)
			(i % 2 == 1) ? (piece_ptr->blockcoords[i] += -1) : 0;
	piece_ptr->pieceletter = pieceletter;
	return (piece_ptr);
}

t_piece		*makelist(char *buf, int size)
{
	t_piece	*hold;
	t_piece *current;
	t_piece *beginning;
	char	pieceletter;
	int		i;

	i = -21;
	pieceletter = 'A';
	while ((i += 21) < size && (hold = makepiece(buf + i, pieceletter)))
	{
		current = pieceletter++ == 'A' ?\
			(beginning = hold) : (current->next = hold);
	}
	current->next = NULL;
	return (beginning);
}
