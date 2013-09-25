/*
** brain_load.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/brain
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Feb  2 16:29:33 2013 barthelemy delemotte
** Last update Sat Mar 30 12:06:41 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"brain.h"
#include	"game.h"
#include	"cpu.h"
#include	"params.h"
#include	"ram.h"
#include	"program.h"
#include	"op.h"

static int	init_units(t_brain *brain, t_params *params)
{
  if (program_list_init(brain->programs) != RET_SUCCESS)
    return (RET_FAILURE);
  if (game_init(brain->game, params, CYCLE_TO_DIE, CYCLE_DELTA) != RET_SUCCESS)
    return (RET_FAILURE);
  if (ram_init(brain->ram, MEM_SIZE) != RET_SUCCESS)
    return (RET_FAILURE);
  if (cpu_create_processes(brain->cpu, brain->programs) == RET_FAILURE)
    return (RET_FAILURE);
  if (game_set_players_id(brain->game, brain->programs) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		brain_load(t_brain *brain, t_params *params)
{
  brain->programs = params->programs;
  if ((brain->game = game_new()) == NULL)
    return (RET_FAILURE);
  if ((brain->cpu = cpu_new()) == NULL)
    return (RET_FAILURE);
  if ((brain->ram = ram_new()) == NULL)
    return (RET_FAILURE);
  if (init_units(brain, params) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
