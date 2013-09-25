/*
** game_new.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/game
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:32:18 2013 raphael defreitas
** Last update Fri Apr  5 18:25:41 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"game.h"

t_game		*game_new(void)
{
  t_game	*game;

  if ((game = xmalloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->cycles_to_die = 0;
  game->cycle_delta = 0;
  game->current_cycle = 1;
  game->players_nbr = 0;
  game->nbr_live = 0;
  game->counter_live = 0;
  game->players_lives = NULL;
  game->players_id = NULL;
  game->players_name = NULL;
  game->hook_winner = NULL;
  game->hook_cycles = NULL;
  game->hook_cycles_to_die = NULL;
  return (game);
}
