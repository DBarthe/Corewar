/*
** my_list_swap.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 11:36:56 2013 raphael defreitas
** Last update Mon Jan 28 11:55:46 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_list_swap(t_list_item *item1, t_list_item *item2)
{
  void		*tmp;
  int		id;

  if (item1 == NULL || item2 == NULL)
    return (RET_FAILURE);
  tmp = item1->data;
  id = item1->id;
  item1->data = item2->data;
  item1->id = item2->id;
  item2->data = tmp;
  item2->id = id;
  return (RET_SUCCESS);
}
