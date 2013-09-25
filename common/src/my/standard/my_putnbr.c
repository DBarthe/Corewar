/*
** my_putnbr.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 01:02:10 2013 raphael defreitas
** Last update Sat Jan 26 01:03:13 2013 raphael defreitas
*/

#include	"my.h"

int		my_putnbr(int nbr)
{
  return (my_fputnbr_base(STD_OUTPUT, nbr, BASE_DEC));
}
