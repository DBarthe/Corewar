/*
** program_display.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Feb  4 18:21:20 2013 barthelemy delemotte
** Last update Wed Mar 27 16:22:27 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"
#include	"program.h"

void		program_display(t_program *program)
{
  my_printf("------------------------------------------\n");
  my_printf("File : [%s]\n", program->file);
  my_printf("Player id : [%d]\n", program->player_id);
  my_printf("Load addr : [%d]\n", program->load_addr);
  my_printf("Name : [%s]\n", program->name);
  my_printf("Data_len : [%d]\n", program->data_len);
  my_printf("Code_len : [%d]\n", program->code_len);
  my_printf("------------------------------------------\n");
}
