/*
** ram_put_program.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/ram
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Feb  2 15:39:21 2013 barthelemy delemotte
** Last update Fri Mar 29 13:13:10 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"ram.h"
#include	"program.h"
#include	"op.h"

int		ram_put_program(t_ram *ram, t_program *program)
{
  int		i;

  if (ram == NULL || program == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < program->code_len)
    {
      ram->arena[(program->load_addr + i) % MEM_SIZE] = program->code[i];
      i++;
    }
  ram->last_user_no = program->player_id;
  ram_hook_set(ram, program->load_addr, program->code_len);
  return (RET_SUCCESS);
}
