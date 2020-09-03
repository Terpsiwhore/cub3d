

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <fcntl.h>

typedef struct	s_map
{
	char		**row;
}				t_map;

void 			ft_parser(char *path, t_map *map);

#endif
