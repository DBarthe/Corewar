/*
** my_list_peek_bot.c for libmy in /home/raphy/Developement/Libraries/libmy/list
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 14:10:22 2013 raphael defreitas
** Last update Mon Jan 28 14:10:59 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_list_peek_bot(t_list *list)
{
  if (list == NULL)
    return (NULL);
  return (list->top->data);
}
