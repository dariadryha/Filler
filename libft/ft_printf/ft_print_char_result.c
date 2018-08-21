/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:30:25 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/17 11:30:26 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char_result(t_flag *head, char n, char *temp)
{
	if (head->left)
	{
		write(1, &n, 1);
		if (head->width)
			write(1, temp, head->width);
	}
	else
	{
		if (head->width)
			write(1, temp, head->width);
		write(1, &n, 1);
	}
}
