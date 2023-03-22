/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chulee <chulee@nstek.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:22:40 by chulee            #+#    #+#             */
/*   Updated: 2023/03/22 17:39:58 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include <string.h>

typedef struct Node {
	const void	*key;
	void		*value;
	struct Node	*next;
} Node;

typedef struct Table {
	int				size;
	int				length;
	int				(*cmp)(const void *x, const void *y);
	unsigned int	(*hash)(const void *key);
	struct Node		**buckets;
} Table;

Table*	new_table(unsigned int size, int cmp(const void *x, const void *y), unsigned int hash(const void *key));
void*	get_table(Table *table, const void *key);
void*	put_table(Table *table, const void *key, void *value);
void	free_table(Table *table);

#endif
