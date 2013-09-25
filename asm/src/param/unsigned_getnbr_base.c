/*
** unsigned_getnbr_base.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Sat Mar 30 13:13:03 2013 marie lefebvre
** Last update Sat Mar 30 14:11:57 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"my.h"

static int	find_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i])
    {
      if (c == base[i])
	return (i);
      i++;
    }
  return (RET_ERROR);
}

static int	unsigned_calculate(char *nbr, char *base, int i, t_bool is_neg)
{
  unsigned int	res;
  int		len;
  int		ret;

  len = my_strlen(base);
  res = 0;
  while (nbr[i])
    {
      res *= len;
      if ((ret = find_base(nbr[i], base)) == RET_ERROR)
	return (0);
      res += ret;
      i++;
    }
  return ((int)res);
}

int		unsigned_getnbr_base(char *nbr, char *base)
{
  int		i;
  t_bool	is_neg;
  int		res;

  if (nbr == NULL || base == NULL)
    return (0);
  is_neg = false;
  i = 0;
  while (nbr[i] == '-' || nbr[i] == '+')
    if (nbr[i++] == '-')
      is_neg = !is_neg;
  res = unsigned_calculate(nbr, base, i, is_neg);
  return ((is_neg) ? -res : res);
}
