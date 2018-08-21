/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:55:50 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/19 17:55:51 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	int		ft_read_cord(int fd, short int y, char ***temp)
{
	int i;

	i = 0;
	*temp = (char **)malloc(sizeof(char *) * y + 1);
	while (i < y)
	{
		get_next_line(fd, &(*temp)[i]);
		if ((ft_isdigit((*temp)[i][0])))
			(*temp)[i] = ft_strcpy((*temp)[i], (*temp)[i] + 4);
		i++;
	}
	(*temp)[i] = NULL;
	return (0);
}

static	void	ft_save_data(int fd, t_cord *data, char *line)
{
	int i;

	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line[1] == 'l')
		{
			data->m[0] = ft_atoi(line + 8);
			data->m[1] = ft_atoi(line + 8 + ft_un_nbr_char(data->m[0], 10));
			free(line);
			get_next_line(fd, &line);
			ft_read_cord(fd, data->m[0], &data->map);
		}
		else
		{
			data->t[0] = ft_atoi(line + 6);
			data->t[1] = ft_atoi(line + 6 + ft_un_nbr_char(data->t[0], 10));
			ft_read_cord(fd, data->t[0], &data->tok);
			ft_algo(data);
		}
		free(line);
	}
}

static	void	ft_null_data(t_cord *data)
{
	ft_bzero(data->m, 2 * 4);
	ft_bzero(data->t, 2 * 4);
	ft_bzero(data->res, 3 * sizeof(int));
	data->pc = NULL;
	data->en = NULL;
}

int				main(void)
{
	t_cord	data;
	char	*line;
	int		fd;

	fd = 0;
	line = NULL;
	ft_null_data(&data);
	get_next_line(fd, &line);
	data.p = line[10] == '1' ? 'O' : 'X';
	data.e[0] = (data.p == 'O' ? 'X' : 'O');
	data.e[1] = data.e[0] + 32;
	free(line);
	ft_save_data(fd, &data, line);
	return (0);
}
