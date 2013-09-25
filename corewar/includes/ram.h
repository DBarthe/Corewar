/*
** ram.h for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 17:12:08 2013 barthelemy delemotte
** Last update Sat Mar 30 14:37:00 2013 barthelemy delemotte
*/

#ifndef		RAM_H_
# define	RAM_H_

#include	"ram_types.h"
#include	"program_types.h"
#include	"my.h"

t_ram		*ram_new(void);
void		ram_free(t_ram *ram);
int		ram_init(t_ram *ram, int mem_size);
int		ram_put_program(t_ram *ram, t_program *program);
int		ram_put_program_list(t_ram *ram, t_list *program_list);
int		ram_dump(t_ram *ram);
char		ram_get(t_ram *ram, int idx);
int		ram_get_n_in_buffer(t_ram *ram, int idx, char *buffer, int n);
int		ram_set(t_ram *ram, int idx, char value);
int		ram_set_n(t_ram *ram, int idx, char *values, int n);
int		ram_set_int32(t_ram *ram, int idx, int values);
int		ram_hook_set(t_ram *ram, int idx, int n);

#endif /* !RAM_H_ */
