/*
** brain_run.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 18:49:00 2013 barthelemy delemotte
** Last update Fri Apr  5 18:30:13 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	<time.h>
#include	"my.h"
#include	"brain.h"
#include	"game.h"
#include	"cpu.h"
#include	"graphic.h"

int		brain_run(t_brain *brain)
{
  if (brain == NULL)
    return (RET_FAILURE);
  if ((brain_put_programs(brain)) == RET_FAILURE)
    return (RET_FAILURE);
  while (game_is_ended(brain->game) == false)
    {
      if (cpu_execution(brain->cpu, brain->game, brain->ram) == RET_FAILURE)
	return (RET_FAILURE);
      if (game_do_cycle(brain->game, brain->cpu) == RET_FAILURE)
	return (RET_FAILURE);
    }
  game_end(brain->game);
  return (RET_SUCCESS);
}

static t_bool	has_to_stop(t_bool *stopped)
{
  SDL_Event	event;

  if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT ||
	  (event.type == SDL_KEYDOWN &&
	   event.key.keysym.sym == SDLK_ESCAPE))
	{
	  *stopped = true;
	  return (true);
	}
    }
  *stopped = false;
  return (false);
}

static t_bool	pause_x()
{
  SDL_Event	event;

  SDL_WaitEvent(&event);
  if (event.type == SDL_QUIT ||
      (event.type == SDL_KEYDOWN &&
       event.key.keysym.sym == SDLK_ESCAPE))
    return (false);
  return (true);
}

static int		brain_run_x_loop(t_brain *brain)
{
  static int	counter = 0;
  int		winner_no;
  t_bool	stopped;

  stopped = false;
  while (!stopped && game_is_ended(brain->game) == false)
    {
      if (cpu_execution(brain->cpu, brain->game, brain->ram) == RET_FAILURE)
	return (RET_ERROR);
      if (game_do_cycle(brain->game, brain->cpu) == RET_FAILURE)
	return (RET_ERROR);
      has_to_stop(&stopped);
      counter++;
      if (counter >= REFRESH)
	{
	  graphic_handler_update(NULL);
	  counter = 0;
	}
    }
  winner_no = game_end(brain->game);
  while (!stopped && pause_x());
  return (winner_no > RET_ERROR ?
	  brain->game->players_id[winner_no] : 0);
}

int		brain_run_x(t_brain *brain)
{
  t_graphic	*graphic;
  int		winner_no;

  if (brain == NULL)
    return (RET_ERROR);
  if ((graphic = graphic_new()) == NULL ||
      graphic_init(graphic, brain->programs) == RET_FAILURE)
    return (RET_ERROR);
  brain->ram->hook_set = &graphic_handler_ram_set;
  brain->game->hook_winner = &graphic_handler_winner;
  brain->game->hook_cycles = &graphic_handler_cycles;
  brain->cpu->hook_process = &graphic_handler_process;
  brain->game->hook_cycles_to_die = &graphic_handler_cycles_to_die;
  graphic_init_handlers(graphic);
  graphic_handler_process(NULL, brain->game->players_nbr);
  graphic_handler_cycles_to_die(NULL, brain->game->cycles_to_die);
  if ((brain_put_programs(brain)) == RET_FAILURE)
    return (RET_ERROR);
  if ((winner_no = brain_run_x_loop(brain)) == RET_ERROR)
    return (RET_ERROR);
  graphic_free(graphic);
  return (winner_no);
}
