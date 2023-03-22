/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chulee <chulee@nstek.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:28:39 by chulee            #+#    #+#             */
/*   Updated: 2023/03/22 18:19:54 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int	ntk_compare(const void *x, const void *y)
{
	const char *str_x = x;
	const char *str_y = y;

	while (*str_x != '\0' || *str_y != '\0')
	{
		if (*str_x != *str_y)
			return (*str_x - *str_y);
		str_x++;
		str_y++;
	}
	return (0);
}

unsigned int ntk_hash(const void *__key)
{
	const char	*key = __key;

	return ((unsigned long)key[0] % 10000);
}

void	ntk_put_table(Table *table, const char *__key, int __value)
{
	char	*key = malloc(strlen(__key) + 1);
	int		*value = malloc(sizeof(int));
	int		*prev;

	assert(key != NULL && value != NULL);
	*value = __value;
	strcpy(key, __key);
	prev = put_table(table, key, value);
	if (prev != NULL)
		free(prev);
}

int	main(void)
{
	Table	*table = new_table(10000, ntk_compare, ntk_hash);

	ntk_put_table(table, "192.168.0.1", 123);
	ntk_put_table(table, "192.168.100.84", 456);
	printf("192.168.0.1 = %d", *((int *)get_table(table, "192.168.0.1")));
	free_table(table);
	return (0);
}
