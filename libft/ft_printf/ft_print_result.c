/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:45:06 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/10 15:45:06 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_right_justify(t_flag *head, int *res, char *temp,
	char *result)
{
	if (head->width)
		write(1, temp, head->width);
	if (head->sign)
	{
		write(1, &head->sign, 1);
		head->sign = 0;
	}
	if (head->precision)
	{
		ft_print_spec_format(head);
		while (head->precision)
		{
			*res += write(1, "0", 1);
			head->precision--;
		}
	}
	if (head->sign)
		write(1, &head->sign, 1);
	ft_print_spec_format(head);
	if (head->data)
		write(1, result, head->data);
}

static	void	ft_left_justify(t_flag *head, int *res, char *temp,
	char *result)
{
	if (head->precision)
	{
		if (head->sign)
		{
			write(1, &head->sign, 1);
			head->sign = 0;
		}
		ft_print_spec_format(head);
		while (head->precision)
		{
			*res += write(1, "0", 1);
			head->precision--;
		}
	}
	if (head->sign)
		write(1, &head->sign, 1);
	ft_print_spec_format(head);
	if (head->data)
		write(1, result, head->data);
	if (head->width)
		write(1, temp, head->width);
}

void			ft_print_result(t_flag *head, int *res, char *temp,
	char *result)
{
	if (head->left)
		ft_left_justify(head, res, temp, result);
	else
		ft_right_justify(head, res, temp, result);
	free(result);
}
