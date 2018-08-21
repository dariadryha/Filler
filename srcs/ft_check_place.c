/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:48:41 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/16 11:48:41 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	ft_find_res(int i, int j, t_cord *data, int *n)
{
	t_str	*temp;
	int		dist;

	temp = data->en;
	while (temp)
	{
		dist = ABS(i - n[0] - temp->y) + ABS(j - n[1] - temp->x);
		if (!data->res[2] || data->res[2] > dist)
		{
			data->res[2] = dist;
			data->res[0] = i - n[0];
			data->res[1] = j - n[1];
		}
		temp = temp->next;
	}
}

static	void	ft_find_min(t_str *temp, int *n)
{
	t_str *new;

	n[0] = temp->y;
	n[1] = temp->x;
	new = temp->next;
	while (new)
	{
		n[0] = n[0] > new->y ? new->y : n[0];
		n[1] = n[1] > new->x ? new->x : n[1];
		new = new->next;
	}
}

static	void	ft_check_valid_cord(t_cord *data, int i, int j)
{
	t_str	*temp;
	int		flg;
	int		n[2];

	temp = data->pc;
	flg = 0;
	ft_bzero(n, 2 * sizeof(int));
	ft_find_min(temp, n);
	while (temp)
	{
		if (i + temp->y - n[0] >= data->m[0] ||
			j + temp->x - n[1] >= data->m[1] ||
		data->map[i + temp->y - n[0]][j + temp->x - n[1]] == data->e[0] ||
		data->map[i + temp->y - n[0]][j + temp->x - n[1]] == data->e[1])
			break ;
		if (data->map[i + temp->y - n[0]][j + temp->x - n[1]] == data->p)
			flg++;
		temp = temp->next;
	}
	if (flg == 1 && !temp)
		ft_find_res(i, j, data, n);
}

void			ft_check_place(t_cord *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_check_valid_cord(data, i, j);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", data->res[0], data->res[1]);
}
