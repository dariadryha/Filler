/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:23:27 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/08 13:23:28 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_save_cord(char **mas, t_cord *data, t_str **lst)
{
	int		i[2];
	t_str	*temp;

	ft_bzero(i, 2 * sizeof(int));
	temp = NULL;
	while (mas[i[0]])
	{
		i[1] = 0;
		while (mas[i[0]][i[1]])
		{
			if (mas[i[0]][i[1]] == data->e[0] ||
				mas[i[0]][i[1]] == data->e[1] || mas[i[0]][i[1]] == '*')
			{
				*lst = !*lst ? ft_create_lst(i[0], i[1]) : *lst;
				(*lst)->next = !temp ? (*lst)->next : ft_create_lst(i[0], i[1]);
				*lst = !temp ? *lst : (*lst)->next;
				temp = !temp ? *lst : temp;
			}
			i[1]++;
		}
		i[0]++;
	}
	*lst = temp;
}

void		ft_algo(t_cord *data)
{
	ft_bzero(data->res, 3 * sizeof(int));
	ft_save_cord(data->tok, data, &data->pc);
	ft_save_cord(data->map, data, &data->en);
	ft_check_place(data);
	ft_del_list(&data->pc);
	ft_del_list(&data->en);
	ft_del_mas_str(data->map);
	ft_del_mas_str(data->tok);
}
