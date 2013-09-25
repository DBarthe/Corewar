/*
** asm_assamble.c for corewar - asm in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 14:42:19 2013 barthelemy delemotte
** Last update Sat Mar 30 16:14:50 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"my.h"

int		asm_assamble(t_list *file, const int fd, char *name_file)
{
  t_asm		*asm_datas;

  if (((asm_datas = asm_new(file, fd)) == NULL) ||
      (asm_fill_extra_datas(asm_datas) == RET_FAILURE) ||
      (asm_fill_len_and_labels(asm_datas) == RET_FAILURE) ||
      (asm_fill_code(asm_datas) == RET_FAILURE) ||
      (asm_write(asm_datas) == RET_FAILURE))
    {
      asm_free(asm_datas);
      return (RET_FAILURE);
    }
  asm_display(asm_datas, name_file);
  asm_free(asm_datas);
  return (RET_SUCCESS);
}
