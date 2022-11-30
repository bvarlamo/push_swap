/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:13:31 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/01/25 13:49:46 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *ps, int groups, int *c)
{
	int		i;
	int		mid;

	while (groups != 1)
	{
		i = 0;
		mid = 0;
		while (i < groups / 2)
			mid += c[i++];
		while (ps->cb < mid)
			push_b(ps->a, ps->c, &ps->b, &ps->cb);
		i--;
		while (ps->cb)
		{
			ps->flag = c[(groups - 1)];
			ps->g_s = c[i];
			c[i] = ps->flag + ps->g_s;
			zipper_reverse(ps);
			i--;
			groups--;
		}
	}
}

void	sorting(t_ps *ps)
{
	int		groups;
	int		i;
	int		*c;

	ps->g_s = 5;
	ps->b = malloc(0);
	ps->cb = 0;
	groups = *ps->c / ps->g_s;
	if (*ps->c % ps->g_s)
		groups++;
	c = malloc(sizeof(int) * groups);
	i = 0;
	while (i < groups)
	{
		if (i == (groups - 1) && *ps->c % ps->g_s)
			c[i] = *ps->c % ps->g_s;
		else
			c[i] = ps->g_s;
		i++;
	}
	sort(ps, groups, c);
	free(c);
	free(ps->b);
}

void	sorting_groups(t_ps *ps)
{
	int		i;
	int		y;

	i = 0;
	ps->b = malloc(0);
	ps->cb = 0;
	while (i < *ps->c)
	{
		if ((*ps->c - i) > 4)
			y = 5;
		else
			y = *ps->c - i;
		while (y-- > 2)
			push_b(ps->a, ps->c, &ps->b, &ps->cb);
		ps->flag = 2;
		ps->g_s = ps->cb;
		if (*ps->c - i > 1 && ps->a[0][0] > ps->a[0][1])
			swap_a(*ps->a);
		odd(ps, i);
		i = i + 5;
	}
	free(ps->b);
	sorting(ps);
}

void	small_sort(t_ps *ps)
{
	ps->b = malloc(0);
	ps->cb = 0;
	if (*ps->c == 2 && ps->a[0][0] > ps->a[0][1])
		swap_a(*ps->a);
	else if (*ps->c == 3)
		sorting3_a(*ps->a, *ps->c);
	else if (*ps->c == 4)
	{
		push_b(ps->a, ps->c, &ps->b, &ps->cb);
		sorting3_a(*ps->a, *ps->c);
		ps->flag = 3;
		zipper_reverse(ps);
	}
	else if (*ps->c == 5)
	{
		push_b(ps->a, ps->c, &ps->b, &ps->cb);
		push_b(ps->a, ps->c, &ps->b, &ps->cb);
		if (ps->b[0] < ps->b[1])
			swap_b(ps->b);
		sorting3_a(*ps->a, *ps->c);
		ps->flag = 3;
		zipper_reverse(ps);
	}
	free(ps->b);
}

void	checker(int **nums, int *count)
{
	int		i;
	t_ps	ps;

	i = 0;
	ps.a = nums;
	ps.c = count;
	while (i < *ps.c - 1 && ps.a[0][i] < ps.a[0][i + 1])
		i++;
	if (i < (*ps.c - 1) && *ps.c > 1)
	{
		if (*ps.c > 5)
			sorting_groups(&ps);
		else
			small_sort(&ps);
	}
}
