/*
** my_list_free.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:09:37 2013 raphael defreitas
** Last update Sun Jan 27 18:24:38 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

void		my_list_free(t_list *list)
{
  t_list_item	*next;

  if (list == NULL)
    return ;
  while (list->top)
    {
      next = list->top->next;
      my_list_item_free(list, list->top);
      list->top = next;
    }
  free(list);
}
