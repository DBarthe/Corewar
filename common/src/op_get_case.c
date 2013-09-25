/*
** op_get_case.c for corewar - common in /home/delemo_b/epitech_1/corewar/common/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sun Mar 10 12:16:24 2013 barthelemy delemotte
** Last update Sat Mar 30 15:55:43 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"

static t_bool	op_cmp_opcode(t_op *op_case, const char *p_opcode)
{
  if (op_case->code == *p_opcode)
    return (true);
  return (false);
}

static t_bool	op_cmp_mnemonique(t_op *op_case, const char *p_mne)
{
  if (my_strcmp(op_case->mnemonique, p_mne) == 0)
    return (true);
  return (false);
}

static t_op	*op_get(t_bool (*fcmp)(t_op *, const void *),
			const char *param)
{
  int		i;
  t_op		*op_case;

  i = 0;
  while (i < 16)
    {
      op_case = op_tab + i;
      if (fcmp(op_case, param) == true)
	return  (op_case);
      i++;
    }
  return (NULL);
}

t_op		*op_get_by_opcode(const char opcode)
{
  return (op_get((t_bool (*)(t_op *, const void *))(&op_cmp_opcode),
		 &opcode));
}

t_op		*op_get_by_mnemonique(const char *mne)
{
  return (op_get((t_bool (*)(t_op *, const void *))(&op_cmp_mnemonique),
		 mne));
}
