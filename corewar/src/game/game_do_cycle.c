/*
** game_do_cycle.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 19:00:45 2013 barthelemy delemotte
** Last update Fri Apr  5 18:27:21 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"game.h"
#include	"cpu.h"

static int	check_players_lives(t_game *game, t_cpu *cpu)
{
  int		i;

  i = 0;
  while (i < game->players_nbr)
    {
      if (game->players_lives[i] != -1)
	{
	  if (game->current_cycle - game->players_lives[i]
	      >= game->cycles_to_die)
	    {
	      game->players_lives[i] = -1;
	      cpu_kill_process(cpu, game->players_id[i]);
	    }
	}
      i++;
    }
  return (RET_SUCCESS);
}

int		game_do_cycle(t_game *game, t_cpu *cpu)
{
  if (game == NULL || cpu == NULL)
    return (RET_FAILURE);
  check_players_lives(game, cpu);
  if (game->counter_live >= game->nbr_live)
    {
      game->cycles_to_die -= game->cycle_delta;
      if (game->hook_cycles_to_die)
	game->hook_cycles_to_die(NULL, game->cycles_to_die);
      game->counter_live = 0;
    }
  game->current_cycle++;
  if (game->hook_cycles)
    game->hook_cycles(NULL, game->current_cycle);
  return (RET_SUCCESS);
}
