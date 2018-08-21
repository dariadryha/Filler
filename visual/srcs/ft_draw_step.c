/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:49:33 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/22 11:49:33 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static	void	ft_draw_rectangle(t_vis *data, t_cord *cor, int y, int x)
{
	int i;
	int s;
	int j;

	s = data->size_line * (data->dist[1] + 1 + y * data->pix) +
	(data->dist[0] + 1 + (x * data->pix)) * BYTES;
	i = -1;
	while (++i < data->pix - 1)
	{
		j = 0;
		while (j < (data->pix - 1) * BYTES)
		{
			data->str[s + j] = mlx_get_color_value(data->ptr, data->rgb[0]);
			data->str[s + j + 1] = mlx_get_color_value(data->ptr, data->rgb[1]);
			data->str[s + j + 2] = mlx_get_color_value(data->ptr, data->rgb[2]);
			j += 4;
		}
		s += data->size_line;
	}
}

static	void	ft_draw_step_player(t_vis *data, t_cord *cor, t_str *temp)
{
	while (temp)
	{
		ft_draw_rectangle(data, cor, temp->y, temp->x);
		temp = temp->next;
	}
}

void			ft_draw_step(t_vis *data, t_cord *cor, t_str *o, t_str *x)
{
	if (cor->p == 'O')
	{
		ft_change_color(data, 0x66, 0x0000, 0x000066);
		ft_draw_step_player(data, cor, o);
		mlx_put_image_to_window(data->ptr, data->win, data->img, 0, PID);
		ft_change_color(data, 0xFF, 0x00CC, 0x000033);
		ft_draw_step_player(data, cor, x);
	}
	if (cor->p == 'X')
	{
		ft_change_color(data, 0xFF, 0x00CC, 0x000033);
		ft_draw_step_player(data, cor, x);
		mlx_put_image_to_window(data->ptr, data->win, data->img, 0, PID);
		ft_change_color(data, 0x66, 0x0000, 0x000066);
		ft_draw_step_player(data, cor, o);
	}
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0, PID);
}
