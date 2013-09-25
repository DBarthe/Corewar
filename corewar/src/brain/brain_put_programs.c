/*
** brain_put_programs.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/brain
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Feb  4 16:46:28 2013 barthelemy delemotte
** Last update Sat Mar 30 12:08:24 2013 barthelemy delemotte
*/

#include	"brain.h"
#include	"ram.h"

int		brain_put_programs(t_brain *brain)
{
  return (ram_put_program_list(brain->ram, brain->programs));
}
