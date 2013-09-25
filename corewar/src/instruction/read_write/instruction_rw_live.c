/*
** instruction_rw_live.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 12:16:09 2013 barthelemy delemotte
** Last update Sat Mar 30 12:52:17 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"
#include	"instruction.h"
#include	"game.h"

int		instruction_r_live(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  if (instruction == NULL)
    return (RET_FAILURE);
  (void)ram;
  (void)process;
  instruction->argv[0] = instruction_get_val_dir(instruction->data + 1,
						 DIR_SIZE);
  return (RET_SUCCESS);
}

int		instruction_w_live(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  if (instruction == NULL)
    return (RET_FAILURE);
  (void)ram;
  (void)process;
  game_live(NULL, instruction->argv[0]);
  return (RET_SUCCESS);
}
