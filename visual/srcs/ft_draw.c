/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:42:24 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/22 10:42:24 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static	void	ft_save_need_cords(t_str **list, t_str **targ, int i, int j)
{
	t_str *temp;
	t_str *temp_t;

	if (!*list || !*targ)
	{
		*list = !*list ? ft_create_lst(i, j) : *list;
		*targ = ft_create_lst(i, j);
	}
	else
	{
		temp = *list;
		temp_t = *targ;
		while (temp && temp->next)
			temp = temp->next;
		while (temp_t && temp_t->next)
			temp_t = temp_t->next;
		temp_t->next = ft_create_lst(i, j);
		temp->next = ft_create_lst(i, j);
	}
}

static	int		ft_check_exist_cords(t_str *list, int i, int j)
{
	t_str *temp;

	temp = list;
	while (temp)
	{
		if (temp->y == i && temp->x == j)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static	void	ft_search_cords(t_vis *data, t_cord *cor, t_str **o, t_str **x)
{
	int i;
	int j;

	i = 0;
	while (i < data->cor.m[0])
	{
		j = 0;
		while (cor->map[i][j])
		{
			if (cor->map[i][j] == 'O' || cor->map[i][j] == 'o')
			{
				if (ft_check_exist_cords(cor->pc, i, j))
					ft_save_need_cords(&cor->pc, o, i, j);
			}
			if (cor->map[i][j] == 'X' || cor->map[i][j] == 'x')
			{
				if (ft_check_exist_cords(cor->en, i, j))
					ft_save_need_cords(&cor->en, x, i, j);
			}
			j++;
		}
		i++;
	}
}

void			ft_draw_map(char c, t_vis *data, t_cord *cor)
{
	t_str *o;
	t_str *x;

	o = NULL;
	x = NULL;
	data->cor.p = c;
	ft_search_cords(data, cor, &o, &x);
	ft_draw_step(data, cor, o, x);
	ft_del_list(&o);
	ft_del_list(&x);
}
