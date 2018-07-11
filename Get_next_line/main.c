#include "get_next_line.h"

int		main(void)
{
	int fd;
	char	*line;

	fd = open("text", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
