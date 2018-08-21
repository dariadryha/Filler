/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:19:07 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/22 11:19:08 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static	void	ft_draw_line_hor(t_vis *data, int index, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		data->str[index + i] = mlx_get_color_value(data->ptr, data->rgb[0]);
		data->str[index + i + 1] = mlx_get_color_value(data->ptr, data->rgb[1]);
		data->str[index + i + 2] = mlx_get_color_value(data->ptr, data->rgb[2]);
		i += 4;
	}
}

static	void	ft_draw_line_ver(t_vis *data, int index, int j)
{
	int i;

	i = -1;
	while (++i < j)
	{
		data->str[index] = mlx_get_color_value(data->ptr, data->rgb[0]);
		data->str[index + 1] = mlx_get_color_value(data->ptr, data->rgb[1]);
		data->str[index + 2] = mlx_get_color_value(data->ptr, data->rgb[2]);
		index += data->size_line;
	}
}

void			ft_change_color(t_vis *data, int r, int g, int b)
{
	data->rgb[0] = r;
	data->rgb[1] = g;
	data->rgb[2] = b;
}

void			ft_draw_frame(t_vis *data, t_cord cor)
{
	ft_change_color(data, 0xFF, 0x0033, 0x000066);
	ft_draw_line_hor(data, data->bord[0], data->points[0]);
	ft_draw_line_ver(data, data->bord[1], data->points[1]);
	ft_draw_line_hor(data, data->bord[2], data->points[0]);
	ft_draw_line_ver(data, data->bord[3], data->points[1]);
}

void			ft_draw_grid(t_vis *data, t_cord cor)
{
	int i;

	i = data->pix;
	ft_change_color(data, 0x55, 0x0055, 0x000055);
	while (i < data->points[1])
	{
		ft_draw_line_hor(data, data->bord[0] + data->size_line * i,
			data->points[0]);
		i += data->pix;
	}
	i = data->pix * BYTES;
	while (i < data->points[0])
	{
		ft_draw_line_ver(data, data->bord[0] + i, data->points[1]);
		i += data->pix * BYTES;
	}
}
