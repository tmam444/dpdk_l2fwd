/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chulee <chulee@nstek.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:45:43 by chulee            #+#    #+#             */
/*   Updated: 2023/03/27 16:45:34 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>
# include <assert.h>

typedef struct s_list {
	void			*value;
	struct s_list	*next;
} list;

list*	create_list(void *value);
list*	list_push(list *lst, void *value);

#endif
