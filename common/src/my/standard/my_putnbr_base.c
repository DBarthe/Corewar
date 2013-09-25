/*
** my_putnbr_base.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 00:59:00 2013 raphael defreitas
** Last update Sat Jan 26 01:03:38 2013 raphael defreitas
*/

#include	"my.h"

int		my_putnbr_base(int nbr, const char *base)
{
  return (my_fputnbr_base(STD_OUTPUT, nbr, base));
}
