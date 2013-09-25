/*
** brain_init.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/brain
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Feb  2 16:26:06 2013 barthelemy delemotte
** Last update Sat Feb  2 16:26:07 2013 barthelemy delemotte
*/

#include	"brain.h"
#include	"my.h"

int		brain_init(t_brain *brain, t_game *game,
			   t_cpu *cpu, t_ram *ram)
{
  brain->game = game;
  brain->cpu = cpu;
  brain->ram = ram;
  return (RET_SUCCESS);
}
