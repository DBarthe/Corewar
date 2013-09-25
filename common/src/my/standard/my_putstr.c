/*
** my_putstr.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jan 25 22:55:27 2013 raphael defreitas
** Last update Fri Jan 25 22:55:49 2013 raphael defreitas
*/

#include	"my.h"

int		my_putstr(const char *str)
{
  return (my_fputstr(STD_OUTPUT, str));
}
