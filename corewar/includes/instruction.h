/*
** instruction.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:06:02 2013 barthelemy delemotte
** Last update Sun Mar 31 11:54:07 2013 barthelemy delemotte
*/

#ifndef		INSTRUCTION_H_
# define	INSTRUCTION_H_

#include	"instruction_types.h"
#include	"ram_types.h"
#include	"process_types.h"

/*
** construtor & destructor
*/
t_instruction	*instruction_new(char *data, int data_len);
void		instruction_free(t_instruction *instruction);

/*
** mains functions
*/
t_instruction	*instruction_get_next(t_ram *ram, int pc);
int		instruction_parse_args(t_instruction *instruction);
int		instruction_load(t_instruction *instruction,
				 t_process *process, t_ram *ram);
int		instruction_read(t_instruction *instruction,
				 t_process *process, t_ram *ram);
int		instruction_write(t_instruction *instruction,
				  t_process *process, t_ram *ram);

/*
** tools
*/
char		instruction_get_arg_type(char *poc, int no);

int		instruction_get_val_dir(char *ptr, int n);
int		instruction_get_val_ind_mod(char *ptr, int n,
					    t_ram *ram, int pc);
int		instruction_get_val_ind(char *ptr, int n, t_ram *ram, int pc);
int		instruction_get_val_reg(char *ptr, int n, t_process *process);

/*
** read params of instructions
*/
int		instruction_r_live(t_instruction *instruction,
				   t_process *process, t_ram *ram);
int		instruction_w_live(t_instruction *instruction,
				   t_process *process, t_ram *ram);

int		instruction_r_load(t_instruction *instruction,
				   t_process *process, t_ram *ram);
int		instruction_w_load(t_instruction *instruction,
				    t_process *process, t_ram *ram);

int		instruction_r_loadi(t_instruction *instruction,
				    t_process *process, t_ram *ram);
int		instruction_w_loadi(t_instruction *instruction,
				    t_process *process, t_ram *ram);

int		instruction_r_store(t_instruction *instruction,
				    t_process *process, t_ram *ram);
int		instruction_w_store(t_instruction *instruction,
				    t_process *process, t_ram *ram);

int		instruction_r_storei(t_instruction *instruction,
				     t_process *process, t_ram *ram);
int		instruction_w_storei(t_instruction *instruction,
				     t_process *process, t_ram *ram);

int		instruction_r_fork(t_instruction *instruction,
				   t_process *process, t_ram *ram);
int		instruction_w_fork(t_instruction *instruction,
				   t_process *process, t_ram *ram);

int		instruction_r_zjump(t_instruction *instruction,
				    t_process *process, t_ram *ram);
int		instruction_w_zjump(t_instruction *instruction,
				    t_process *process, t_ram *ram);

int		instruction_r_add(t_instruction *instruction,
				  t_process *process, t_ram *ram);
int		instruction_w_add(t_instruction *instruction,
				  t_process *process, t_ram *ram);

int		instruction_r_sub(t_instruction *instruction,
				  t_process *process, t_ram *ram);
int		instruction_w_sub(t_instruction *instruction,
				  t_process *process, t_ram *ram);

int		instruction_r_and(t_instruction *instruction,
				  t_process *process, t_ram *ram);
int		instruction_w_and(t_instruction *instruction,
				  t_process *process, t_ram *ram);

int		instruction_r_or(t_instruction *instruction,
				 t_process *process, t_ram *ram);
int		instruction_w_or(t_instruction *instruction,
				 t_process *process, t_ram *ram);

int		instruction_r_xor(t_instruction *instruction,
				  t_process *process, t_ram *ram);
int		instruction_w_xor(t_instruction *instruction,
				  t_process *process, t_ram *ram);

int		instruction_r_aff(t_instruction *instruction,
				  t_process *process, t_ram *ram);
int		instruction_w_aff(t_instruction *instruction,
				  t_process *process, t_ram *ram);

int		instruction_r_op(t_instruction *instruction,
				 t_process *process, t_ram *ram);
int		instruction_r_op_b(t_instruction *instruction,
				   t_process *process, t_ram *ram);

int		instruction_read_args(t_instruction *instruction, t_ram *ram,
				      t_process *process,
				      int types_size[MAX_ARGS_NUMBER]);
int		instruction_read_args_mod(t_instruction *instruction,
					  t_ram *ram, t_process *process,
					  int types_size[MAX_ARGS_NUMBER]);

#endif /* !INSTRUCTION_H_ */
