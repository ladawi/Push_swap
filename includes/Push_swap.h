/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:50:30 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/13 15:39:30 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <stdio.h>

typedef struct s_chain
{
	int				nb;
	struct s_chain	*next;
	struct s_chain	*prev;
}				t_chain;

typedef struct s_push_swap
{
	t_chain		*list_a;
	t_chain		*list_b;
	t_chain		*list_a_tail;
	int			median;
	int			*tab_nb;
	int			len;
}				t_push_swap;

t_chain		*set_list_tail(t_push_swap *push_swap, t_chain *node);
int		get_list(t_push_swap *push_swap, int len, char **av);
int		check(int ac, char **av);
int		check_double(t_push_swap *push_swap, int index, int len);
int		get_median(t_push_swap *push_swap);
void	rotate_a(t_push_swap *push_swap);
void	rev_rotate_a(t_push_swap *push_swap);
void		swap_a(t_push_swap *push_swap);

#endif
