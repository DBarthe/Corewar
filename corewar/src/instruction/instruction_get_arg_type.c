/*
** instruction_get_arg_type.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sun Mar 10 15:54:10 2013 barthelemy delemotte
** Last update Thu Mar 14 23:58:59 2013 barthelemy delemotte
*/

#include	"instruction.h"
#include	"my.h"

char		instruction_get_arg_type(char *poc, int no)
{
  unsigned char	bits;
  unsigned char	upoc;

  upoc = *poc;
  if (no > 4 || no < 1)
    return (0);
  bits = upoc & (0x3 << (3 - (no - 1)) * 2);
  if (bits == (POC_REG << (3 - (no - 1)) * 2))
    return (T_REG);
  else if (bits == (POC_DIR << (3 - (no - 1)) * 2))
    return (T_DIR);
  else if (bits == (POC_IND << (3 - (no - 1)) * 2))
    return (T_IND);
  return (0);
}

char		instruction_get_arg_poc(char *poc, int no)
{
  unsigned char	bits;
  unsigned char	upoc;

  upoc = *poc;
  if (no > 4 || no < 1)
    return (0);
  bits = upoc & (0x3 << (3 - (no - 1)) * 2);
  if (bits == (POC_REG << (3 - (no - 1)) * 2))
    return (POC_REG);
  else if (bits == (POC_DIR << (3 - (no - 1)) * 2))
    return (POC_DIR);
  else if (bits == (POC_IND << (3 - (no - 1)) * 2))
    return (POC_IND);
  return (0);
}
