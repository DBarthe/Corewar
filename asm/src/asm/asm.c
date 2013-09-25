/*
** asm.c for corewar - asm in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 15:11:54 2013 barthelemy delemotte
** Last update Sun Mar 31 09:51:30 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"my.h"
#include	"asm.h"

t_asm		*asm_new(t_list *file, const int fd)
{
  t_asm		*asm_datas;

  asm_datas = xmalloc(sizeof(t_asm));
  asm_datas->file = file;
  asm_datas->labels = my_list_new(LIST_LINKED, &label_free);
  asm_datas->fd = fd;
  asm_datas->name = NULL;
  asm_datas->comment = NULL;
  asm_datas->code = NULL;
  asm_datas->code_len = 0;
  return (asm_datas);
}

void		asm_free(t_asm *asm_datas)
{
  if (asm_datas)
    {
      if (asm_datas->name)
	free(asm_datas->name);
      if (asm_datas->comment)
	free(asm_datas->comment);
      if (asm_datas->file)
	my_list_free(asm_datas->file);
      if (asm_datas->labels)
	my_list_free(asm_datas->labels);
      if (asm_datas->code)
	free(asm_datas->code);
    }
  free(asm_datas);
}
