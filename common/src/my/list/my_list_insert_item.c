/*
** my_list_insert_item.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 11:40:22 2013 raphael defreitas
** Last update Mon Jan 28 11:59:01 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_list_insert_item(t_list *list, t_list_item *ref,
				    t_list_item *item)
{
  if (list == NULL || ref == NULL || item == NULL)
    return (RET_FAILURE);
  item->previous = ref;
  item->next = ref->next;
  ref->next = item;
  return (RET_SUCCESS);
}
