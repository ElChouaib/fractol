/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:52:12 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/30 18:08:18 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	static char	*str[4863];
	char		tab[BUFF_SIZE + 1];
	int			bytes_read;
	int			i;

	if (fd == -1 || line == NULL || read(fd, tab, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = malloc(sizeof(char *) * (BUFF_SIZE + 1));
	while ((bytes_read = read(fd, tab, BUFF_SIZE)) > 0)
	{
		tab[bytes_read] = '\0';
		str[fd] = ft_strjoin(str[fd], tab);
		if (ft_strchr(tab, '\n'))
			break ;
	}
	i = 0;
	if (!ft_strlen(str[fd]))
		return (0);
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	str[fd] = ft_strdup(str[fd] + i + 1);
	return (1);
}
