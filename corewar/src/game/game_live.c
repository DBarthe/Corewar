/*
** game_live.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/game
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 19:49:42 2013 barthelemy delemotte
** Last update Sat Mar 16 22:38:53 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"game.h"

static int	get_player_idx(t_game *game, int pid)
{
  int		i;

  i = 0;
  while (i < game->players_nbr)
    {
      if (game->players_id[i] == pid)
	return (i);
      i++;
    }
  return (RET_ERROR);
}

int		game_live(t_game *affect, int pid)
{
  static t_game	*game = NULL;
  int		ret;
  int		idx;

  ret = RET_SUCCESS;
  if (affect != NULL)
    game = affect;
  else if (game && (idx = get_player_idx(game, pid)) >= 0)
    {
      my_printf("le joueur %d(%s) est en vie\n",
		pid, game->players_name[idx]);
      game->counter_live++;
      game->players_lives[idx] = game->current_cycle;
    }
  else
    ret = RET_FAILURE;
  return (ret);
}
