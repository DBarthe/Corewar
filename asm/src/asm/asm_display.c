/*
** asm_display.c for corewar - asm in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 16:51:12 2013 barthelemy delemotte
** Last update Sun Mar 31 09:56:18 2013 damien sauvalle
*/

#include	"my.h"
#include	"asm.h"

void		asm_display(t_asm *asm_d, char *name_file)
{
  my_printf("**************\nAssembling: %s\n", name_file);
  my_printf("Name= %s\n", asm_d->name);
  my_printf("Comment= %s\n", asm_d->comment);
  my_printf("**************\n");
}
