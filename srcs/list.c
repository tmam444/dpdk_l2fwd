/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chulee <chulee@nstek.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:46 by chulee            #+#    #+#             */
/*   Updated: 2023/03/27 16:57:06 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

list*	create_list(void *value)
{
	list	*ret;

	ret = malloc(sizeof(list));
	assert(ret != NULL);
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

list*	list_push(list *lst, void *value)
{
	list	*ret;

	ret = create_list(value);
	ret->next = lst;
	return (ret);
}
