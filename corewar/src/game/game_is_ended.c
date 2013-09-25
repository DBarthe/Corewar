/*
** game_is_ended.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 19:38:09 2013 barthelemy delemotte
** Last update Sat Mar 16 22:54:32 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"game.h"

static t_bool	one_max_players_in_life(t_game *game)
{
  int		i;
  int		nbr;

  nbr = 0;
  i = 0;
  while (i < game->players_nbr)
    {
      if (game->players_lives[i] >= 0)
	nbr++;
      i++;
    }
  if (nbr > 1)
    return (false);
  return (true);
}

t_bool		game_is_ended(t_game *game)
{
  if (game == NULL)
    return (true);
  if (one_max_players_in_life(game) == true)
    return (true);
  if (game->current_cycle >= game->dump_cycle)
    return (true);
  return  (false);
}
