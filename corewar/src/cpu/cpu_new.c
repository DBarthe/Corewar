/*
** cpu_new.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/cpu
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:30:03 2013 raphael defreitas
** Last update Sun Mar 31 18:59:46 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"
#include	"process.h"

t_cpu		*cpu_new(void)
{
  t_cpu		*cpu;

  if ((cpu = xmalloc(sizeof(t_cpu))) == NULL)
    return (NULL);
  if ((cpu->processes = my_list_new(LIST_LINKED, &process_free)) == NULL)
    return (NULL);
  cpu_add_process(cpu, NULL);
  cpu->hook_process = NULL;
  return (cpu);
}
