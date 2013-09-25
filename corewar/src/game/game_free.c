/*
** game_free.c for corewar in /media/home/Projects/prog_elem/corewar/corewar
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 22:51:37 2013 raphael defreitas
** Last update Tue Mar 12 20:29:09 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"game.h"

void		game_free(t_game *game)
{
  if (game != NULL)
    {
      if (game->players_lives != NULL)
	free(game->players_lives);
      if (game->players_id != NULL)
	free(game->players_id);
      if (game->players_name != NULL)
	free(game->players_name);
      free(game);
    }
}
