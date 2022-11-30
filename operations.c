/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:05:54 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/01/25 09:44:44 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *nums)
{
	int	tmp;

	tmp = nums[0];
	nums[0] = nums[1];
	nums[1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(int *nums)
{
	int	tmp;

	tmp = nums[0];
	nums[0] = nums[1];
	nums[1] = tmp;
	write(1, "sb\n", 3);
}

void	push_b(int **from, int *count_from, int **to, int *count_to)
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
	write(1, "pb\n", 3);
}

void	rotate_b(int *nums, int count)
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
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(int *nums, int count)
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
	write(1, "rrb\n", 4);
}
