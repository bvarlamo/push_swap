/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:17:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/01/25 10:52:12 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	odd(t_ps *ps, int i)
{
	if (ps->cb)
	{
		if (ps->cb == 3)
			sorting3_b(ps->b, ps->cb);
		else if (ps->cb == 2 && ps->b[0] > ps->b[1])
			swap_b(ps->b);
		zipper(ps);
	}
	else
	{
		if (ps->cb == 0 && *ps->c - i == 2)
		{
			if (ps->a[0][0] > ps->a[0][1])
				swap_a(*ps->a);
			rotate_a(*ps->a, *ps->c);
			rotate_a(*ps->a, *ps->c);
		}
		else if (ps->cb == 0 && *ps->c - i == 1)
			rotate_a(*ps->a, *ps->c);
	}
}

void	zipper(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->g_s)
	{
		if (ps->flag && ps->a[0][0] < ps->b[0])
		{
			rotate_a(*ps->a, *ps->c);
			ps->flag--;
		}
		else
		{
			push_a(&ps->b, &ps->cb, ps->a, ps->c);
			ps->flag++;
			i++;
		}
	}
	if (i >= ps->g_s && ps->flag)
	{
		while (ps->flag--)
			rotate_a(*ps->a, *ps->c);
	}
}

void	zipper_reverse(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->g_s && ps->cb)
	{
		if (ps->flag && ps->a[0][*ps->c - 1] > ps->b[0])
		{
			reverse_rotate_a(*ps->a, *ps->c);
			ps->flag--;
		}
		else
		{
			push_a(&ps->b, &ps->cb, ps->a, ps->c);
			i++;
		}
	}
	if (i >= ps->g_s && ps->flag)
		while (ps->flag--)
			reverse_rotate_a(*ps->a, *ps->c);
	else if (!ps->cb && ps->flag)
		while (ps->flag--)
			reverse_rotate_a(*ps->a, *ps->c);
}

void	sorting3_a(int *nums, int count)
{
	if (nums[0] > nums[1] && nums[0] < nums[2])
		swap_a(nums);
	if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		swap_a(nums);
		reverse_rotate_a(nums, count);
	}
	if (nums[0] > nums[1] && nums[2] > nums[1])
		rotate_a(nums, count);
	if (nums[0] < nums[2] && nums[1] > nums[2])
	{
		swap_a(nums);
		rotate_a(nums, count);
	}
	if (nums[0] > nums[2] && nums[0] < nums[1])
		reverse_rotate_a(nums, count);
}

void	sorting3_b(int *nums, int count)
{
	if (nums[0] > nums[1] && nums[0] < nums[2])
		swap_b(nums);
	if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		swap_b(nums);
		reverse_rotate_b(nums, count);
	}
	if (nums[0] > nums[1] && nums[2] > nums[1])
		rotate_b(nums, count);
	if (nums[0] < nums[2] && nums[1] > nums[2])
	{
		swap_b(nums);
		rotate_b(nums, count);
	}
	if (nums[0] > nums[2] && nums[0] < nums[1])
		reverse_rotate_b(nums, count);
}
