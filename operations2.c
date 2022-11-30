/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:06:29 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/01/25 10:06:58 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int **from, int *count_from, int **to, int *count_to)
{
	int	*tmp;
	int	i;
	int	tem;

	tem = from[0][0];
	tmp = (int *)malloc(sizeof(int) * (*count_from - 1));
	i = 0;
	while (++i < *count_from)
		tmp[i - 1] = from[0][i];
	*count_from = *count_from - 1;
	free(*from);
	*from = tmp;
	tmp = (int *)malloc(sizeof(int) * (*count_to + 1));
	tmp[0] = tem;
	i = 0;
	while (++i < (*count_to + 1))
		tmp[i] = to[0][i - 1];
	*count_to = *count_to + 1;
	free(*to);
	*to = tmp;
	write(1, "pa\n", 3);
}

void	rotate_a(int *nums, int count)
{
	int	i;
	int	tmp;

	tmp = nums[0];
	i = 0;
	while (i < (count - 1))
	{
		nums[i] = nums[i + 1];
		i++;
	}
	nums[i] = tmp;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(int *nums, int count)
{
	int	i;
	int	tmp;

	tmp = nums[count - 1];
	i = count - 1;
	while (i > 0)
	{
		nums[i] = nums[i - 1];
		i--;
	}
	nums[i] = tmp;
	write(1, "rra\n", 4);
}
