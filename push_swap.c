/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:09:01 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/01/25 13:05:04 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nums_check(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-')
			i++;
	if (!(ft_atoi(str)) && str[0] != '0')
		return (0);
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]))
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	*allocation(int	**num, int count, char	**split)
{
	int	*tmp;
	int	i;

	i = 0;
	while (split[i])
	{
		if (!(nums_check(split[i])))
			exit (write(2, "Error\n", 6));
		i++;
	}
	tmp = (int *)malloc(sizeof(int) * (count + i));
	i = 0;
	while (i < count)
	{
		tmp[i] = num[0][i];
		i++;
	}
	free(*num);
	return (tmp);
}

int	*init(char **argv, int *y)
{
	char	**split;
	int		*nums1;
	int		i;
	int		j;

	j = 1;
	nums1 = malloc(0);
	while (argv[j])
	{
		split = ft_split(argv[j], ' ');
		nums1 = allocation(&nums1, *y, split);
		i = 0;
		while (split[i])
		{
			nums1[*y] = ft_atoi(split[i]);
			free(split[i++]);
			*y += 1;
		}
		free(split);
		j++;
	}
	return (nums1);
}

int	main(int argc, char **argv)
{
	int		*nums1;
	int		y;
	int		i;
	int		d;

	if (argc < 2)
		return (0);
	y = 0;
	nums1 = init(argv, &y);
	i = 0;
	while (i < y)
	{
		d = 0;
		while (d < i)
		{
			if (nums1[i] == nums1[d])
				exit (write(2, "Error\n", 6));
			d++;
		}
		i++;
	}
	checker(&nums1, &y);
	free(nums1);
	return (0);
}
