/*
** my_list_reverse.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 13:54:25 2013 raphael defreitas
** Last update Mon Jan 28 14:24:52 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_list_reverse(t_list *list)
{
  int		i;
  t_list_item	*item1;
  t_list_item	*item2;

  if (list == NULL)
    return (RET_ERROR);
  item1 = list->top;
  item2 = list->bot;
  i = 0;
  while (i < my_list_length(list) / 2)
    {
      if (my_list_swap(item1, item2) == RET_FAILURE)
        return (RET_FAILURE);
      item1 = item1->next;
      item2 = item2->previous;
      i++;
    }
  return (RET_SUCCESS);
}
