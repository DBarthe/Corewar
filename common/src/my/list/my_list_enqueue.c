/*
** my_list_enqueue.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:27:25 2013 raphael defreitas
** Last update Sun Jan 27 18:35:14 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_list_enqueue(t_list *list, void *data)
{
  t_list_item	*item;

  if ((item = my_list_item_new(list, data)) == NULL)
    return (RET_FAILURE);
  item->previous = list->bot;
  if (list->bot)
    list->bot->next = item;
  list->bot = item;
  if (list->top == NULL)
    list->top = item;
  list->length++;
  return (RET_SUCCESS);
}
