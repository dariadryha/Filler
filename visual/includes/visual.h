/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:22:26 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/20 11:22:27 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "minilibx_macos/mlx.h"
# include "../../includes/filler.h"

# define WIDTH 1000
# define HEIGHT 1000
# define BYTES 4
# define PID 150

typedef struct	s_vis
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*str;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			rgb[3];
	int			pix;
	int			fd;
	int			bord[4];
	int			points[2];
	int			dist[2];
	int			skip;
	t_cord		cor;
}				t_vis;

int				ft_read_data(t_vis *data);
void			ft_draw_frame(t_vis *data, t_cord cor);
void			ft_draw_grid(t_vis *data, t_cord cor);
void			ft_change_color(t_vis *data, int r, int g, int b);
void			ft_draw_map(char c, t_vis *data, t_cord *cor);
void			ft_draw_step(t_vis *data, t_cord *cor, t_str *o, t_str *x);

#endif
