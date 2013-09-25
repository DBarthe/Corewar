/*
** my_fputnbr.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 01:00:08 2013 raphael defreitas
** Last update Sat Jan 26 01:00:46 2013 raphael defreitas
*/

#include	"my.h"

int		my_fputnbr(const int fd, int nbr)
{
  return (my_fputnbr_base(fd, nbr, BASE_DEC));
}
