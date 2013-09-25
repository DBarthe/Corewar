/*
** my_list_new.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 18:02:54 2013 raphael defreitas
** Last update Sun Jan 27 18:09:16 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

t_list		*my_list_new(t_list_mode mode, void (*data_free_fptr)())
{
  t_list	*list;

  if ((list = my_calloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->mode = mode;
  if (data_free_fptr)
    list->data_free_fptr = data_free_fptr;
  return (list);
}
