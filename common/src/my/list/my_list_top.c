/*
** my_list_top.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:37:31 2013 raphael defreitas
** Last update Sun Jan 27 18:45:15 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_list_top(t_list *list)
{
  void		*data;
  t_list_item	*next;

  if (list == NULL || list->top == NULL)
    return (NULL);
  data = list->top->data;
  next = list->top->next;
  free(list->top);
  if (next)
    next->previous = NULL;
  else
    list->bot = NULL;
  list->top = next;
  list->length--;
  return (data);
}
