/*
** instruction.h for corewar in /home/sauval_d/corewar/asm/includes
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Fri Feb  1 13:46:28 2013 damien sauvalle
** Last update Sat Mar 30 13:16:16 2013 marie lefebvre
*/

#ifndef		INSTRUCTION_H_
# define	INSTRUCTION_H_

#include	"my.h"

typedef struct	s_code
{
  char		*str;
  int		idx;
  int		idx_line;
}		t_code;

int		coffee_write_nbr(char *, int, int, int);

/*
** new_file
*/
int		create_file(char *);

/*
** param
*/
int		param_code_calc(char **, char, char *);
int		param_oct_nb(char *, int, char);
int		unsigned_getnbr_base(char *, char *);
int		param_value(t_list *, char **, char, t_code *);
int		lab_value(t_list *, char *, t_code *, int);

/*
** instruction
*/
char		**parse_instruct(char *);
int		find_instruct_code(char **);
int		instruction(t_list *, char *, t_code *);
int		instruction_get_len(char *);
int		instruction_error(char *);

/*
** tab
*/
void		free_tab(char **);

#endif /* !INSTRUCTION_H_ */
