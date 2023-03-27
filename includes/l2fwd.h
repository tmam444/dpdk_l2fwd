/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l2fwd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chulee <chulee@nstek.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:08:53 by chulee            #+#    #+#             */
/*   Updated: 2023/03/27 11:59:59 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L2FWD_H
# define L2FWD_H
# include "table.h"
# include <stdint.h>
# include <string.h>

enum e_direction {
	RX,
	TX
};

typedef struct s_statistics {
	uint64_t	tx;
	uint64_t	rx;
} statistics;

int				ntk_compare(const void *x, const void *y);
void			ntk_put_table(Table *table, const char *__key, uint64_t __value, enum e_direction type);
unsigned int	ntk_hash(const void *__key);

#endif
