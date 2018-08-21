/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:22:41 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/12 13:22:41 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_spec_format(t_flag *head)
{
	if (head->hash)
	{
		if (head->c == 'o' || head->c == 'O')
			write(1, "0", 1);
		else if (head->c == 'x' || head->c == 'p')
			ft_putstr("0x");
		else if (head->c == 'X')
			ft_putstr("0X");
		head->hash = 0;
	}
	if (head->c == 'p')
		ft_putstr("0x");
	head->c = 0;
}
