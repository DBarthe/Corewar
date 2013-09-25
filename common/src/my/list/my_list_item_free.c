/*
** my_list_item_free.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:09:37 2013 raphael defreitas
** Last update Sun Jan 27 18:24:06 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

void		my_list_item_free(t_list *list, t_list_item *item)
{
  if (list == NULL || item == NULL)
    return ;
  if (list->data_free_fptr)
    list->data_free_fptr(item->data);
  free(item);
}
