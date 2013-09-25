/*
** my_list_delete.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 14:03:43 2013 raphael defreitas
** Last update Sun Mar 31 21:20:03 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_list_delete(t_list *list, t_list_item *item)
{
  if (list == NULL || item == NULL)
    return (RET_FAILURE);
  if (list->top == item)
    list->top = item->next;
  if (list->bot == item)
    list->bot = item->previous;
  if (item->previous)
    item->previous->next = item->next;
  if (item->next)
    item->next->previous = item->previous;
  my_list_item_free(list, item);
  list->length--;
  return (RET_SUCCESS);
}
