/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:21:22 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/20 11:21:22 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static	void	ft_parsing_data(t_vis *data, char *line)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	while (++i < 9 && get_next_line(data->fd, &line) > 0)
	{
		j = 0;
		if (i == 6 || i == 8)
		{
			while (line[j])
			{
				if (line[14 + j] == '.' && line[14 + j + 1] == '/')
					break ;
				j++;
			}
			str = ft_strsub(line, 14 + j + 2, ft_strlen(line + j + 14 + 2) - 1);
			if (i == 6)
				mlx_string_put(data->ptr, data->win, 250, 130, 0x660066, str);
			if (i == 8)
				mlx_string_put(data->ptr, data->win, 620, 130, 0x33CCFF, str);
			free(str);
		}
		free(line);
	}
}

static	int		set_key(int key, void *param)
{
	if (key == 53)
		exit(0);
	*(int *)param = 1;
	return (0);
}

static	void	ft_init_struct(t_vis *data)
{
	data->rgb[0] = 0xFF;
	data->rgb[1] = 0x00FF;
	data->rgb[2] = 0x0000FF;
	ft_bzero(data->cor.m, 2 * sizeof(int));
	data->cor.map = NULL;
	data->cor.en = NULL;
	data->cor.pc = NULL;
	data->pix = 0;
	ft_bzero(data->bord, 4 * sizeof(int));
	ft_bzero(data->points, 2 * sizeof(int));
	ft_bzero(data->dist, 2 * sizeof(int));
}

int				main(void)
{
	t_vis	data;
	int		fd;
	char	*line;

	line = NULL;
	data.fd = 0;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, WIDTH, HEIGHT, "Filler visualizer");
	data.img = mlx_new_image(data.ptr, WIDTH - PID, HEIGHT - PID);
	data.str = mlx_get_data_addr(data.img, &data.bits_per_pixel,
		&data.size_line, &data.endian);
	mlx_key_hook(data.win, set_key, (void *)0);
	ft_init_struct(&data);
	ft_parsing_data(&data, line);
	mlx_loop_hook(data.ptr, ft_read_data, &data);
	mlx_loop(data.ptr);
	return (0);
}
