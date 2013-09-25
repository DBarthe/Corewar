/*
** my_list_item_new.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:12:34 2013 raphael defreitas
** Last update Thu Jan 31 16:29:47 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"my.h"

t_list_item	*my_list_item_new(t_list *list, void *data)
{
  t_list_item	*item;

  if ((item = my_calloc(sizeof(t_list_item))) == NULL)
    return (NULL);
  item->data = data;
  item->id = list->next_id++;
  return (item);
}
