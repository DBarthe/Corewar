/*
** game_init.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/game
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Feb  2 16:00:38 2013 barthelemy delemotte
** Last update Sat Mar 16 21:12:49 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"game.h"
#include	"params.h"
#include	"my.h"
#include	"error.h"
#include	"op.h"
#include	"program.h"

static char	**name_tab_init(t_game *game, t_params *params)
{
  char		**tab;
  int		i;
  t_list_item	*item;
  t_program	*program;

  if ((tab = xmalloc(game->players_nbr * sizeof(char *))) == NULL)
    return (NULL);
  item = params->programs->top;
  i = 0;
  while (item)
    {
      if ((program = item->data) != NULL)
	{
	  tab[i] = program->name;
	}
      i++;
      item = item->next;
    }
  return (tab);
}

int		game_init(t_game *game, t_params *params,
			  int cycles_to_die, int cycle_delta)
{
  if (cycles_to_die < 0 || cycle_delta < 0)
    return (error_int(RET_FAILURE, ERR_NEG_CYCLE_NBR));
  game->cycles_to_die = cycles_to_die;
  game->cycle_delta = cycle_delta;
  game->nbr_live = NBR_LIVE;
  game->dump_cycle = params->dump_cycle;
  if (game->dump_cycle == DUMP_UNDEF)
    game->dump_cycle = DEFAULT_DUMP_CYCLE;
  game->players_nbr = params->programs->length;
  game->players_lives = my_calloc(game->players_nbr * sizeof(int));
  game->players_id = my_calloc(game->players_nbr * sizeof(int));
  game->players_name = name_tab_init(game, params);
  if (game->players_lives == NULL || game->players_id == NULL
      || game->players_name == NULL)
    return (error_int(RET_FAILURE, ERR_MALLOC));
  game_live(game, 0);
  return (RET_SUCCESS);
}
