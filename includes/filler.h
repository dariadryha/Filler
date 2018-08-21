/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:47:21 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/19 17:47:21 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef	struct		s_str
{
	int				x;
	int				y;
	struct s_str	*next;
}					t_str;

typedef struct		s_cord
{
	char			p;
	char			e[2];
	short int		m[2];
	short int		t[2];
	int				res[3];
	char			**map;
	char			**tok;
	t_str			*pc;
	t_str			*en;
}					t_cord;

void				ft_algo(t_cord *data);
t_str				*ft_create_lst(int i, int j);
int					ft_count_list(t_str *list);
void				ft_del_list(t_str **data);
void				ft_check_place(t_cord *data);

#endif
