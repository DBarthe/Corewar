/*
** instruction_get_next.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sun Mar 10 12:10:37 2013 barthelemy delemotte
** Last update Sat Mar 16 22:45:27 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"
#include	"op.h"
#include	"error.h"

static int	get_args_len(t_op *op_case, char *arena, int pc)
{
  int		len;
  unsigned char	i;
  unsigned char	bits;

  len = 0;
  i = 0;
  while (i < op_case->nbr_args)
    {
      bits = arena[(pc + 1) % MEM_SIZE] & (0x3 << ((3 - i) * 2));
      if (bits == (POC_REG << (3 - i) * 2))
	len += 1;
      else if (bits == (POC_DIR << (3 - i) * 2))
	len += DIR_SIZE;
      else if (bits == (POC_IND << (3 - i) * 2))
	len += IND_SIZE;
      i++;
    }
  return (len);
}

static int	get_instuction_len(t_op *op_case, char *arena, int pc)
{
  int		len;

  if (op_case->code == 0x01)
    return (5);
  else if (op_case->code == 0x09 || op_case->code == 0x0c
	   || op_case->code == 0x0f)
    return (3);
  else if (op_case->code == 0x0a || op_case->code == 0x0e)
    {
      if ((arena[(pc + 1) % MEM_SIZE] & 0xc0) == 0x40)
	return (6);
      return (7);
    }
  else if (op_case->code == 0x0b)
    {
      if ((arena[(pc + 1) % MEM_SIZE] & 0x3c) == 0x14)
	return (5);
      else if ((arena[(pc + 1) % MEM_SIZE] & 0x3c) == 0x10 ||
	       (arena[(pc + 1) % MEM_SIZE] & 0x3c) == 0x04)
	return (6);
      return (7);
    }
  len = 2 + get_args_len(op_case, arena, pc);
  return (len);
}

t_instruction	*instruction_get_next(t_ram *ram, int pc)
{
  t_instruction	*inst;
  char		opcode;
  t_op		*op_case;
  int		len;
  char		*data;
  int		i;

  opcode = ram->arena[pc % MEM_SIZE];
  if ((op_case = op_get_by_opcode(opcode)) == NULL)
    return (NULL);
  len = get_instuction_len(op_case, ram->arena, pc);
  if ((data = xmalloc(len * sizeof(char))) == NULL)
    return (error_ptr(NULL, ERR_MALLOC));
  i = 0;
  while (i < len)
    {
      data[i] = ram->arena[(pc + i) % MEM_SIZE];
     i++;
    }
  inst = instruction_new(data, len);
  return (inst);
}
