/*
** my_list_length.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 13:52:48 2013 raphael defreitas
** Last update Mon Jan 28 13:53:35 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_list_length(t_list *list)
{
  if (list == NULL)
    return (RET_ERROR);
  return (list->length);
}
