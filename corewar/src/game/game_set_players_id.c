/*
** game_set_players_id.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/game
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 19:27:04 2013 barthelemy delemotte
** Last update Fri Mar  8 19:33:16 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"game.h"
#include	"program.h"

int		game_set_players_id(t_game *game, t_list *programs)
{
  t_list_item	*item;
  t_program	*prog;
  int		i;

  if (game == NULL || programs == NULL)
    return (RET_FAILURE);
  item = programs->top;
  i = 0;
  while (item && i < game->players_nbr)
    {
      prog = item->data;
      if (prog != NULL)
	{
	  game->players_id[i] = prog->player_id;
	  i++;
	}
      item = item->next;
    }
  return (RET_SUCCESS);
}
