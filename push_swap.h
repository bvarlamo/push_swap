/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:13:36 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/01/25 10:17:09 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_ps
{
	int		**a;
	int		*b;
	int		*c;
	int		cb;
	int		flag;
	int		g_s;
}	t_ps;

void	checker(int **nums, int *count);
void	swap_a(int *nums);
void	swap_b(int *nums);
void	push_a(int **from, int *count_from, int **to, int *count_to);
void	push_b(int **from, int *count_from, int **to, int *count_to);
void	rotate_a(int *nums, int count);
void	rotate_b(int *nums, int count);
void	reverse_rotate_a(int *nums, int count);
void	reverse_rotate_b(int *nums, int count);
void	odd(t_ps *ps, int i);
void	sorting3_b(int *nums, int count);
void	sorting3_a(int *nums, int count);
void	zipper(t_ps *ps);
void	zipper_reverse(t_ps *ps);

#endif 