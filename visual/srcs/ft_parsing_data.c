/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:42:31 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/21 16:42:32 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static	int		ft_read_cord(char **line, int fd, short int y, char ***temp)
{
	int i;

	i = 0;
	free(*line);
	get_next_line(fd, line);
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

static	void	ft_draw(t_vis *data)
{
	ft_draw_frame(data, data->cor);
	ft_draw_grid(data, data->cor);
	mlx_string_put(data->ptr, data->win, WIDTH / 2 - 130, 90,
		0x6633FF, "Filler visualizer by ddryha");
}

static	void	ft_count_sizes(t_vis *data, char *line)
{
	data->cor.m[0] = ft_atoi(line + 8);
	data->cor.m[1] = ft_atoi(line + 8 + ft_un_nbr_char(data->cor.m[0], 10));
	if (data->cor.m[0] < 20 && data->cor.m[1] < 20)
		data->pix = 20;
	if (data->cor.m[0] > 20 && data->cor.m[1] > 20 &&
		data->cor.m[0] < 50 && data->cor.m[1] < 50)
		data->pix = 15;
	if (data->cor.m[0] > 50 && data->cor.m[1] > 50)
		data->pix = 6;
	data->points[0] = data->cor.m[1] * BYTES * data->pix;
	data->points[1] = data->cor.m[0] * data->pix;
	data->dist[0] = (WIDTH - PID) / 2 - ((data->points[0] / BYTES) / 2) + 75;
	data->dist[1] = (HEIGHT - PID) / 2 - data->points[1] / 2 - 75;
	data->bord[0] = data->size_line * data->dist[1] + data->dist[0] * BYTES;
	data->bord[1] = data->size_line * data->dist[1] + data->dist[0] * BYTES;
	data->bord[2] = data->size_line *
	(data->dist[1] + data->cor.m[0] * data->pix) + data->dist[0] * BYTES;
	data->bord[3] = data->size_line * data->dist[1] +
	(data->dist[0] + data->cor.m[1] * data->pix) * BYTES;
	ft_draw(data);
}

static	void	ft_print_final(char *line, t_vis *data)
{
	char *str;

	mlx_string_put(data->ptr, data->win, WIDTH / 2 - 85, HEIGHT / 2 - 50,
		0x6633FF, "Results of the game:");
	str = ft_strjoin("PLayer ", line + 3);
	if (line[3] == 'O')
	{
		mlx_destroy_image(data->ptr, data->img);
		mlx_clear_window(data->ptr, data->win);
		mlx_string_put(data->ptr, data->win, WIDTH / 2 - 70, HEIGHT / 2,
		0x6633FF, str);
	}
	else
		mlx_string_put(data->ptr, data->win, WIDTH / 2 - 70, HEIGHT / 2 + 50,
			0x6633FF, str);
	free(str);
}

int				ft_read_data(t_vis *data)
{
	char	*line;

	line = NULL;
	data->skip = 0;
	while (get_next_line(data->fd, &line) > 0)
	{
		if (line[1] == 'l')
		{
			if (!data->cor.m[0] && !data->cor.m[1])
				ft_count_sizes(data, line);
			data->skip = 1;
			ft_read_cord(&line, data->fd, data->cor.m[0], &data->cor.map);
		}
		if (data->skip == 1 && line[0] == '<')
		{
			ft_draw_map(line[6], data, &data->cor);
			free(line);
			ft_del_mas_str(data->cor.map);
			return (1);
		}
		if (line[0] == '=')
			ft_print_final(line, data);
		free(line);
	}
	return (0);
}
