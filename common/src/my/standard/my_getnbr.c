/*
** my_getnbr.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 01:19:21 2013 raphael defreitas
** Last update Sat Jan 26 01:19:47 2013 raphael defreitas
*/

#include	"my.h"

int		my_getnbr(const char *str)
{
  return (my_getnbr_base(str, BASE_DEC));
}
