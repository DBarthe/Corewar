/*
** instruction_get_val.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 17:36:15 2013 barthelemy delemotte
** Last update Fri Mar 29 12:47:07 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"
#include	"op.h"
#include	"ram.h"
#include	"process.h"

static int	put_sign(int val, int n)
{
  int		i;
  int		smask;
  int		lmask;

  smask = 0x80;
  lmask = 0xff;
  i = 1;
  while (i < n)
    {
      lmask = (lmask << 8) + 0xff;
      smask <<= 8;
      i++;
    }
  if ((val & smask) && n < 4)
    {
      val |= ~lmask;
    }
  return (val);
}

int		instruction_get_val_dir(char *ptr, int n)
{
  unsigned int	tmp;
  int		val;
  int		i;

  i = 0;
  tmp = 0;
  while (i < n)
    {
      tmp = tmp << 8;
      tmp |= (ptr[i] & 0xff);
      i++;
    }
  val = (int)tmp;
  return (put_sign(val, n));
}

int		instruction_get_val_ind_mod(char *ptr, int n, t_ram *ram, int pc)
{
  int		addr;
  int		val;
  int		i;
  unsigned int	tmp;

  addr = instruction_get_val_dir(ptr, IND_SIZE);
  i = 0;
  tmp = 0;
  while (i < n)
    {
      tmp = tmp << 8;
      tmp |= (ram_get(ram, pc + ((addr + i) % IDX_MOD)) & 0xff);
      i++;
    }
  val = (int)tmp;
  return (put_sign(val, n));
}

int		instruction_get_val_ind(char *ptr, int n, t_ram *ram, int pc)
{
  int		addr;
  int		val;
  int		i;

  addr = instruction_get_val_dir(ptr, IND_SIZE);
  i = 0;
  val = 0;
  while (i < n)
    {
      val = val << 8;
      val += (ram_get(ram, pc + addr + i) & 0xff);
      i++;
    }
  return (put_sign(val, n));
}

int		instruction_get_val_reg(char *ptr, int n, t_process *process)
{
  int		val;
  int		reg_no;
  int		mask;

  reg_no = instruction_get_val_dir(ptr, 1);
  val = process_get_registre(process, reg_no);
  mask = 0;
  if (n == 1)
    mask = 0x000000ff;
  else if (n == 2)
    mask = 0x0000ffff;
  else if (n == 3)
    mask = 0x00ffffff;
  else if (n == 4)
    mask = 0xffffffff;
  return (put_sign(val & mask, n));
}
