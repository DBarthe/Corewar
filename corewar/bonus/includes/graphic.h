/*
** graphic.h for corewar in /home/raphy/Developement/tmp/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 27 16:27:41 2013 raphael defreitas
<<<<<<< HEAD
** Last update Fri Apr  5 19:15:49 2013 raphael defreitas
=======
** Last update Fri Apr  5 17:13:53 2013 barthelemy delemotte
>>>>>>> 7dee79281eb6a84f6985bf2665e1aafff72ac6f9
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

#include	"my.h"
#include	"graphic_types.h"

#define		WIN_W		1200
#define		WIN_H		892
#define		SQR_W		10
#define		SQR_H		10
#define		MAX_COLORS	12
#define		REFRESH		31

t_graphic	*graphic_new();
int		graphic_init(t_graphic *graphic, t_list *programs);
void		graphic_free(t_graphic *graphic);
void		graphic_init_handlers(t_graphic *graphic);
void		graphic_handler_ram_set(t_graphic *graphic, int player, int mem);
void		graphic_handler_cycles(t_graphic *graphic, int cycles);
void		graphic_handler_process(t_graphic *graphic, int process);
void		graphic_handler_cycles_to_die(t_graphic *graphic, int cycles_to_die);
void		graphic_handler_winner(t_graphic *graphic, int, const char *);
void		graphic_handler_update(t_graphic *graphic);
void		graphic_update(t_graphic *graphic);
void		graphic_write_players(t_graphic *graphic);
void		graphic_write_cycles(t_graphic *graphic);
void		graphic_write_process(t_graphic *graphic);
void		graphic_write_cycles_to_die(t_graphic *graphic);
void		graphic_write_cycle_delta(t_graphic *graphic);

#endif /* !GRAPHIC_H_ */
