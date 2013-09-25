/*
** my_getnbr_base.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 01:03:57 2013 raphael defreitas
** Last update Sat Jan 26 01:36:24 2013 raphael defreitas
*/

#include	<limits.h>
#include	<stdlib.h>
#include	"my.h"

static int	calculate(const char *, const char *, int, t_bool);

int		my_getnbr_base(const char *nbr, const char *base)
{
  int		i;
  t_bool	is_neg;
  int		res;

  if (nbr == NULL || base == NULL)
    return (0);
  is_neg = false;
  i = 0;
  while (nbr[i] == '-' || nbr[i] == '+')
    {
      if (nbr[i] == '-')
	is_neg = !is_neg;
      i++;
    }
  res = calculate(nbr, base, i, is_neg);
  return ((is_neg) ? -res : res);
}

static int	calculate(const char *nbr, const char *base, int i,
			  t_bool is_neg)
{
  unsigned int	res;
  int           base_len;
  int           base_idx;

  base_len = my_strlen(base);
  res = 0;
  while ((base_idx = my_strpos(base, nbr[i])) != RET_ERROR)
    {
      res = (res * base_len) + base_idx;
      if ((is_neg && res > (unsigned int)INT_MAX + 1)
	  || (!is_neg && res > INT_MAX))
	return (0);
      i++;
    }
  return (res);
}
