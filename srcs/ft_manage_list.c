/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:58:48 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/15 17:58:49 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_del_list(t_str **data)
{
	t_str *temp;
	t_str *del;

	del = *data;
	while (del)
	{
		temp = del->next;
		del->x = 0;
		del->y = 0;
		free(del);
		del = temp;
	}
	*data = NULL;
}

int		ft_count_list(t_str *list)
{
	t_str	*temp;
	int		i;

	temp = list;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_str	*ft_create_lst(int i, int j)
{
	t_str *temp;

	if (!(temp = (t_str *)malloc(sizeof(t_str))))
		return (NULL);
	temp->x = j;
	temp->y = i;
	temp->next = NULL;
	return (temp);
}
