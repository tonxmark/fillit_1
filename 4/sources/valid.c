#include "fillit.h"

int		adjacency_counter(char *buf)
{
	int i;
	int x;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
		{
			x = -9;
			while (x++ <= -3 && (x += 3))
				if (buf[x + i] == '#' && x + i >= 0)
					count++;
			x = -3;
		      while (x++ <= 3 && (x += 3))
				if (buf[x + i] == '#' && x + i <= 18)
					count++;
		}
		i++;
	}
	return (count);
}

int		valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if((adjacency_counter(buf + i) != 6 && adjacency_counter(buf + i) != 8))
			return (0);
		i += 21;
	}
	return (1);
}


t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	close(fd);
	buf[bytecount] = '\0';
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	if (valid(buf, bytecount) == 0)
		return (NULL);
	return (makelist(buf, bytecount));
}
