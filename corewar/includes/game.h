/*
** game.h for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:12:35 2013 raphael defreitas
** Last update Sat Mar 30 14:31:59 2013 barthelemy delemotte
*/

#ifndef		GAME_H_
# define	GAME_H_

#include	"game_types.h"
#include	"params_types.h"
#include	"cpu_types.h"
#include	"my.h"

t_game		*game_new(void);
void		game_free(t_game *game);
int		game_init(t_game *game, t_params *params,
			  int cycles_to_die, int cycle_delta);
int		game_do_cycle(t_game *game, t_cpu *cpu);
int		game_set_players_id(t_game *game, t_list *programs);
t_bool		game_is_ended(t_game *game);
int		game_live(t_game *affect, int pid);
int		game_end(t_game *game);

#endif /* !GAME_H_ */
