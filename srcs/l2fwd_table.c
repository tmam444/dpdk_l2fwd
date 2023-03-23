/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l2fwd_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chulee <chulee@nstek.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:28:39 by chulee            #+#    #+#             */
/*   Updated: 2023/03/23 18:20:09 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l2fwd.h"

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
	const char		*key = __key;
    unsigned long	hash = 5381;
    int c;

    while ((c = *key++))
        hash = (((hash << 5) + hash) + c) % TABLE_SIZE;
    return (hash % TABLE_SIZE);
}

void	ntk_put_table(Table *table, const char *__key, uint64_t packet_size, enum e_direction type)
{
	statistics	*prev_value = get_table(table, __key);
	char		*key = malloc(strlen(__key) + 1);
	statistics	*value = malloc(sizeof(statistics));

	assert(key != NULL && value != NULL);
	if (prev_value != NULL)
		memcpy(value, prev_value, sizeof(statistics));
	else
		memset(value, 0, sizeof(statistics));
	if (type == RX)
		value->rx += packet_size;
	else if (type == TX)
		value->tx += packet_size;
	strcpy(key, __key);
	prev_value = put_table(table, key, value);
	if (prev_value != NULL)
		free(prev_value);
}

/*
int	main(void)
{
	Table		*table = new_table(TABLE_SIZE, ntk_compare, ntk_hash);
	statistics	*cur_statistics;
	const void	**keys;
	const char	**temp;

	ntk_put_table(table, "192.168.0.1", 123, RX);
	ntk_put_table(table, "192.168.100.84", 456, RX);
	cur_statistics = get_table(table, "192.168.0.1");
	printf("192.168.0.1 = rx:%lu, tx:%lu\n", cur_statistics->rx, cur_statistics->tx);
	keys = key_set(table);
	temp = (const char **)keys;
	while (*temp != NULL)
	{
		printf("%s aa\n", *temp);
		temp++;
	}
	free(keys);
	free_table(table);
	return (0);
}
*/
