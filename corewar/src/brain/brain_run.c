/*
** brain_run.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 18:49:00 2013 barthelemy delemotte
** Last update Fri Apr  5 17:53:11 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"brain.h"
#include	"game.h"
#include	"cpu.h"

int		brain_run(t_brain *brain)
{
  int		no;

  if (brain == NULL)
    return (RET_FAILURE);
  if ((brain_put_programs(brain)) == RET_ERROR)
    return (RET_FAILURE);
  while (game_is_ended(brain->game) == false)
    {
      if (cpu_execution(brain->cpu, brain->game, brain->ram) == RET_FAILURE)
	return (RET_ERROR);
      if (game_do_cycle(brain->game, brain->cpu) == RET_FAILURE)
	return (RET_ERROR);
    }
  no = game_end(brain->game);
  return (no < 0 ? no : brain->game->players_id[no]);
}
