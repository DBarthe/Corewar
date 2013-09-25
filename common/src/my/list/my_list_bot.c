/*
** my_list_bot.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:37:31 2013 raphael defreitas
** Last update Sun Jan 27 18:49:18 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_list_bot(t_list *list)
{
  void		*data;
  t_list_item	*previous;

  if (list == NULL || list->bot == NULL)
    return (NULL);
  data = list->bot->data;
  previous = list->bot->previous;
  free(list->bot);
  if (previous)
    previous->next = NULL;
  else
    list->top = NULL;
  list->bot = previous;
  list->length--;
  return (data);
}
