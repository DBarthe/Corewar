/*
** my_fputnbr_base.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 00:56:05 2013 raphael defreitas
** Last update Sat Jan 26 01:07:26 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_fputnbr_base(const int fd, int nbr, const char *base)
{
  int		strlen;
  int		divi;
  int		baselen;

  if (base == NULL)
    return (RET_ERROR);
  baselen = my_strlen(base);
  strlen = 0;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
      strlen++;
    }
  divi = 1;
  while ((nbr / divi) >= baselen)
    divi *= baselen;
  while (divi)
    {
      my_fputchar(fd, base[(nbr / divi) % baselen]);
      divi /= baselen;
      strlen++;
    }
  return (strlen);
}
