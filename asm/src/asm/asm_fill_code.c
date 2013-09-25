/*
** asm_fill_code.c for corewar - asm in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 16:01:17 2013 barthelemy delemotte
** Last update Sat Mar 30 16:49:47 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"instruction.h"
#include	"my.h"

int		asm_fill_code(t_asm *asm_d)
{
  t_list_item	*instruct_line;
  char		*line;
  t_code	*code;

  code = xmalloc(sizeof(t_code));
  code->str = xmalloc(sizeof(char) * asm_d->code_len);
  code->idx = 0;
  instruct_line = asm_d->file->top;
  while (instruct_line != NULL)
    {
      line = instruct_line->data;
      code->idx_line = code->idx;
      if (line && line[0] != '\0')
	if (instruction(asm_d->labels, line, code) == RET_FAILURE)
	  {
	    if (code->str)
	      free(code->str);
	    free(code);
	    return (RET_FAILURE);
	  }
      instruct_line = instruct_line->next;
    }
  asm_d->code = code->str;
  free(code);
  return (RET_SUCCESS);
}
