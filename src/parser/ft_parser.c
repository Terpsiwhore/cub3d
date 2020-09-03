/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 10:57:55 by kcorazon          #+#    #+#             */
/*   Updated: 2020/09/02 10:57:57 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

void 	ft_parser(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int 	i;
	t_list	*list = NULL;
	t_list	*tmp;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	map->row = ft_calloc(ft_lstsize(list) + 1, sizeof(char *));
	tmp = list;
	while(tmp)
	{
		map->row[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&list, free);
}
