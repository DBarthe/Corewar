/*
** game_end.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar 16 19:27:09 2013 barthelemy delemotte
** Last update Fri Apr  5 17:40:47 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"game.h"

static t_bool	one_players_in_life(t_game *game)
{
  int		i;
  int		nbr;

  i = 0;
  nbr = 0;
  while (i < game->players_nbr)
    {
      if (game->players_lives[i] >= 0)
	nbr++;
      i++;
    }
  if (nbr == 1)
    return (true);
  return (false);
}

static int	get_last_players(t_game *game)
{
  int		i;

  i = 0;
  while (i < game->players_nbr)
    {
      if (game->players_lives[i] >= 0)
	return (i);
      i++;
    }
  return (RET_ERROR);
}

static int	get_winner(t_game *game)
{
  int		max_cycle;
  int		winner;
  int		i;

  winner = 0;
  max_cycle = game->players_lives[0];
  i = 1;
  while (i < game->players_nbr)
    {
      if (max_cycle <= game->players_lives[i])
	{
	  max_cycle = game->players_lives[i];
	  winner = i;
	}
      i++;
    }
  return (winner);
}

int		game_end(t_game *game)
{
  int		no;

  if (game == NULL)
    return (RET_ERROR);
  if (one_players_in_life(game) == true)
    no = get_last_players(game);
  else
    no = get_winner(game);
  if (game_is_ended(game) == true)
    {
      my_printf("le joueur %d(%s) a gagne\n",
		game->players_id[no],
		game->players_name[no]);
      if (game->hook_winner)
	game->hook_winner(NULL, game->players_id[no], game->players_name[no]);
    }
  else
    no = RET_ERROR;
  return (no);
}
