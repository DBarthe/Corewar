/*
** game_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:49:29 2013 barthelemy delemotte
** Last update Fri Apr  5 18:25:22 2013 barthelemy delemotte
*/

#ifndef		GAME_TYPES_H_
# define	GAME_TYPES_H_

#define		DEFAULT_DUMP_CYCLE	10000000
#define		DUMP_UNDEF		-2

typedef struct
{
  int		cycles_to_die;
  int		cycle_delta;
  int		nbr_live;
  int		counter_live;
  int		dump_cycle;
  int		players_nbr;
  char		**players_name;
  int		*players_id;
  int		*players_lives;
  int		current_cycle;
  void		(*hook_winner)();
  void		(*hook_cycles)();
  void		(*hook_cycles_to_die)();
}		t_game;

#endif /* !GAME_TYPES_H_ */
